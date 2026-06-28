#include "mesh_adapter.h"

#include <stdlib.h>
#include <string.h>

// BMesh API
BMesh* BMESH_new(void) {
    BMesh* bm = BKE_bmesh_new();
    return bm;
}

void BMESH_free(BMesh* bm) {
    BKE_bmesh_free(bm);
}

void BMESH_clear(BMesh* bm) {
    BKE_bmesh_clear(bm);
}

// DerivedMesh API
DerivedMesh* DERIVEDMESH_create(Mesh* mesh) {
    return (DerivedMesh*)BKE_mesh_runtime_create((Mesh*)mesh);
}

void DERIVEDMESH_free(DerivedMesh* dm) {
    BKE_derivedMesh_free((struct DerivedMesh*)dm);
}

void DERIVEDMESH_eval(DerivedMesh* dm, Object* ob) {
    BKE_derivedMesh_eval((struct DerivedMesh*)dm, ob);
}

// Mesh API
Mesh* MESH_new_from_object(Object* ob) {
    return BKE_mesh_new_from_object(ob);
}

void MESH_free(Mesh* mesh) {
    BKE_mesh_free((struct Mesh*)mesh);
}

// Modifier Stack
void MODIFIER_apply_stack(Object* ob) {
    BKE_modifier_apply_stack(ob);
}

void MODIFIER_eval_stack(Object* ob) {
    BKE_modifier_eval_stack(ob);
}

int MODIFIER_register_type(ModifierTypeInfo* info) {
    return BKE_modifier_register_type(info);
}

ModifierTypeInfo* MODIFIER_find_type(const char* name) {
    for (int i = 0; i < modifierTypesNum; i++) {
        if (strcmp(modifierTypeInfo[i].name, name) == 0) {
            return (ModifierTypeInfo*)&modifierTypeInfo[i];
        }
    }
    return NULL;
}

// PBVH
PBVH* PBVH_new_from_bmesh(BMesh* bm) {
    return BKE_pbvh_from_bmesh((struct BMesh*)bm, 0.0f, 0, NULL, NULL);
}

void PBVH_free(PBVH* pbvh) {
    BKE_pbvh_free((struct PBVH*)pbvh);
}