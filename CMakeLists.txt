cmake_minimum_required(VERSION 3.10)
project(BlenderModular C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

include_directories(
    core
    modules/tools
    plugins/render
)

set(CORE_SRCS
    core/BLE_module_registry.c
    core/BLE_core_memory.c
    core/BLE_core_math.c
    core/BLE_core_dna.c
)

set(TOOLS_SRCS
    modules/tools/BLE_module_tools.c
    modules/tools/mesh/BLE_tool_mesh_select.c
    modules/tools/sculpt/BLE_tool_sculpt_brush.c
    modules/tools/animation/BLE_tool_animation_timeline.c
)

set(RENDER_SRCS
    plugins/render/BLE_render_module.c
    plugins/render/engines/BLE_engine_br.c
    plugins/render/engines/BLE_engine_eevee.c
)

add_executable(blender_mod
    main.c
    ${CORE_SRCS}
    ${TOOLS_SRCS}
    ${RENDER_SRCS}
)

target_link_libraries(blender_mod m)