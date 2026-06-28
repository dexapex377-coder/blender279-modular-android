#include "BLE_module_tools.h"
#include "BLE_module_api.h"
#include "BLE_core_memory.h"
#include <string.h>
#include <stdio.h>

static int tools_init(BLE_ModuleContext *ctx) {
    fprintf(stderr, "[Tools] Module initialized\n");
    return 1;
}

static void tools_shutdown(BLE_ModuleContext *ctx) {
    BLE_ToolsModule *mod = (BLE_ToolsModule *)BLE_module_find(ctx->registry, "ble_tools");
    if (mod) {
        for (int i = 0; i < mod->num_tools; i++) {
            if (mod->tools[i]->vtable->shutdown) mod->tools[i]->vtable->shutdown(mod->tools[i]);
        }
        BLE_mem_free(mod->tools);
    }
    fprintf(stderr, "[Tools] Module shutdown\n");
}

static void tools_register_types(BLE_ModuleContext *ctx) { (void)ctx; }
static void tools_register_tools(BLE_ModuleContext *ctx) { (void)ctx; }
static void tools_register_render_engines(BLE_ModuleContext *ctx) { (void)ctx; }
static void tools_register_physics(BLE_ModuleContext *ctx) { (void)ctx; }

static BLE_ModuleVTable tools_vtable = {
    .init = tools_init,
    .shutdown = tools_shutdown,
    .register_types = tools_register_types,
    .register_tools = tools_register_tools,
    .register_render_engines = tools_register_render_engines,
    .register_physics = tools_register_physics,
};

static BLE_ModuleInfo tools_info = {
    .name = "ble_tools",
    .version = "1.0",
    .api_version = BLE_MODULE_API_VERSION,
    .type = BLE_MODULE_TYPE_TOOLS,
    .dependencies = (const char*[]){"ble_core"},
    .num_dependencies = 1,
};

static BLE_ToolsModule ble_tools_module = {0};

BLE_Module *BLE_module_get_ble_tools(void) {
    if (!ble_tools_module.base.info.name) {
        ble_tools_module.base.info = tools_info;
        ble_tools_module.base.vtable = tools_vtable;
    }
    return &ble_tools_module.base;
}

BLE_Module *BLE_tools_module_create(void) { return BLE_module_get_ble_tools(); }

int BLE_tools_register_tool(BLE_ToolsModule *mod, BLE_Tool *tool) {
    if (!mod || !tool) return 0;
    if (mod->num_tools >= mod->max_tools) {
        int new_max = mod->max_tools ? mod->max_tools * 2 : 16;
        mod->tools = BLE_mem_realloc(mod->tools, new_max * sizeof(BLE_Tool*));
        mod->max_tools = new_max;
    }
    mod->tools[mod->num_tools++] = tool;
    
    // Initialize the tool if it has an init function
    if (tool->vtable && tool->vtable->init) {
        BLE_ModuleContext *ctx = NULL; // We'll use a dummy context
        BLE_ToolContext dummy_ctx = {0};
        tool->vtable->init(tool, &dummy_ctx);
    }
    
    fprintf(stderr, "[Tools] Registered tool: %s\n", tool->vtable->name);
    return 1;
}

BLE_Tool *BLE_tools_find_tool(BLE_ToolsModule *mod, const char *name) {
    for (int i = 0; i < mod->num_tools; i++) {
        if (strcmp(mod->tools[i]->vtable->name, name) == 0) return mod->tools[i];
    }
    return NULL;
}

BLE_Tool *BLE_tools_find_by_type(BLE_ToolsModule *mod, BLE_ToolType type) {
    for (int i = 0; i < mod->num_tools; i++) {
        if (mod->tools[i]->vtable->type == type) return mod->tools[i];
    }
    return NULL;
}