#include "BLE_module_api.h"
#include "BLE_types.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int core_init(BLE_ModuleContext *ctx) {
    fprintf(stderr, "[Core] Module initialized\n");
    return 1;
}

static void core_shutdown(BLE_ModuleContext *ctx) {
    fprintf(stderr, "[Core] Module shutdown\n");
}

static void core_register_types(BLE_ModuleContext *ctx) { (void)ctx; }
static void core_register_tools(BLE_ModuleContext *ctx) { (void)ctx; }
static void core_register_render_engines(BLE_ModuleContext *ctx) { (void)ctx; }
static void core_register_physics(BLE_ModuleContext *ctx) { (void)ctx; }

static BLE_ModuleVTable core_vtable = {
    .init = core_init,
    .shutdown = core_shutdown,
    .register_types = core_register_types,
    .register_tools = core_register_tools,
    .register_render_engines = core_register_render_engines,
    .register_physics = core_register_physics,
};

static BLE_ModuleInfo core_info = {
    .name = "ble_core",
    .version = "1.0",
    .api_version = BLE_MODULE_API_VERSION,
    .type = BLE_MODULE_TYPE_CORE,
    .dependencies = NULL,
    .num_dependencies = 0,
};

BLE_Module ble_core_module = {0};

BLE_Module *BLE_module_get_ble_core(void) {
    if (!ble_core_module.info.name) {
        ble_core_module.info = core_info;
        ble_core_module.vtable = core_vtable;
    }
    return &ble_core_module;
}