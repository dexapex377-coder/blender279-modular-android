#include "BLE_render_api.h"
#include "BLE_module_api.h"
#include "BLE_core_memory.h"
#include <string.h>
#include <stdio.h>

static int render_init(BLE_ModuleContext *ctx) {
    BLE_RenderModule *mod = (BLE_RenderModule *)BLE_module_find(ctx->registry, "ble_render");
    mod->context = BLE_render_context_create(ctx);
    fprintf(stderr, "[Render] Module initialized\n");
    return 1;
}

static void render_shutdown(BLE_ModuleContext *ctx) {
    BLE_RenderModule *mod = (BLE_RenderModule *)BLE_module_find(ctx->registry, "ble_render");
    BLE_render_context_destroy(mod->context);
    fprintf(stderr, "[Render] Module shutdown\n");
}

static void render_register_types(BLE_ModuleContext *ctx) { (void)ctx; }
static void render_register_tools(BLE_ModuleContext *ctx) { (void)ctx; }
static void render_register_render_engines(BLE_ModuleContext *ctx) { (void)ctx; }
static void render_register_physics(BLE_ModuleContext *ctx) { (void)ctx; }

static BLE_ModuleVTable render_vtable = {
    .init = render_init,
    .shutdown = render_shutdown,
    .register_types = render_register_types,
    .register_tools = render_register_tools,
    .register_render_engines = render_register_render_engines,
    .register_physics = render_register_physics,
};

static BLE_ModuleInfo render_info = {
    .name = "ble_render",
    .version = "1.0",
    .api_version = BLE_MODULE_API_VERSION,
    .type = BLE_MODULE_TYPE_RENDER,
    .dependencies = (const char*[]){"ble_core"},
    .num_dependencies = 1,
};

static BLE_RenderModule ble_render_module = {0};

BLE_Module *BLE_module_get_ble_render(void) {
    if (!ble_render_module.base.info.name) {
        ble_render_module.base.info = render_info;
        ble_render_module.base.vtable = render_vtable;
    }
    return &ble_render_module.base;
}

BLE_RenderContext *BLE_render_context_create(BLE_ModuleContext *module_ctx) {
    BLE_RenderContext *ctx = BLE_mem_alloc(sizeof(BLE_RenderContext));
    memset(ctx, 0, sizeof(BLE_RenderContext));
    ctx->module_ctx = module_ctx;
    return ctx;
}

void BLE_render_context_destroy(BLE_RenderContext *ctx) {
    if (!ctx) return;
    BLE_mem_free(ctx->engines);
    BLE_mem_free(ctx);
}

int BLE_render_engine_register(BLE_RenderContext *ctx, BLE_RenderEngine *engine) {
    if (!ctx || !engine) return 0;
    if (ctx->num_engines >= ctx->max_engines) {
        int new_max = ctx->max_engines ? ctx->max_engines * 2 : 8;
        ctx->engines = BLE_mem_realloc(ctx->engines, new_max * sizeof(BLE_RenderEngine*));
        ctx->max_engines = new_max;
    }
    ctx->engines[ctx->num_engines++] = engine;
    fprintf(stderr, "[Render] Registered engine: %s\n", engine->vtable->name);
    return 1;
}

BLE_RenderEngine *BLE_render_engine_find(BLE_RenderContext *ctx, const char *name) {
    for (int i = 0; i < ctx->num_engines; i++) {
        if (strcmp(ctx->engines[i]->vtable->name, name) == 0) return ctx->engines[i];
    }
    return NULL;
}

BLE_RenderEngine *BLE_render_engine_find_by_type(BLE_RenderContext *ctx, BLE_RenderEngineType type) {
    for (int i = 0; i < ctx->num_engines; i++) {
        if (ctx->engines[i]->vtable->type == type) return ctx->engines[i];
    }
    return NULL;
}

int BLE_render_engine_set_active(BLE_RenderContext *ctx, const char *name) {
    BLE_RenderEngine *engine = BLE_render_engine_find(ctx, name);
    if (!engine) return 0;
    if (ctx->active_engine) ctx->active_engine->is_active = 0;
    ctx->active_engine = engine;
    engine->is_active = 1;
    fprintf(stderr, "[Render] Active engine set to: %s\n", name);
    return 1;
}

int BLE_render_scene(BLE_RenderContext *ctx, BLE_RenderScene *scene, BLE_RenderResult *result) {
    if (!ctx->active_engine) return 0;
    (void)scene; (void)result;
    fprintf(stderr, "[Render] Rendering scene with %s...\n", ctx->active_engine->vtable->name);
    return ctx->active_engine->vtable->render_start(ctx->active_engine, result);
}

void BLE_render_viewport(BLE_RenderContext *ctx, void *viewport_data) {
    if (!ctx->active_engine) return;
    ctx->active_engine->vtable->draw_viewport(ctx->active_engine, viewport_data);
}