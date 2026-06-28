#include "BLE_render_api.h"
#include <stdio.h>

static int ee_init(BLE_RenderEngine *e, BLE_RenderContext *c) { (void)c; fprintf(stderr, "[EEVEE] Init\n"); return 1; }
static void ee_shutdown(BLE_RenderEngine *e) { fprintf(stderr, "[EEVEE] Shutdown\n"); }
static int ee_scene_sync(BLE_RenderEngine *e, BLE_RenderScene *s) { (void)e; (void)s; return 1; }
static int ee_view_sync(BLE_RenderEngine *e, BLE_RenderViewLayer *vl) { (void)e; (void)vl; return 1; }
static int ee_start(BLE_RenderEngine *e, BLE_RenderResult *r) { fprintf(stderr, "[EEVEE] Rendering... (FAST)\n"); (void)e; (void)r; return 1; }
static int ee_tile(BLE_RenderEngine *e, int x, int y, int w, int h, BLE_RenderResult *r) { (void)e; (void)x; (void)y; (void)w; (void)h; (void)r; return 1; }
static void ee_cancel(BLE_RenderEngine *e) { (void)e; }
static void ee_end(BLE_RenderEngine *e, BLE_RenderResult *r) { (void)e; (void)r; }
static void ee_draw(BLE_RenderEngine *e, void *vp) { fprintf(stderr, "[EEVEE] Drawing PBR Viewport\n"); (void)e; (void)vp; }
static void ee_update(BLE_RenderEngine *e, void *vp) { (void)e; (void)vp; }
static void ee_ui(BLE_RenderEngine *e, void *ui) { (void)e; (void)ui; }
static void ee_gpu_init(BLE_RenderEngine *e) { fprintf(stderr, "[EEVEE] GPU Init\n"); (void)e; }
static void ee_gpu_free(BLE_RenderEngine *e) { (void)e; }

static BLE_RenderEngineVTable ee_vtable = {
    .name = "eevee",
    .description = "EEVEE Real-time Engine",
    .type = BLE_RENDER_ENGINE_EEVEE,
    .init = ee_init, .shutdown = ee_shutdown, .scene_sync = ee_scene_sync, .view_layer_sync = ee_view_sync,
    .render_start = ee_start, .render_tile = ee_tile, .render_cancel = ee_cancel, .render_end = ee_end,
    .draw_viewport = ee_draw, .viewport_update = ee_update, .settings_ui_draw = ee_ui, .gpu_resources_init = ee_gpu_init, .gpu_resources_free = ee_gpu_free,
};

BLE_RenderEngine eevee_engine = { .vtable = &ee_vtable, .is_active = 0 };
BLE_RenderEngine *BLE_render_engine_get_eevee(void) { return &eevee_engine; }
