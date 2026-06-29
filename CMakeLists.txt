cmake_minimum_required(VERSION 3.22)

project(Blender279ModularAndroid LANGUAGES C CXX)

# Default to Linux build
if(NOT CMAKE_SYSTEM_NAME STREQUAL "Android")
    set(CMAKE_SYSTEM_NAME Linux)
endif()

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options
option(BLENDER_BUILD_ANDROID "Build for Android" OFF)
option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(WITH_GPU_OPENGL "Build OpenGL GPU backend" ON)
option(WITH_GPU_VULKAN "Build Vulkan GPU backend" OFF)

# Platform-specific settings
if(CMAKE_SYSTEM_NAME STREQUAL "Android")
    set(CMAKE_ANDROID_NDK ${CMAKE_ANDROID_NDK} CACHE PATH "Android NDK path")
    set(CMAKE_ANDROID_NDK_TOOLCHAIN_VERSION clang)
    
    if(NOT ANDROID_ABI)
        set(ANDROID_ABI arm64-v8a)
    endif()
    
    if(NOT ANDROID_PLATFORM)
        set(ANDROID_PLATFORM android-24)
    endif()
    
    if(NOT ANDROID_STL)
        set(ANDROID_STL c++_shared)
    endif()
    
    add_definitions(
        -D__ANDROID__
        -DANDROID
        -DWITH_GLES
        -DWITH_GLEW_ES
        -DGLEW_STATIC
        -DNO_PYTHON
        -DNO_FREESTYLE
        -DNO_CYCLES
        -DNO_AUDASPACE
        -DNO_GAMEENGINE
        -DNO_RAYOPTIMIZATION
        -DNO_MEM_VALGRIND
        -DNO_MEM_JEMALLOC
        -DWITH_THREADS
    )
    
    find_library(EGL_LIBRARY EGL)
    find_library(GLESv3_LIBRARY GLESv3)
    find_library(LOG_LIBRARY log)
    find_library(ANDROID_LIBRARY android)
    find_library(DL_LIBRARY dl)
    
    set(PLATFORM_LIBS ${EGL_LIBRARY} ${GLESv3_LIBRARY} ${LOG_LIBRARY} ${ANDROID_LIBRARY} ${DL_LIBRARY} m)
else()
    find_package(OpenGL REQUIRED)
    find_package(EGL REQUIRED)
    find_package(GLESv3 REQUIRED)
    find_package(Threads REQUIRED)
    
    set(PLATFORM_LIBS ${OPENGL_LIBRARIES} ${EGL_LIBRARIES} ${GLESv3_LIBRARIES} Threads::Threads m)
endif()

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

# GPU backend sources
set(GPU_COMMON_SRCS
    core/gpu/gpu_init_exit.c
    core/gpu/gpu_immediate_util.c
    core/gpu/gpu_select.c
    core/gpu/gpu_select_pick.c
    core/gpu/gpu_viewport.c
)

set(GPU_OPENGL_SRCS
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

# Mesh module
add_subdirectory(modules/mesh)

# Depsgraph module
add_subdirectory(modules/depsgraph)

# Anim module
add_subdirectory(modules/anim)

# Physics module
add_subdirectory(modules/physics)

# Render plugin
set(RENDER_SRCS
    plugins/render/BLE_render_module.c
    plugins/render/engines/BLE_engine_br.c
    plugins/render/engines/BLE_engine_eevee.c
)

# Android JNI
if(CMAKE_SYSTEM_NAME STREQUAL "Android")
    set(ANDROID_SRCS
        android/jni/blender_android.c
    )
else()
    set(ANDROID_SRCS)
endif()

# Include directories
include_directories(
    core
    core/gpu
    core/gpu/opengl
    modules/tools
    plugins/render
    android/jni
)

# Main library
add_library(blender279_modular SHARED
    main.c
    ${CORE_SRCS}
    ${GPU_COMMON_SRCS}
    ${GPU_OPENGL_SRCS}
    ${MODULE_SRCS}
    ${RENDER_SRCS}
    ${ANDROID_SRCS}
)

target_link_libraries(blender279_modular ${PLATFORM_LIBS})

target_compile_options(blender279_modular PRIVATE
    -Wall -Wextra -Wpedantic
    -Wno-unused-parameter
    -Wno-missing-field-initializers
)

if(CMAKE_SYSTEM_NAME STREQUAL "Android")
    target_compile_definitions(blender279_modular PRIVATE
        __ANDROID__
        ANDROID
        WITH_GLES
        WITH_GLEW_ES
        GLEW_STATIC
        NO_PYTHON
        NO_FREESTYLE
        NO_CYCLES
        NO_AUDASPACE
        NO_GAMEENGINE
    )
endif()

# Install
install(TARGETS blender279_modular
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)