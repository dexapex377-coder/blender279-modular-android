#include "BLE_module_tools.h"
#include "BLE_core_math.h"
#include "BLE_core_memory.h"
#include <stdio.h>
#include <string.h>

typedef struct AnimationToolData {
    int current_frame;
    int playing;
    float playback_speed;
    BLE_Vec3 key_pos;
    BLE_Quat key_rot;
} AnimationToolData;

static int animation_timeline_init(BLE_Tool *t, BLE_ToolContext *ctx) {
    t->private_data = BLE_mem_alloc(sizeof(AnimationToolData));
    AnimationToolData *data = (AnimationToolData*)t->private_data;
    data->current_frame = 1;
    data->playing = 0;
    data->playback_speed = 1.0f;
    data->key_pos = (BLE_Vec3){0,0,0};
    data->key_rot = (BLE_Quat){0,0,0,1};
    fprintf(stderr, "[AnimTool] Initialized - frame: %d\n", data->current_frame);
    return 1;
}

static void animation_timeline_shutdown(BLE_Tool *t) {
    BLE_mem_free(t->private_data);
    t->private_data = NULL;
}

static void animation_timeline_activate(BLE_Tool *t, BLE_ToolContext *ctx) {
    (void)ctx;
    t->active = 1;
    fprintf(stderr, "[AnimTool] Activated - timeline mode\n");
}

static void animation_timeline_deactivate(BLE_Tool *t) {
    t->active = 0;
    fprintf(stderr, "[AnimTool] Deactivated\n");
}

static int animation_timeline_handle_event(BLE_Tool *t, BLE_ToolContext *ctx, int event_type, void *event_data) {
    AnimationToolData *data = (AnimationToolData*)t->private_data;
    (void)ctx;
    
    switch (event_type) {
        case 10: // KEYFRAME_INSERT
            data->key_pos = ctx->mouse_pos;
            fprintf(stderr, "[AnimTool] Keyframe inserted at frame %d, pos: %.2f, %.2f, %.2f\n",
                    data->current_frame, data->key_pos.x, data->key_pos.y, data->key_pos.z);
            break;
        case 11: // PLAY_PAUSE
            data->playing = !data->playing;
            fprintf(stderr, "[AnimTool] Playback: %s\n", data->playing ? "PLAY" : "PAUSE");
            break;
        case 12: // FRAME_CHANGE
            data->current_frame = *(int*)event_data;
            fprintf(stderr, "[AnimTool] Frame changed to %d\n", data->current_frame);
            break;
        case 13: // SPEED_CHANGE
            data->playback_speed = *(float*)event_data;
            fprintf(stderr, "[AnimTool] Speed: %.2fx\n", data->playback_speed);
            break;
    }
    return 1;
}

static void animation_timeline_draw(BLE_Tool *t, BLE_ToolContext *ctx) {
    AnimationToolData *data = (AnimationToolData*)t->private_data;
    (void)ctx;
    fprintf(stderr, "[AnimTool] Draw timeline: frame=%d, playing=%d, speed=%.2f\n",
            data->current_frame, data->playing, data->playback_speed);
}

static BLE_ToolVTable animation_timeline_vtable = {
    .name = "animation_timeline",
    .description = "Animation Timeline Tool",
    .type = BLE_TOOL_TYPE_ANIMATION,
    .init = animation_timeline_init,
    .shutdown = animation_timeline_shutdown,
    .activate = animation_timeline_activate,
    .deactivate = animation_timeline_deactivate,
    .handle_event = animation_timeline_handle_event,
    .draw = animation_timeline_draw,
};

BLE_Tool animation_timeline_tool = { .vtable = &animation_timeline_vtable, .private_data = NULL, .active = 0 };
BLE_Tool *BLE_tool_get_animation_timeline(void) { return &animation_timeline_tool; }