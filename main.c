#include <stdio.h>
#include <stdlib.h>
#include "core/BLE_module_api.h"
#include "core/BLE_core_memory.h"
#include "core/BLE_core_math.h"
#include "modules/tools/BLE_module_tools.h"
#include "modules/mesh/BLE_module_mesh.h"
#include "plugins/render/BLE_render_api.h"

// External module declarations
extern BLE_Module *BLE_module_get_ble_core(void);
extern BLE_Module *BLE_module_get_ble_tools(void);
extern BLE_Module *BLE_module_get_ble_render(void);
extern BLE_Module *BLE_module_get_ble_mesh(void);

// External engine declarations
extern BLE_RenderEngine *BLE_render_engine_get_blender_render(void);
extern BLE_RenderEngine *BLE_render_engine_get_eevee(void);

// External tool declarations
extern BLE_Tool *BLE_tool_get_mesh_select(void);
extern BLE_Tool *BLE_tool_get_sculpt_brush(void);
extern BLE_Tool *BLE_tool_get_animation_timeline(void);

int main() {
    printf("=== BLENDER MODULAR BOOT ===\n");

    // 1. Core Initialization
    BLE_mem_init();
    BLE_math_init();
    
    BLE_ModuleRegistry *reg = BLE_module_registry_create();
    
    // 2. Register Modules
    BLE_module_register(reg, BLE_module_get_ble_core());
    BLE_module_register(reg, BLE_module_get_ble_tools());
    BLE_module_register(reg, BLE_module_get_ble_mesh());
    BLE_module_register(reg, BLE_module_get_ble_render());
    
    // 3. Initialize Modules
    BLE_ModuleContext *ctx = BLE_module_context_create(reg);
    for (int i = 0; i < reg->num_modules; i++) {
        reg->modules[i]->vtable.init(ctx);
    }
    
    // 4. Demonstrate Tools Modularity
    printf("\n--- Tool System Test ---\n");
    fflush(stdout);
    BLE_ToolsModule *tools_mod = (BLE_ToolsModule *)BLE_module_find(reg, "ble_tools");
    BLE_tools_register_tool(tools_mod, BLE_tool_get_mesh_select());
    BLE_tools_register_tool(tools_mod, BLE_tool_get_sculpt_brush());
    BLE_tools_register_tool(tools_mod, BLE_tool_get_animation_timeline());
    
    BLE_ToolContext tool_ctx = { .module_ctx = ctx, .mouse_pos = {10, 20, 0} };
    BLE_Tool *sel = BLE_tools_find_tool(tools_mod, "mesh_select");
    sel->vtable->activate(sel, &tool_ctx);
    sel->vtable->handle_event(sel, &tool_ctx, 1, NULL); // MOUSE_DOWN
    
    // 5. Demonstrate Render Engine Swapping
    printf("\n--- Render Engine Swapping Test ---\n");
    fflush(stdout);
    BLE_RenderModule *render_mod = (BLE_RenderModule *)BLE_module_find(reg, "ble_render");
    BLE_RenderContext *r_ctx = render_mod->context;
    
    BLE_render_engine_register(r_ctx, BLE_render_engine_get_blender_render());
    BLE_render_engine_register(r_ctx, BLE_render_engine_get_eevee());
    
    // Switch to Blender Render
    BLE_render_engine_set_active(r_ctx, "blender_render");
    BLE_render_scene(r_ctx, NULL, NULL);
    
    // Switch to EEVEE
    BLE_render_engine_set_active(r_ctx, "eevee");
    BLE_render_scene(r_ctx, NULL, NULL);
    
    printf("\n--- Shutdown ---\n");
    fflush(stdout);
    for (int i = reg->num_modules - 1; i >= 0; i--) {
        reg->modules[i]->vtable.shutdown(ctx);
    }
    
    BLE_module_context_destroy(ctx);
    BLE_module_registry_destroy(reg);
    BLE_mem_shutdown();
    
    printf("=== BLENDER MODULAR EXIT SUCCESS ===\n");
    fflush(stdout);
    return 0;
}