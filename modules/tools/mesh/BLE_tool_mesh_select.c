#include "BLE_module_tools.h"
#include "BLE_core_math.h"
#include "BLE_core_memory.h"
#include <stdio.h>
#include <string.h>

typedef struct MeshToolData {
    BLE_Vec3 last_pos;
    int selecting;
} MeshToolData;

static int mesh_select_init(BLE_Tool *t, BLE_ToolContext *ctx) {
    t->private_data = BLE_mem_alloc(sizeof(MeshToolData));
    memset(t->private_data, 0, sizeof(MeshToolData));
    fprintf(stderr, "[MeshTool] Initialized\n");
    return 1;
}

static void mesh_select_shutdown(BLE_Tool *t) {
    BLE_mem_free(t->private_data);
    t->private_data = NULL;
}

static void mesh_select_activate(BLE_Tool *t, BLE_ToolContext *ctx) {
    (void)ctx;
    t->active = 1;
    fprintf(stderr, "[MeshTool] Activated\n");
}

static void mesh_select_deactivate(BLE_Tool *t) {
    t->active = 0;
    fprintf(stderr, "[MeshTool] Deactivated\n");
}

static int mesh_select_handle_event(BLE_Tool *t, BLE_ToolContext *ctx, int event_type, void *event_data) {
    MeshToolData *data = (MeshToolData*)t->private_data;
    (void)event_data;
    
    fprintf(stderr, "[MeshTool] handle_event called: %d, t=%p, data=%p\n", event_type, (void*)t, (void*)data);
    fflush(stderr);
    
    if (!data) {
        fprintf(stderr, "[MeshTool] ERROR: data is NULL!\n");
        fflush(stderr);
        return 1;
    }
    
    BLE_MathAPI *math = BLE_math_api_get();
    fprintf(stderr, "[MeshTool] math_api = %p\n", (void*)math);
    fflush(stderr);
    
    if (math && math->vec3_sub) {
        fprintf(stderr, "[MeshTool] vec3_sub exists\n");
        fflush(stderr);
    }
    
    fprintf(stderr, "[MeshTool] before switch\n");
    fflush(stderr);
    
    switch (event_type) {
        case 1: // MOUSE_DOWN
            fprintf(stderr, "[MeshTool] IN CASE 1\n");
            fflush(stderr);
            data->selecting = 1;
            break;
        case 2: // MOUSE_MOVE
            if (data->selecting) {
                BLE_Vec3 delta;
                math->vec3_sub(&delta, &ctx->mouse_pos, &data->last_pos);
                fprintf(stderr, "[MeshTool] Drag delta\n");
                fflush(stderr);
                data->last_pos = ctx->mouse_pos;
            }
            break;
        case 3: // MOUSE_UP
            data->selecting = 0;
            fprintf(stderr, "[MeshTool] Select end\n");
            fflush(stderr);
            break;
    }
    return 1;
}

static void mesh_select_draw(BLE_Tool *t, BLE_ToolContext *ctx) {
    (void)t; (void)ctx;
}

static BLE_ToolVTable mesh_select_vtable = {
    .name = "mesh_select",
    .description = "Mesh Selection Tool",
    .type = BLE_TOOL_TYPE_MESH,
    .init = mesh_select_init,
    .shutdown = mesh_select_shutdown,
    .activate = mesh_select_activate,
    .deactivate = mesh_select_deactivate,
    .handle_event = mesh_select_handle_event,
    .draw = mesh_select_draw,
};

BLE_Tool mesh_select_tool = { .vtable = &mesh_select_vtable, .private_data = NULL, .active = 0 };
BLE_Tool *BLE_tool_get_mesh_select(void) { return &mesh_select_tool; }