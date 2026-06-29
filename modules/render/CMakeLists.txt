# Render Module CMakeLists.txt

# Blender Internal render
set(RENDER_INTERNAL_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/bake.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/bake_api.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/convertblender.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/envmap.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/external_engine.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/imagetexture.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/initrender.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/multires_bake.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/occlusion.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/imagetexture.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/imagetexture.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/initrender.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/multires_bake.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/occlusion.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/pipeline.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/pixelblending.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/pixelshading.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/pointdensity.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/rayshade.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/render_result.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/render_texture.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/rendercore.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/renderdatabase.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/shadbuf.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/shadeinput.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/shadeoutput.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/sss.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/strand.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/sunsky.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/texture_ocean.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/volume_precache.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/volumetric.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/voxeldata.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/zbuf.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/rayobject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/rayobject_empty.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/rayobject_instance.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/rayobject_octree.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/rayobject_qbvh.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/rayobject_raycounter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/rayobject_rtbuild.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/rayobject_svbvh.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/rayobject_vbvh.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/rayshade.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/render_result.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/render_texture.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/rendercore.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/renderdatabase.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/shadbuf.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/shadeinput.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/shadeoutput.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/sss.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/strand.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/sunsky.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/texture_ocean.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/volume_precache.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/volumetric.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/voxeldata.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/zbuf.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/bake.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/bake_api.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/convertblender.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/envmap.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/external_engine.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/imagetexture.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/initrender.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/multires_bake.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/pipeline.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/pixelblending.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/pixelshading.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/pointdensity.c
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/rayshade.c
)

# Cycles
set(CYCLES_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/cycles/kernel/kernel_*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/cycles/kernel/kernel_*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/cycles/render/render_*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/cycles/render/render_*.h
)

# Module
set(RENDER_MODULE_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/BLE_module_render.c
)

# External engine API
set(EXTERNAL_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/external/include/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/external/source/*.c
)

set(RENDER_ALL_SRCS
    ${RENDER_INTERNAL_SRCS}
    ${RENDER_MODULE_SRCS}
)

target_include_directories(blender279_modular PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/internal
    ${CMAKE_CURRENT_SOURCE_DIR}/cycles
    ${CMAKE_CURRENT_SOURCE_DIR}/cycles/kernel
    ${CMAKE_CURRENT_SOURCE_DIR}/cycles/render
    ${CMAKE_CURRENT_SOURCE_DIR}/cycles/device
    ${CMAKE_CURRENT_SOURCE_DIR}/cycles/graph
    ${CMAKE_CURRENT_SOURCE_DIR}/cycles/util
    ${CMAKE_CURRENT_SOURCE_DIR}/cycles/bvh
    ${CMAKE_CURRENT_SOURCE_DIR}/cycles/subd
    ${CMAKE_SOURCE_DIR}/core
    ${CMAKE_SOURCE_DIR}/modules/mesh
    ${CMAKE_SOURCE_DIR}/modules/depsgraph
    ${CMAKE_SOURCE_DIR}/modules/anim
    ${CMAKE_SOURCE_DIR}/modules/physics
    ${CMAKE_SOURCE_DIR}/core/gpu
)

target_sources(blender279_modular PRIVATE ${RENDER_ALL_SRCS})

# Cycles needs special handling - compile as C++
target_compile_definitions(blender279_modular PRIVATE
    WITH_RENDER
    WITH_CYCLES
    WITH_BLENDER_INTERNAL
    WITH_CXX11
)

# Set C++ standard for Cycles
set_target_properties(blender279_modular PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)