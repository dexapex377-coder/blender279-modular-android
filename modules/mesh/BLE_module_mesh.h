#ifndef BLE_MODULE_MESH_H
#define BLE_MODULE_MESH_H

#include "BLE_types.h"
#include "BLE_module_api.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BLE_BMesh BLE_BMesh;
typedef struct BLE_DerivedMesh BLE_DerivedMesh;
typedef struct BLE_Mesh BLE_Mesh;
typedef struct BLE_PBVH BLE_PBVH;
typedef struct BLE_ModifierData BLE_ModifierData;
typedef struct BLE_Object BLE_Object;
typedef struct BLE_ModifierTypeInfo BLE_ModifierTypeInfo;

typedef struct BLE_MeshModule {
    BLE_Module base;
    // BMesh API
    BLE_BMesh* (*bmesh_new)(void);
    void (*bmesh_free)(BLE_BMesh* bm);
    m);
    void (*bmesh_clear)(BLE_BMesh* b m);
    
    // DerivedMesh API
    BLE_DerivedMesh* (*derived_mesh_create)(BLE_Mesh* mesh);
    void (*derived_mesh_free)(BLE_DerivedMesh* dm);
    void (*derived_mesh_eval)(BLE_DerivedMesh* dm, BLE_Object* ob);
    
    // Mesh API
    BLE_Mesh* (*mesh_new_from_object)(BLE_Object* ob);
    void (*mesh_free)(BLE_Mesh* mesh);
    
    // Modifier Stack
    void (*modifier_apply_stack)(BLE_Object* ob);
    void (*modifier_eval_stack)(BLE_Object* ob);
    
    // PBVH (sculpt)
    BLE_PBVH* (*pbvh_new_from_bmesh)(BLE_BMesh* b m);
    void (*pbvh_free)(BLE_PBVH* pbvh);
    
    // Modifier Type Registry
    BLE_ModifierTypeInfo* modifier_types;
    int num_modifier_types;
    int (*modifier_register_type)(BLE_ModifierTypeInfo* info);
    BLE_ModifierTypeInfo* (*modifier_find_type)(const char* name);
} BLE_MeshModule;

BLE_Module* BLE_mesh_module_create(void);

// BMesh API
BLE_BMesh* BLE_bmesh_new(void);
void BLE_bmesh_free(BLE_BMesh* b m);
void BLE_bmesh_clear(BLE_BMesh* b m);

// DerivedMesh API
BLE_DerivedMesh* BLE_derived_mesh_create(BLE_Mesh* mesh);
void BLE_derived_mesh_free(BLE_DerivedMesh* dm);
void BLE_derived_mesh_eval(BLE_DerivedMesh* dm, BLE_Object* ob);

// Mesh API
BLE_Mesh* BLE_mesh_new_from_object(BLE_Object* ob);
void BLE_mesh_free(BLE_Mesh* mesh);

// Modifier Stack
void BLE_modifier_apply_stack(BLE_Object* ob);
void BLE_modifier_eval_stack(BLE_Object* ob);

// Modifier Type Registry
int BLE_modifier_register_type(BLE_ModifierTypeInfo* info);
BLE_ModifierTypeInfo* BLE_modifier_find_type(const char* name);

// PBVH
BLE_PBVH* BLE_pbvh_new_from_bmesh(BLE_BMesh* b m);
void BLE_pbvh_free(BLE_PBVH* pbvh);

#ifdef __cplusplus
}
#endif

#endif