#include "BLE_module_io.h"
#include "BLE_core_memory.h"
#include <string.h>
#include <stdio.h>

static int io_init(BLE_ModuleContext *ctx) {
    fprintf(stderr, "[IO] Module initialized\n");
    return 1;
}

static void io_shutdown(BLE_ModuleContext *ctx) {
    fprintf(stderr, "[IO] Module shutdown\n");
}

static void io_register_types(BLE_ModuleContext *ctx) { (void)ctx; }
static void io_register_tools(BLE_ModuleContext *ctx) { (void)ctx; }
static void io_register_render_engines(BLE_ModuleContext *ctx) { (void)ctx; }
static void io_register_physics(BLE_ModuleContext *ctx) { (void)ctx; }

static BLE_ModuleVTable io_vtable = {
    .init = io_init,
    .shutdown = io_shutdown,
    .register_types = io_register_types,
    .register_tools = io_register_tools,
    .register_render_engines = io_register_render_engines,
    .register_physics = io_register_physics,
};

static BLE_ModuleInfo io_info = {
    .name = "ble_io",
    .version = "1.0",
    .api_version = BLE_MODULE_API_VERSION,
    .type = BLE_MODULE_TYPE_IO,
    .dependencies = (const char*[]){"ble_core", "ble_mesh"},
    .num_dependencies = 2,
};

static BLE_Module ble_io_module = {0};

BLE_Module *BLE_module_get_ble_io(void) {
    if (!ble_io_module.info.name) {
        ble_io_module.info = io_info;
        ble_io_module.vtable = io_vtable;
    }
    return &ble_io_module;
}
