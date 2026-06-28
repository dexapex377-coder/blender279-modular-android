cmake_minimum_required(VERSION 3.22)

# Android NDK toolchain
set(CMAKE_SYSTEM_NAME Android)
set(CMAKE_SYSTEM_VERSION 24)  # API level 24 (Android 7.0)
set(CMAKE_ANDROID_ARCH_ABI arm64-v8a)
set(CMAKE_ANDROID_NDK /opt/android/ndk)
set(CMAKE_ANDROID_STL_TYPE c++_shared)

# Toolchain file
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_ANDROID_NDK}/build/cmake/android.toolchain.cmake)

project(Blender279ModularAndroid C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Core sources
set(CORE_SRCS
    core/BLE_module_api.h
    core/BLE_module_registry.c
    core/BLE_module_core.c
    core/BLE_core_memory.c
    core/BLE_core_memory.h
    core/BLE_core_math.c
    core/BLE_core_math.h
    core/BLE_core_dna.c
    core/BLE_core_dna.h
    core/BLE_types.h
)

# GPU backend (adapted from epai's 3.6 for 2.79)
set(GPU_SRCS
    core/gpu/gpu_init_exit.c
    core/gpu/gpu_buffers.c
    core/gpu/gpu_draw.c
    core/gpu/gpu_shader.c
    core/gpu/gpu_texture.c
    core/gpu/gpu_framebuffer.c
    core/gpu/gpu_material.c
    core/gpu/gpu_immediate_util.c
    core/gpu/gpu_select.c
    core/gpu/gpu_select_pick.c
    core/gpu/gpu_viewport.c
    core/gpu/opengl/gl_backend.cc
    core/gpu/opengl/gl_batch.cc
    core/gpu/opengl/gl_context.cc
    core/gpu/opengl/gl_drawlist.cc
    core/gpu/opengl/gl_framebuffer.cc
    core/gpu/opengl/gl_immediate.cc
    core/gpu/opengl/gl_index_buffer.cc
    core/gpu/opengl/gl_shader.cc
    core/gpu/opengl/gl_shader_interface.cc
    core/gpu/opengl/gl_state.cc
    core/gpu/opengl/gl_texture.cc
    core/gpu/opengl/gl_uniform_buffer.cc
    core/gpu/opengl/gl_vertex_array.cc
    core/gpu/opengl/gl_vertex_buffer.cc
)

# Modules
set(MODULE_SRCS
    modules/tools/BLE_module_tools.c
    modules/tools/mesh/BLE_tool_mesh_select.c
    modules/tools/sculpt/BLE_tool_sculpt_brush.c
    modules/tools/animation/BLE_tool_animation_timeline.c
)

# Render plugin
set(RENDER_SRCS
    plugins/render/BLE_render_module.c
    plugins/render/engines/BLE_engine_br.c
    plugins/render/engines/BLE_engine_eevee.c
)

# Android JNI bridge
set(ANDROID_SRCS
    android/jni/blender_android.c
    android/jni/blender_jni.c
)

# Include directories
include_directories(
    core
    core/gpu
    core/gpu/opengl
    core/gpu/vulkan
    modules/tools
    plugins/render
    android/jni
    ${CMAKE_ANDROID_NDK}/sysroot/usr/include
    ${CMAKE_ANDROID_NDK}/sysroot/usr/include/EGL
    ${CMAKE_ANDROID_NDK}/sysroot/usr/include/GLES3
)

# Shared library for Android
add_library(blender279_modular SHARED
    main.c
    ${CORE_SRCS}
    ${GPU_SRCS}
    ${MODULE_SRCS}
    ${RENDER_SRCS}
    ${ANDROID_SRCS}
)

target_link_libraries(blender279_modular
    log
    android
    EGL
    GLESv3
    dl
    m
)

target_compile_definitions(blender279_modular PRIVATE
    __ANDROID__
    WITH_GLES
    WITH_GLEW_ES
    GLEW_STATIC
    NO_PYTHON
    NO_FREESTYLE
    NO_CYCLES
    NO_AUDASPACE
    NO_GAMEENGINE
    NO_RAYOPTIMIZATION
    NO_MEM_VALGRIND
    NO_MEM_JEMALLOC
)