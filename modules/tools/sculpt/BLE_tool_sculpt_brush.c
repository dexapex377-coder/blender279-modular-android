#include "BLE_module_tools.h"
#include "BLE_core_math.h"
#include "BLE_core_memory.h"
#include <stdio.h>
#include <string.h>

typedef struct SculptToolData {
    float radius;
    float strength;
    int brush_type;
    BLE_Vec3 last_pos;
} SculptToolData;

static int sculpt_brush_init(BLE_Tool *t, BLE_ToolContext *ctx) {
    t->private_data = BLE_mem_alloc(sizeof(SculptToolData));
    SculptToolData *data = (SculptToolData*)t->private_data;
    data->radius = 50.0f;
    data->strength = 0.5f;
    data->brush_type = 0;
    data->last_pos = (BLE_Vec3){0,0,0};
    fprintf(stderr, "[SculptTool] Initialized - radius: %.1f, strength: %.2f\n", data->radius, data->strength);
    return 1;
}

static void sculpt_brush_shutdown(BLE_Tool *t) {
    BLE_mem_free(t->private_data);
    t->private_data = NULL;
}

static void sculpt_brush_activate(BLE_Tool *t, BLE_ToolContext *ctx) {
    (void)ctx;
    t->active = 1;
    fprintf(stderr, "[SculptTool] Activated - brush mode\n");
}

static void sculpt_brush_deactivate(BLE_Tool *t) {
    t->active = 0;
    fprintf(stderr, "[SculptTool] Deactivated\n");
}

static int sculpt_brush_handle_event(BLE_Tool *t, BLE_ToolContext *ctx, int event_type, void *event_data) {
    SculptToolData *data = (SculptToolData*)t->private_data;
    (void)event_data;
    
    switch (event_type) {
        case 1: // MOUSE_DOWN
            data->last_pos = ctx->mouse_pos;
            fprintf(stderr, "[SculptTool] Stroke start at %.2f, %.2f\n", 
                    ctx->mouse_pos.x, ctx->mouse_pos.y);
            break;
        case 2: // MOUSE_MOVE
            if (ctx->modifiers & 1) {
                BLE_Vec3 dir;
                BLE_math_api_get()->vec3_sub(&dir, &ctx->mouse_pos, &data->last_pos);
                float dist = BLE_math_api_get()->vec3_len(&dir);
                if (dist > 0.001f) {
                    fprintf(stderr, "[SculptTool] Stroke: dist=%.2f, radius=%.1f, strength=%.2f\n", 
                            dist, data->radius, data->strength);
                }
                data->last_pos = ctx->mouse_pos;
            }
            break;
        case 3: // MOUSE_UP
            fprintf(stderr, "[SculptTool] Stroke end\n");
            break;
        case 4: // WHEEL
            data->radius += *(float*)event_data * 5.0f;
            if (data->radius < 1.0f) data->radius = 1.0f;
            if (data->radius > 500.0f) data->radius = 500.0f;
            fprintf(stderr, "[SculptTool] Radius changed to %.1f\n", data->radius);
            break;
    }
    return 1;
}

static void sculpt_brush_draw(BLE_Tool *t, BLE_ToolContext *ctx) {
    SculptToolData *data = (SculptToolData*)t->private_data;
    (void)ctx;
    fprintf(stderr, "[SculptTool] Draw brush preview: radius=%.1f\n", data->radius);
}

static BLE_ToolVTable sculpt_brush_vtable = {
    .name = "sculpt_brush",
    .description = "Sculpt Brush Tool",
    .type = BLE_TOOL_TYPE_SCULPT,
    .init = sculpt_brush_init,
    .shutdown = sculpt_brush_shutdown,
    .activate = sculpt_brush_activate,
    .deactivate = sculpt_brush_deactivate,
    .handle_event = sculpt_brush_handle_event,
    .draw = sculpt_brush_draw,
};

BLE_Tool sculpt_brush_tool = { .vtable = &sculpt_brush_vtable, .private_data = NULL, .active = 0 };
BLE_Tool *BLE_tool_get_sculpt_brush(void) { return &sculpt_brush_tool; }