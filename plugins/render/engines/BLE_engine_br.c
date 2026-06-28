#include "BLE_render_api.h"
#include <stdio.h>

static int br_init(BLE_RenderEngine *e, BLE_RenderContext *c) { (void)c; fprintf(stderr, "[BlenderRender] Init\n"); return 1; }
static void br_shutdown(BLE_RenderEngine *e) { fprintf(stderr, "[BlenderRender] Shutdown\n"); }
static int br_scene_sync(BLE_RenderEngine *e, BLE_RenderScene *s) { (void)e; (void)s; return 1; }
static int br_view_sync(BLE_RenderEngine *e, BLE_RenderViewLayer *vl) { (void)e; (void)vl; return 1; }
static int br_start(BLE_RenderEngine *e, BLE_RenderResult *r) { fprintf(stderr, "[BlenderRender] Rendering... (SLOW)\n"); (void)e; (void)r; return 1; }
static int br_tile(BLE_RenderEngine *e, int x, int y, int w, int h, BLE_RenderResult *r) { (void)e; (void)x; (void)y; (void)w; (void)h; (void)r; return 1; }
static void br_cancel(BLE_RenderEngine *e) { (void)e; }
static void br_end(BLE_RenderEngine *e, BLE_RenderResult *r) { (void)e; (void)r; }
static void br_draw(BLE_RenderEngine *e, void *vp) { fprintf(stderr, "[BlenderRender] Drawing Viewport\n"); (void)e; (void)vp; }
static void br_update(BLE_RenderEngine *e, void *vp) { (void)e; (void)vp; }
static void br_ui(BLE_RenderEngine *e, void *ui) { (void)e; (void)ui; }
static void br_gpu_init(BLE_RenderEngine *e) { (void)e; }
static void br_gpu_free(BLE_RenderEngine *e) { (void)e; }

static BLE_RenderEngineVTable br_vtable = {
    .name = "blender_render",
    .description = "Internal Blender Render",
    .type = BLE_RENDER_ENGINE_INTERNAL,
    .init = br_init, .shutdown = br_shutdown, .scene_sync = br_scene_sync, .view_layer_sync = br_view_sync,
    .render_start = br_start, .render_tile = br_tile, .render_cancel = br_cancel, .render_end = br_end,
    .draw_viewport = br_draw, .viewport_update = br_update, .settings_ui_draw = br_ui, .gpu_resources_init = br_gpu_init, .gpu_resources_free = br_gpu_free,
};

BLE_RenderEngine blender_render_engine = { .vtable = &br_vtable, .is_active = 0 };
BLE_RenderEngine *BLE_render_engine_get_blender_render(void) { return &blender_render_engine; }
