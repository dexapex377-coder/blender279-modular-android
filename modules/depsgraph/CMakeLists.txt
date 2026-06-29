# Depsgraph Module CMakeLists.txt

set(DEPSGRAPH_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/depsgraph.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/depsgraph.h
    ${CMAKE_CURRENT_SOURCE_DIR}/depsgraph_build.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/depsgraph_debug.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/depsgraph_eval.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/depsgraph_intern.h
    ${CMAKE_CURRENT_SOURCE_DIR}/depsgraph_query.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/depsgraph_tag.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/depsgraph_type_defines.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/depsgraph_types.h
)

set(DEPSGRAPH_BUILDER_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/builder/deg_builder.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/builder/deg_builder.h
    ${CMAKE_CURRENT_SOURCE_DIR}/builder/deg_builder_cycle.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/builder/deg_builder_cycle.h
    ${CMAKE_CURRENT_SOURCE_DIR}/builder/deg_builder_nodes.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/builder/deg_builder_nodes.h
    ${CMAKE_CURRENT_SOURCE_DIR}/builder/deg_builder_nodes_rig.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/builder/deg_builder_nodes_scene.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/builder/deg_builder_pchanmap.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/builder/deg_builder_pchanmap.h
    ${CMAKE_CURRENT_SOURCE_DIR}/builder/deg_builder_relations.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/builder/deg_builder_relations.h
    ${CMAKE_CURRENT_SOURCE_DIR}/builder/deg_builder_relations_keys.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/builder/deg_builder_relations_rig.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/builder/deg_builder_relations_scene.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/builder/deg_builder_transitive.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/builder/deg_builder_transitive.h
)

set(DEPSGRAPH_EVAL_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/eval/deg_eval.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/eval/deg_eval.h
    ${CMAKE_CURRENT_SOURCE_DIR}/eval/deg_eval_debug.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/eval/deg_eval_debug.h
    ${CMAKE_CURRENT_SOURCE_DIR}/eval/deg_eval_flush.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/eval/deg_eval_flush.h
)

set(DEPSGRAPH_NODES_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/nodes/deg_node.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/nodes/deg_node.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nodes/deg_node_component.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/nodes/deg_node_component.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nodes/deg_node_operation.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/nodes/deg_node_operation.h
)

set(DEPSGRAPH_DEBUG_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/debug/deg_debug_graphviz.cc
)

set(DEPSGRAPH_MODULE_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/BLE_module_depsgraph.c
)

set(DEPSGRAPH_ALL_SRCS
    ${DEPSGRAPH_SRCS}
    ${DEPSGRAPH_BUILDER_SRCS}
    ${DEPSGRAPH_EVAL_SRCS}
    ${DEPSGRAPH_NODES_SRCS}
    ${DEPSGRAPH_DEBUG_SRCS}
    ${DEPSGRAPH_MODULE_SRCS}
)

target_include_directories(blender279_modular PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/builder
    ${CMAKE_CURRENT_SOURCE_DIR}/eval
    ${CMAKE_CURRENT_SOURCE_DIR}/nodes
    ${CMAKE_SOURCE_DIR}/core
    ${CMAKE_SOURCE_DIR}/modules/mesh
)

target_sources(blender279_modular PRIVATE ${DEPSGRAPH_ALL_SRCS})

target_compile_definitions(blender279_modular PRIVATE
    WITH_DEPSGRAPH
)