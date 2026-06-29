#ifndef BLE_MODULE_ANIM_H
#define BLE_MODULE_ANIM_H

#include "BLE_types.h"
#include "BLE_module_api.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BLE_Action BLE_Action;
typedef struct BLE_FCurve BLE_FCurve;
typedef struct BLE_NLA BLE_NLA;
typedef struct BLE_Armature BLE_Armature;
typedef struct BLE_Constraint BLE_Constraint;
typedef struct BLE_Object BLE_Object;

typedef struct BLE_AnimModule {
    BLE_Module base;
    
    // Action/Animation
    BLE_Action* (*action_new)(const char* name);
    void (*action_free)(BLE_Action* act);
    BLE_FCurve* (*action_add_fcurve)(BLE_Action* act, const char* data_path, int array_index);
    
    // FCurve
    void (*fcurve_free)(BLE_FCurve* fcu);
    void (*fcurve_keyframe_add)(BLE_FCurve* fcu, float frame, float value);
    
    // NLA
    BLE_NLA* (*nla_new)(void);
    void (*nla_free)(BLE_NLA* nla);
    void (*nla_add_strip)(BLE_NLA* nla, BLE_Action* act, float start_frame);
    
    // Armature
    BLE_Armature* (*armature_new)(void);
    void (*armature_free)(BLE_Armature* arm);
    int (*armature_add_bone)(BLE_Armature* arm, const char* name, BLE_Vec3 head, BLE_Vec3 tail);
    
    // Constraints
    BLE_Constraint* (*constraint_new)(const char* type);
    void (*constraint_free)(BLE_Constraint* con);
    int (*constraint_apply)(BLE_Constraint* con, BLE_Object* ob);
} BLE_AnimModule;

BLE_Module* BLE_anim_module_create(void);
BLE_Module* BLE_module_get_ble_anim(void);

// Action/Animation
BLE_Action* BLE_action_new(const char* name);
void BLE_action_free(BLE_Action* act);
BLE_FCurve* BLE_action_add_fcurve(BLE_Action* act, const char* data_path, int array_index);

// FCurve
void BLE_fcurve_free(BLE_FCurve* fcu);
void BLE_fcurve_keyframe_add(BLE_FCurve* fcu, float frame, float value);

// NLA
BLE_NLA* BLE_nla_new(void);
void BLE_nla_free(BLE_NLA* nla);
void BLE_nla_add_strip(BLE_NLA* nla, BLE_Action* act, float start_frame);

// Armature
BLE_Armature* BLE_armature_new(void);
void BLE_armature_free(BLE_Armature* arm);
int BLE_armature_add_bone(BLE_Armature* arm, const char* name, BLE_Vec3 head, BLE_Vec3 tail);

// Constraints
BLE_Constraint* BLE_constraint_new(const char* type);
void BLE_constraint_free(BLE_Constraint* con);
int BLE_constraint_apply(BLE_Constraint* con, BLE_Object* ob);

#ifdef __cplusplus
}
#endif

#endif