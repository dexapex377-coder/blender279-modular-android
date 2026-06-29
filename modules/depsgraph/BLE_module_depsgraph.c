#include "BLE_module_depsgraph.h"
#include "BLE_module_api.h"
#include "BLE_core_memory.h"
#include <stdio.h>

// Include 2.79 depsgraph headers
#include "../../../../blender-2.79/source/blender/depsgraph/DEG_depsgraph.h"
#include "../../../../blender-2.79/source/blender/depsgraph/DEG_depsgraph_build.h"
#include "../../../../blender-2.79/source/blender/depsgraph/DEG_depsgraph_query.h"

static int depsgraph_init(BLE_ModuleContext* ctx) {
    (void)ctx;
    fprintf(stderr, "[Depsgraph] Module initialized\n");
    return 1;
}

static void depsgraph_shutdown(BLE_ModuleContext* ctx) {
    (void)ctx;
    fprintf(stderr, "[Depsgraph] Module shutdown\n");
}

static void depsgraph_register_types(BLE_ModuleContext* ctx) {
    (void)ctx;
    fprintf(stderr, "[Depsgraph] Registering types...\n");
}

static void depsgraph_register_tools(BLE_ModuleContext* ctx) {
    (void)ctx;
}

static void depsgraph_register_render_engines(BLE_ModuleContext* ctx) {
    (void)ctx;
}

static void depsgraph_register_physics(BLE_ModuleContext* ctx) {
    (void)ctx;
}

static BLE_ModuleVTable depsgraph_vtable = {
    .init = depsgraph_init,
    .shutdown = depsgraph_shutdown,
    .register_types = depsgraph_register_types,
    .register_tools = depsgraph_register_tools,
    .register_render_engines = depsgraph_register_render_engines,
    .register_physics = depsgraph_register_physics,
};

static BLE_ModuleInfo depsgraph_info = {
    .name = "ble_depsgraph",
    .version = "1.0",
    .api_version = BLE_MODULE_API_VERSION,
    .type = BLE_MODULE_TYPE_TOOLS,
    .dependencies = (const char*[]){"ble_core", "ble_mesh"},
    .num_dependencies = 2,
};

BLE_Module ble_depsgraph_module = {
    .info = depsgraph_info,
    .vtable = depsgraph_vtable,
    .private_data = NULL,
    .is_loaded = 0,
};

BLE_Module* BLE_module_get_ble_depsgraph(void) {
    return &ble_depsgraph_module;
}

BLE_Module* BLE_depsgraph_module_create(void) {
    return BLE_module_get_ble_depsgraph();
}

// Depsgraph API wrappers
BLE_Depsgraph* BLE_depsgraph_new(BLE_Scene* scene, BLE_ViewLayer* view_layer) {
    return (BLE_Depsgraph*)DEG_depsgraph_new((struct Scene*)scene, (struct ViewLayer*)view_layer);
}

void BLE_depsgraph_free(BLE_Depsgraph* dg) {
    DEG_depsgraph_free((struct Depsgraph*)dg);
}

int BLE_depsgraph_build(BLE_Depsgraph* dg) {
    return DEG_depsgraph_build((struct Depsgraph*)dg);
}

int BLE_depsgraph_rebuild(BLE_Depsgraph* dg) {
    return DEG_depsgraph_rebuild((struct Depsgraph*)dg);
}

int BLE_depsgraph_eval(BLE_Depsgraph* dg) {
    return DEG_depsgraph_eval((struct Depsgraph*)dg);
}

int BLE_depsgraph_flush_updates(BLE_Depsgraph* dg) {
    return DEG_depsgraph_flush_updates((struct Depsgraph*)dg);
}

BLE_DepsgraphNode* BLE_depsgraph_get_node(BLE_Depsgraph* dg, BLE_Object* ob) {
    return (BLE_DepsgraphNode*)DEG_depsgraph_get_node((struct Depsgraph*)dg, (struct Object*)ob);
}

BLE_DepsgraphNode* BLE_depsgraph_get_eval_node(BLE_Depsgraph* dg, BLE_Object* ob) {
    return (BLE_DepsgraphNode*)DEG_depsgraph_get_eval_node((struct Depsgraph*)dg, (struct Object*)ob);
}

BLE_Object* BLE_depsgraph_get_eval_object(BLE_Depsgraph* dg, BLE_Object* ob) {
    return (BLE_Object*)DEG_depsgraph_get_eval_object((struct Depsgraph*)dg, (struct Object*)ob);
}

void* BLE_depsgraph_get_eval_data(BLE_Depsgraph* dg, BLE_Object* ob) {
    return DEG_depsgraph_get_eval_data((struct Depsgraph*)dg, (struct Object*)ob);
}

void BLE_depsgraph_debug_print(BLE_Depsgraph* dg) {
    DEG_depsgraph_debug_print((struct Depsgraph*)dg);
}