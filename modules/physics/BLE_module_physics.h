#ifndef BLE_MODULE_PHYSICS_H
#define BLE_MODULE_PHYSICS_H

#include "BLE_types.h"
#include "BLE_module_api.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BLE_PointCache BLE_PointCache;
typedef struct BLE_ParticleSystem BLE_ParticleSystem;
typedef struct BLE_RigidBody BLE_RigidBody;
typedef struct BLE_SoftBody BLE_SoftBody;
typedef struct BLE_Cloth BLE_Cloth;
typedef struct BLE_Fluid BLE_Fluid;
typedef struct BLE_Smoke BLE_Smoke;

typedef struct BLE_PhysicsModule {
    BLE_Module base;
    
    // Point Cache
    BLE_PointCache* (*pointcache_new)(void);
    void (*pointcache_free)(BLE_PointCache* pc);
    int (*pointcache_bake)(BLE_PointCache* pc, float start, float end, int step);
    
    // Particle System
    BLE_ParticleSystem* (*particle_system_new)(void);
    void (*particle_system_free)(BLE_ParticleSystem* ps);
    int (*particle_system_step)(BLE_ParticleSystem* ps, float dt);
    
    // Rigid Body (Bullet)
    BLE_RigidBody* (*rigidbody_new)(void);
    void (*rigidbody_free)(BLE_RigidBody* rb);
    int (*rigidbody_add_shape)(BLE_RigidBody* rb, const float* verts, int num_verts);
    
    // Soft Body
    BLE_SoftBody* (*softbody_new)(void);
    void (*softbody_free)(BLE_SoftBody* sb);
    
    // Cloth
    BLE_Cloth* (*cloth_new)(void);
    void (*cloth_free)(BLE_Cloth* cl);
    
    // Fluid (Elbeem)
    BLE_Fluid* (*fluid_new)(void);
    void (*fluid_free)(BLE_Fluid* fl);
    
    // Smoke
    BLE_Smoke* (*smoke_new)(void);
    void (*smoke_free)(BLE_Smoke* sm);
} BLE_PhysicsModule;

BLE_Module* BLE_physics_module_create(void);
BLE_Module* BLE_module_get_ble_physics(void);

// Point Cache
BLE_PointCache* BLE_pointcache_new(void);
void BLE_pointcache_free(BLE_PointCache* pc);
int BLE_pointcache_bake(BLE_PointCache* pc, float start, float end, int step);

// Particle System
BLE_ParticleSystem* BLE_particle_system_new(void);
void BLE_particle_system_free(BLE_ParticleSystem* ps);
int BLE_particle_system_step(BLE_ParticleSystem* ps, float dt);

// Rigid Body
BLE_RigidBody* BLE_rigidbody_new(void);
void BLE_rigidbody_free(BLE_RigidBody* rb);
int BLE_rigidbody_add_shape(BLE_RigidBody* rb, const float* verts, int num_verts);

// Soft Body
BLE_SoftBody* BLE_softbody_new(void);
void BLE_softbody_free(BLE_SoftBody* sb);

// Cloth
BLE_Cloth* BLE_cloth_new(void);
void BLE_cloth_free(BLE_Cloth* cl);

// Fluid
BLE_Fluid* BLE_fluid_new(void);
void BLE_fluid_free(BLE_Fluid* fl);

// Smoke
BLE_Smoke* BLE_smoke_new(void);
void BLE_smoke_free(BLE_Smoke* sm);

#ifdef __cplusplus
}
#endif

#endif