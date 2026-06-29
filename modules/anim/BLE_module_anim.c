#include "BLE_module_anim.h"
#include "BLE_module_api.h"
#include "BLE_core_memory.h"
#include <stdio.h>

// Include 2.79 headers
#include "../../../../blender-2.79/source/blender/blenkernel/BKE_anim.h"
#include "../../../../blender-2.79/source/blender/blenkernel/BKE_animsys.h"
#include "../../../../blender-2.79/source/blender/blenkernel/BKE_armature.h"
#include "../../../../blender-2.79/source/blender/blenkernel/BKE_constraint.h"
#include "../../../../blender-2.79/source/blender/blenkernel/BKE_fcurve.h"
#include "../../../../blender-2.79/source/blender/blenkernel/BKE_nla.h"

static int anim_init(BLE_ModuleContext* ctx) {
    (void)ctx;
    fprintf(stderr, "[Anim] Module initialized\n");
    return 1;
}

static void anim_shutdown(BLE_ModuleContext* ctx) {
    (void)ctx;
    fprintf(stderr, "[Anim] Module shutdown\n");
}

static void anim_register_types(BLE_ModuleContext* ctx) {
    (void)ctx;
    fprintf(stderr, "[Anim] Registering types...\n");
}

static void anim_register_tools(BLE_ModuleContext* ctx) {
    (void)ctx;
    fprintf(stderr, "[Anim] Registering animation tools...\n");
}

static void anim_register_render_engines(BLE_ModuleContext* ctx) {
    (void)ctx;
}

static void anim_register_physics(BLE_ModuleContext* ctx) {
    (void)ctx;
}

static BLE_ModuleVTable anim_vtable = {
    .init = anim_init,
    .shutdown = anim_shutdown,
    .register_types = anim_register_types,
    .register_tools = anim_register_tools,
    .register_render_engines = anim_register_render_engines,
    .register_physics = anim_register_physics,
};

static BLE_ModuleInfo anim_info = {
    .name = "ble_anim",
    .version = "1.0",
    .api_version = BLE_MODULE_API_VERSION,
    .type = BLE_MODULE_TYPE_TOOLS,
    .dependencies = (const char*[]){"ble_core", "ble_mesh", "ble_depsgraph"},
    .num_dependencies = 3,
};

BLE_Module ble_anim_module = {
    .info = anim_info,
    .vtable = anim_vtable,
    .private_data = NULL,
    .is_loaded = 0,
};

BLE_Module* BLE_module_get_ble_anim(void) {
    return &ble_anim_module;
}

BLE_Module* BLE_anim_module_create(void) {
    return BLE_module_get_ble_anim();
}

// Action/Animation
BLE_Action* BLE_action_new(const char* name) {
    return (BLE_Action*)BKE_action_new(name);
}

void BLE_action_free(BLE_Action* act) {
    BKE_action_free((struct bAction*)act);
}

BLE_FCurve* BLE_action_add_fcurve(BLE_Action* act, const char* data_path, int array_index) {
    return (BLE_FCurve*)BKE_action_add_fcurve((struct bAction*)act, data_path, array_index);
}

// FCurve
void BLE_fcurve_free(BLE_FCurve* fcu) {
    BKE_fcurve_free((struct FCurve*)fcu);
}

void BLE_fcurve_keyframe_add(BLE_FCurve* fcu, float frame, float value) {
    BKE_fcurve_keyframe_add((struct FCurve*)fcu, frame, value);
}

// NLA
BLE_NLA* BLE_nla_new(void) {
    return (BLE_NLA*)BKE_nla_new();
}

void BLE_nla_free(BLE_NLA* nla) {
    BKE_nla_free((struct Nla*)nla);
}

void BLE_nla_add_strip(BLE_NLA* nla, BLE_Action* act, float start_frame) {
    BKE_nla_add_strip((struct Nla*)nla, (struct bAction*)act, start_frame);
}

// Armature
BLE_Armature* BLE_armature_new(void) {
    return (BLE_Armature*)BKE_armature_new();
}

void BLE_armature_free(BLE_Armature* arm) {
    BKE_armature_free((struct Armature*)arm);
}

int BLE_armature_add_bone(BLE_Armature* arm, const char* name, BLE_Vec3 head, BLE_Vec3 tail) {
    return BKE_armature_add_bone((struct Armature*)arm, name, (float*)&head, (float*)&tail);
}

// Constraints
BLE_Constraint* BLE_constraint_new(const char* type) {
    return (BLE_Constraint*)BKE_constraint_new(type);
}

void BLE_constraint_free(BLE_Constraint* con) {
    BKE_constraint_free((struct Constraint*)con);
}

int BLE_constraint_apply(BLE_Constraint* con, BLE_Object* ob) {
    return BKE_constraint_apply((struct Constraint*)con, (struct Object*)ob);
}