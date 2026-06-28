# Mesh Module CMakeLists.txt

# BMesh sources
set(BMESH_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_core.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_construct.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_delete.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_edgeloop.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_interp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_iterators.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_log.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_marking.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_mesh.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_mesh_conv.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_mesh_validate.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_mods.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_opdefines.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_operators.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_polygon.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_polygon_edgenet.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_queries.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_structure.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_walkers.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_walkers_impl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_bevel.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_bisect_plane.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_edgenet.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_edgesplit.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_intersect.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_path.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_path_region.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_separate.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_triangulate.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_wireframe.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_region_match.c
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh/bmesh_callback_generic.c
)

# Modifier sources
set(MODIFIER_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_build.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_armature.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_array.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_bevel.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_boolean.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_boolean_util.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_cast.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_cloth.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_collision.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_correctivesmooth.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_curve.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_datatransfer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_decimate.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_displace.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_dynamicpaint.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_edgesplit.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_explode.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_fluidsim.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_fluidsim_util.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_hook.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_laplaciandeform.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_laplaciansmooth.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_lattice.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_mask.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_meshcache.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_meshcache_mdd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_meshcache_pc2.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_meshcache_util.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_meshdeform.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_meshsequencecache.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_mirror.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_multires.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_none.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_normal_edit.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_ocean.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_particleinstance.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_particlesystem.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_remesh.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_screw.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_shapekey.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_shrinkwrap.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_simpledeform.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_skin.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_smoke.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_smooth.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_softbody.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_solidify.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_subsurf.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_surface.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_surfacedeform.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_triangulate.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_uvproject.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_uvwarp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_warp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_wave.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_weightvg_util.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_weightvgedit.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_weightvgmix.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_weightvgproximity.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_wireframe.c
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers/MOD_util.c
)

# DerivedMesh / Mesh evaluation sources
set(DERIVEDMESH_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/derivedmesh/DerivedMesh.c
    ${CMAKE_CURRENT_SOURCE_DIR}/derivedmesh/cdderivedmesh.c
    ${CMAKE_CURRENT_SOURCE_DIR}/derivedmesh/editderivedmesh.c
    ${CMAKE_CURRENT_SOURCE_DIR}/derivedmesh/mesh.c
    ${CMAKE_CURRENT_SOURCE_DIR}/derivedmesh/mesh_evaluate.c
    ${CMAKE_CURRENT_SOURCE_DIR}/derivedmesh/mesh_remap.c
    ${CMAKE_CURRENT_SOURCE_DIR}/derivedmesh/mesh_validate.c
    ${CMAKE_CURRENT_SOURCE_DIR}/derivedmesh/modifiers_bmesh.c
    ${CMAKE_CURRENT_SOURCE_DIR}/derivedmesh/editmesh.c
    ${CMAKE_CURRENT_SOURCE_DIR}/derivedmesh/editmesh_bvh.c
    ${CMAKE_CURRENT_SOURCE_DIR}/derivedmesh/mesh_mapping.c
    ${CMAKE_CURRENT_SOURCE_DIR}/derivedmesh/mesh_remap.c
    ${CMAKE_CURRENT_SOURCE_DIR}/derivedmesh/pbvh_bmesh.c
)

# Module registration
set(MESH_MODULE_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/BLE_module_mesh.c
    ${CMAKE_CURRENT_SOURCE_DIR}/mesh_adapter.c
)

# All mesh module sources
set(MESH_ALL_SRCS
    ${BMESH_SRCS}
    ${MODIFIER_SRCS}
    ${DERIVEDMESH_SRCS}
    ${MESH_MODULE_SRCS}
)

# Include directories
target_include_directories(blender279_modular PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/bmesh
    ${CMAKE_CURRENT_SOURCE_DIR}/modifiers
    ${CMAKE_CURRENT_SOURCE_DIR}/derivedmesh
    ${CMAKE_SOURCE_DIR}/core
    ${CMAKE_SOURCE_DIR}/core/gpu
)

# Add to main library
target_sources(blender279_modular PRIVATE ${MESH_ALL_SRCS})

# Compile definitions for mesh module
target_compile_definitions(blender279_modular PRIVATE
    WITH_BMESH
    WITH_MODIFIERS
)