# Tools Module CMakeLists.txt

set(TOOLS_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/BLE_module_tools.c
    ${CMAKE_CURRENT_SOURCE_DIR}/mesh/BLE_tool_mesh_select.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sculpt/BLE_tool_sculpt_brush.c
    ${CMAKE_CURRENT_SOURCE_DIR}/animation/BLE_tool_animation_timeline.c
)

target_include_directories(blender279_modular PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/core
)

target_sources(blender279_modular PRIVATE ${TOOLS_SRCS})
