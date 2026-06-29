# Physics Module CMakeLists.txt

# Core physics simulation
set(PHYSICS_CORE_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/cloth.c
    ${CMAKE_CURRENT_SOURCE_DIR}/fluidsim.c
    ${CMAKE_CURRENT_SOURCE_DIR}/particle.c
    ${CMAKE_CURRENT_SOURCE_DIR}/particle_child.c
    ${CMAKE_CURRENT_SOURCE_DIR}/particle_distribute.c
    ${CMAKE_CURRENT_SOURCE_DIR}/particle_system.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pointcache.c
    ${CMAKE_CURRENT_SOURCE_DIR}/rigidbody.c
    ${CMAKE_CURRENT_SOURCE_DIR}/smoke.c
    ${CMAKE_CURRENT_SOURCE_DIR}/softbody.c
)

# Physics intern (mass spring, hair, implicit)
set(PHYSICS_INTERN_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/BPH_mass_spring.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/hair_volume.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/implicit_blender.c
    ${CMAKE_CURRENT_SOURCE_DIR}/implicit_eigen.cpp
)

# Bullet (Rigid Body)
set(BULLET_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/bullet/rb_bullet_api.cpp
    # Bullet source is in extern/bullet2 - we'll include it
)

# Elbeem (Fluid)
set(ELBEEM_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/elbeem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/attributes.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/controlparticles.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/isosurface.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/mvmcoords.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_blenderdumper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_bsptree.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_geometryclass.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_geometrymodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_geometryobject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_lighting.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_matrices.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_ray.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_geometryobject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/parametrizer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/particletracer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/simulation_object.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/solver_adap.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/solver_control.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/solver_init.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/solver_interface.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/solver_main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/solver_relax.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/solver_util.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/utilities.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_blenderdumper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_bsptree.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_geometryclass.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_geometrymodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_geometryobject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_lighting.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_matrices.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_ray.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_vector3dim.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/ntl_world.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/controlparticles.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/parametrizer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/particletracer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/solver_adap.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/solver_control.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/solver_init.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/solver_interface.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/solver_main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/solver_relax.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/solver_util.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem/utilities.cpp
)

# Physics module wrapper
set(PHYSICS_MODULE_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/BLE_module_physics.c
)

# Combine all
set(PHYSICS_ALL_SRCS
    ${PHYSICS_CORE_SRCS}
    ${PHYSICS_INTERN_SRCS}
    ${PHYSICS_MODULE_SRCS}
)

target_include_directories(blender279_modular PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/bullet
    ${CMAKE_CURRENT_SOURCE_DIR}/elbeem
    ${CMAKE_SOURCE_DIR}/core
    ${CMAKE_SOURCE_DIR}/modules/mesh
    ${CMAKE_SOURCE_DIR}/modules/depsgraph
    ${CMAKE_SOURCE_DIR}/modules/anim
    ${CMAKE_SOURCE_DIR}/extern/bullet2/src
    ${CMAKE_SOURCE_DIR}/extern/bullet2/src/BulletCollision
    ${CMAKE_SOURCE_DIR}/extern/bullet2/src/BulletDynamics
    ${CMAKE_SOURCE_DIR}/extern/bullet2/src/LinearMath
)

target_sources(blender279_modular PRIVATE ${PHYSICS_ALL_SRCS})

target_compile_definitions(blender279_modular PRIVATE
    WITH_PHYSICS
    WITH_BULLET
    WITH_ELBEEM
    WITH_CLOTH
    WITH_SOFTBODY
    WITH_SMOKE
    WITH_PARTICLES
)