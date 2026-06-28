#ifndef BLE_MESH_ADAPTER_H
#define BLE_MESH_ADAPTER_H

#include "BLE_module_mesh.h"

// Include 2.79 headers
#include "../../../blender-2.79/source/blender/bmesh/bmesh.h"
#include "../../../blender-2.79/source/blender/bmesh/bmesh_class.h"
#include "../../../blender-2.79/source/blender/blenkernel/BKE_derivedmesh.h"
#include "../../../blender-2.79/source/blender/blenkernel/BKE_mesh.h"
#include "../../../blender-2.79/source/blender/blenkernel/BKE_pbvh.h"
#include "../../../blender-2.79/source/blender/blenkernel/BKE_modifier.h"
#include "../../../blender-2.79/source/blender/blenkernel/BKE_object.h"
#include "../../../blender-2.79/source/blender/blenkernel/BKE_main.h"
#include "../../../blender-2.79/source/blender/makesdna/DNA_mesh_types.h"
#include "../../../blender-2.79/source/blender/makesdna/DNA_modifier_types.h"
#include "../../../blender-2.79/source/blender/makesdna/DNA_object_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Type mapping
#define BLE_BMesh BMesh
#define BLE_DerivedMesh DerivedMesh
#define BLE_Mesh Mesh
#define BLE_PBVH PBVH
#define BLE_ModifierData ModifierData
#define BLE_Object Object
#define BLE_ModifierTypeInfo ModifierTypeInfo

// Function declarations
BMesh* BMESH_new(void);
void BMESH_free(BMesh* bm);
void BMESH_clear(BMesh* bm);

DerivedMesh* DERIVEDMESH_create(Mesh* mesh);
void DERIVEDMESH_free(DerivedMesh* dm);
void DERIVEDMESH_eval(DerivedMesh* dm, Object* ob);

Mesh* MESH_new_from_object(Object* ob);
void MESH_free(Mesh* mesh);

void MODIFIER_apply_stack(Object* ob);
void MODIFIER_eval_stack(Object* ob);
int MODIFIER_register_type(ModifierTypeInfo* info);
ModifierTypeInfo* MODIFIER_find_type(const char* name);

PBVH* PBVH_new_from_bmesh(BMesh* bm);
void PBVH_free(PBVH* pbvh);

#ifdef __cplusplus
}
#endif

#endif