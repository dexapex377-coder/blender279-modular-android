#include <jni.h>
#include <android/log.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#include "BLE_module_api.h"
#include "BLE_core_memory.h"
#include "BLE_module_core.c"

#define LOG_TAG "Blender279Modular"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

typedef struct {
    ANativeWindow* window;
    EGLDisplay display;
    EGLSurface surface;
    EGLContext context;
    int width;
    int height;
    BLE_ModuleRegistry* registry;
    BLE_ModuleContext* ctx;
    pthread_t render_thread;
    volatile int running;
} BlenderAndroidContext;

static BlenderAndroidContext g_ctx = {0};

static int init_eglInitialize(BlenderAndroidContext* ctx) {
    ctx->display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    EGLint major, minor;
    eglInitialize(ctx->display, &major, &minor);
    
    const EGLint config_attribs[] = {
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_DEPTH_SIZE, 24,
        EGL_STENCIL_SIZE, 8,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
        EGL_NONE
    };
    EGLConfig config;
    EGLint num_configs;
    eglChooseConfig(ctx->display, config_attribs, &config, 1, &num_configs);
    
    const EGLint ctx_attribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 3,
        EGL_NONE
    };
    ctx->context = eglCreateContext(ctx->display, config, EGL_NO_CONTEXT, ctx_attribs);
    
    return 1;
}

static void createSurface(BlenderAndroidContext* ctx) {
    if (ctx->surface != EGL_NO_SURFACE) {
        eglDestroySurface(ctx->display, ctx->surface);
    }
    ctx->surface = eglCreateWindowSurface(ctx->display, ctx->config, ctx->window, NULL);
    eglMakeCurrent(ctx->display, ctx->surface, ctx->surface, ctx->context);
}

static void* renderLoop(void* arg) {
    BlenderAndroidContext* ctx = (BlenderAndroidContext*)arg;
    
    while (ctx->running) {
        if (ctx->window) {
            eglMakeCurrent(ctx->display, ctx->surface, ctx->surface, ctx->context);
            
            // Blender render frame
            // TODO: call into modular render engine
            glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            
            eglSwapBuffers(ctx->display, ctx->surface);
        }
        usleep(16666); // ~60fps
    }
    return NULL;
}

JNIEXPORT jboolean JNICALL
Java_com_blender279modular_BlenderNative_init(JNIEnv* env, jobject obj, jstring homePath) {
    const char* home = (*env)->GetStringUTFChars(env, homePath, NULL);
    
    // Set Blender paths
    setenv("HOME", home, 1);
    setenv("BLENDER_USER_CONFIG", home, 1);
    setenv("BLENDER_USER_SCRIPTS", home, 1);
    
    (*env)->ReleaseStringUTFChars(env, homePath, home);
    
    // Initialize modular core
    BLE_mem_init();
    
    g_ctx.registry = BLE_module_registry_create();
    BLE_module_register(g_ctx.registry, BLE_module_get_ble_core());
    BLE_module_register(g_ctx.registry, BLE_module_get_ble_tools());
    BLE_module_register(g_ctx.registry, BLE_module_get_ble_render());
    
    g_ctx.ctx = BLE_module_context_create(g_ctx.registry);
    for (int i = 0; i < g_ctx.registry->num_modules; i++) {
        g_ctx.registry->modules[i]->vtable.init(g_ctx.ctx);
    }
    
    g_ctx.running = 1;
    pthread_create(&g_ctx.render_thread, NULL, renderLoop, &g_ctx);
    
    LOGI("Blender 2.79 Modular initialized");
    return JNI_TRUE;
}

JNIEXPORT void JNICALL
Java_com_blender279modular_BlenderNative_setSurface(JNIEnv* env, jobject obj, jobject surface) {
    if (g_ctx.window) {
        ANativeWindow_release(g_ctx.window);
    }
    g_ctx.window = ANativeWindow_fromSurface(env, surface);
    
    if (!g_ctx.display) {
        eglInitialize(g_ctx);
    }
    createSurface(&g_ctx);
    
    LOGI("Surface set: %dx%d", ANativeWindow_getWidth(g_ctx.window), ANativeWindow_getHeight(g_ctx.window));
}

JNIEXPORT void JNICALL
Java_com_blender279modular_BlenderNative_onTouch(JNIEnv* env, jobject obj, jint action, jfloat x, jfloat y, jint pointerId) {
    BLE_ToolsModule* tools = (BLE_ToolsModule*)BLE_module_find(g_ctx.registry, "ble_tools");
    if (!tools) return;
    
    BLE_Tool* tool = BLE_tools_find_by_type(tools, BLE_TOOL_TYPE_MESH);
    if (!tool) return;
    
    BLE_ToolContext tool_ctx = {0};
    tool_ctx.module_ctx = g_ctx.ctx;
    tool_ctx.mouse_pos = (BLE_Vec3){x, y, 0};
    
    int event_type = 0;
    switch (action) {
        case 0: event_type = 1; break; // DOWN
        case 2: event_type = 2; break; // MOVE
        case 1: event_type = 3; break; // UP
    }
    
    if (tool->vtable && tool->vtable->handle_event) {
        tool->vtable->handle_event(tool, &tool_ctx, event_type, NULL);
    }
}

JNIEXPORT void JNICALL
Java_com_blender279modular_BlenderNative_shutdown(JNIEnv* env, jobject obj) {
    g_ctx.running = 0;
    pthread_join(g_ctx.render_thread, NULL);
    
    for (int i = g_ctx.registry->num_modules - 1; i >= 0; i--) {
        g_ctx.registry->modules[i]->vtable.shutdown(g_ctx.ctx);
    }
    
    BLE_module_context_destroy(g_ctx.ctx);
    BLE_module_registry_destroy(g_ctx.registry);
    BLE_mem_shutdown();
    
    if (g_ctx.surface != EGL_NO_SURFACE) {
        eglDestroySurface(g_ctx.display, g_ctx.surface);
    }
    if (g_ctx.context != EGL_NO_CONTEXT) {
        eglDestroyContext(g_ctx.display, g_ctx.context);
    }
    eglTerminate(g_ctx.display);
    
    if (g_ctx.window) {
        ANativeWindow_release(g_ctx.window);
    }
    
    LOGI("Blender 2.79 Modular shutdown");
}