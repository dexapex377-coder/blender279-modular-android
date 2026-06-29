# Anim Module CMakeLists.txt

set(ANIM_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/anim.c
    ${CMAKE_CURRENT_SOURCE_DIR}/anim_sys.c
    ${CMAKE_CURRENT_SOURCE_DIR}/armature.c
    ${CMAKE_CURRENT_SOURCE_DIR}/armature_update.c
    ${CMAKE_CURRENT_SOURCE_DIR}/constraint.c
    ${CMAKE_CURRENT_SOURCE_DIR}/fcurve.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nla.c
)

set(ANIM_MODULE_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/BLE_module_anim.c
)

set(ANIM_ALL_SRCS
    ${ANIM_SRCS}
    ${ANIM_MODULE_SRCS}
)

target_include_directories(blender279_modular PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/core
    ${CMAKE_SOURCE_DIR}/modules/mesh
    ${CMAKE_SOURCE_DIR}/modules/depsgraph
)

target_sources(blender279_modular PRIVATE ${ANIM_ALL_SRCS})

target_compile_definitions(blender279_modular PRIVATE
    WITH_ANIM
    WITH_FCURVE
    WITH_NLA
    WITH_ARMATURE
    WITH_CONSTRAINT
)