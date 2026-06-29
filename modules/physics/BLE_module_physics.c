#include "BLE_module_physics.h"
#include "BLE_module_api.h"
#include "BLE_core_memory.h"
#include <stdio.h>

// Include 2.79 physics headers
#include "../../../../blender-2.79/source/blender/blenkernel/BKE_cloth.h"
#include "../../../../blender-2.79/source/blender/blenkernel/BKE_fluidsim.h"
#include "../../../../blender-2.79/source/blender/blenkernel/BKE_particle.h"
#include "../../../../blender-2.79/source/blender/blenkernel/BKE_pointcache.h"
#include "../../../../blender-2.79/source/blender/blenkernel/BKE_rigidbody.h"
#include "../../../../blender-2.79/source/blender/blenkernel/BKE_smoke.h"
#include "../../../../blender-2.79/source/blender/blenkernel/BKE_softbody.h"
#include "../../../../blender-2.79/source/blender/blenkernel/BKE_bullet.h"

static int physics_init(BLE_ModuleContext* ctx) {
    (void)ctx;
    fprintf(stderr, "[Physics] Module initialized\n");
    return 1;
}

static void physics_shutdown(BLE_ModuleContext* ctx) {
    (void)ctx;
    fprintf(stderr, "[Physics] Module shutdown\n");
}

static void physics_register_types(BLE_ModuleContext* ctx) {
    (void)ctx;
    fprintf(stderr, "[Physics] Registering types...\n");
}

static void physics_register_tools(BLE_ModuleContext* ctx) {
    (void)ctx;
    fprintf(stderr, "[Physics] Registering tools...\n");
}

static void physics_register_render_engines(BLE_ModuleContext* ctx) {
    (void)ctx;
}

static void physics_register_physics(BLE_ModuleContext* ctx) {
    (void)ctx;
    fprintf(stderr, "[Physics] Registering physics systems...\n");
}

static BLE_ModuleVTable physics_vtable = {
    .init = physics_init,
    .shutdown = physics_shutdown,
    .register_types = physics_register_types,
    .register_tools = physics_register_tools,
    .register_render_engines = physics_register_render_engines,
    .register_physics = physics_register_physics,
};

static BLE_ModuleInfo physics_info = {
    .name = "ble_physics",
    .version = "1.0",
    .api_version = BLE_MODULE_API_VERSION,
    .type = BLE_MODULE_TYPE_PHYSICS,
    .dependencies = (const char*[]){"ble_core", "ble_mesh", "ble_depsgraph", "ble_anim"},
    .num_dependencies = 4,
};

BLE_Module ble_physics_module = {
    .info = physics_info,
    .vtable = physics_vtable,
    .private_data = NULL,
    .is_loaded = 0,
};

BLE_Module* BLE_module_get_ble_physics(void) {
    return &ble_physics_module;
}

BLE_Module* BLE_physics_module_create(void) {
    return BLE_module_get_ble_physics();
}

// Point Cache
BLE_PointCache* BLE_pointcache_new(void) {
    return (BLE_PointCache*)BKE_pointcache_new();
}

void BLE_pointcache_free(BLE_PointCache* pc) {
    BKE_pointcache_free((PointCache*)pc);
}

int BLE_pointcache_bake(BLE_PointCache* pc, float start, float end, int step) {
    return BKE_pointcache_bake((PointCache*)pc, start, end, step);
}

// Particle System
BLE_ParticleSystem* BLE_particle_system_new(void) {
    return (BLE_ParticleSystem*)BKE_particlesystem_new();
}

void BLE_particle_system_free(BLE_ParticleSystem* ps) {
    BKE_particlesystem_free((ParticleSystem*)ps);
}

int BLE_particle_system_step(BLE_ParticleSystem* ps, float dt) {
    return BKE_particlesystem_step((ParticleSystem*)ps, dt);
}

// Rigid Body
BLE_RigidBody* BLE_rigidbody_new(void) {
    return (BLE_RigidBody*)BKE_rigidbody_new();
}

void BLE_rigidbody_free(BLE_RigidBody* rb) {
    BKE_rigidbody_free((RigidBody*)rb);
}

int BLE_rigidbody_add_shape(BLE_RigidBody* rb, const float* verts, int num_verts) {
    return BKE_rigidbody_add_shape((RigidBody*)rb, verts, num_verts);
}

// Soft Body
BLE_SoftBody* BLE_softbody_new(void) {
    return (BLE_SoftBody*)BKE_softbody_new();
}

void BLE_softbody_free(BLE_SoftBody* sb) {
    BKE_softbody_free((SoftBody*)sb);
}

// Cloth
BLE_Cloth* BLE_cloth_new(void) {
    return (BLE_Cloth*)BKE_cloth_new();
}

void BLE_cloth_free(BLE_Cloth* cl) {
    BKE_cloth_free((Cloth*)cl);
}

// Fluid
BLE_Fluid* BLE_fluid_new(void) {
    return (BLE_Fluid*)BKE_fluidsim_new();
}

void BLE_fluid_free(BLE_Fluid* fl) {
    BKE_fluidsim_free((FluidSim*)fl);
}

// Smoke
BLE_Smoke* BLE_smoke_new(void) {
    return (BLE_Smoke*)BKE_smoke_new();
}

void BLE_smoke_free(BLE_Smoke* sm) {
    BKE_smoke_free((Smoke*)sm);
}