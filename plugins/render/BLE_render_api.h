#ifndef BLE_RENDER_API_H
#define BLE_RENDER_API_H

#include "BLE_types.h"
#include "BLE_module_api.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum BLE_RenderEngineType {
    BLE_RENDER_ENGINE_INTERNAL = 0,
    BLE_RENDER_ENGINE_EEVEE = 1,
    BLE_RENDER_ENGINE_CYCLES = 2,
    BLE_RENDER_ENGINE_WORKBENCH = 3,
    BLE_RENDER_ENGINE_CUSTOM = 100,
} BLE_RenderEngineType;

typedef struct BLE_RenderSettings {
    int width;
    int height;
    int samples;
    int use_gpu;
    int use_denoising;
    int use_motion_blur;
    float shutter_open;
    float shutter_close;
    int max_bounces;
    int min_bounces;
    float exposure;
    BLE_ColorRGBA film_transparent;
} BLE_RenderSettings;

typedef struct BLE_RenderContext BLE_RenderContext;
typedef struct BLE_RenderEngine BLE_RenderEngine;
typedef struct BLE_RenderScene BLE_RenderScene;
typedef struct BLE_RenderViewLayer BLE_RenderViewLayer;
typedef struct BLE_RenderResult BLE_RenderResult;

typedef struct BLE_RenderEngineVTable {
    const char *name;
    const char *description;
    BLE_RenderEngineType type;
    
    int (*init)(BLE_RenderEngine *engine, BLE_RenderContext *ctx);
    void (*shutdown)(BLE_RenderEngine *engine);
    
    int (*scene_sync)(BLE_RenderEngine *engine, BLE_RenderScene *scene);
    int (*view_layer_sync)(BLE_RenderEngine *engine, BLE_RenderViewLayer *view_layer);
    
    int (*render_start)(BLE_RenderEngine *engine, BLE_RenderResult *result);
    int (*render_tile)(BLE_RenderEngine *engine, int x, int y, int w, int h, BLE_RenderResult *result);
    void (*render_cancel)(BLE_RenderEngine *engine);
    void (*render_end)(BLE_RenderEngine *engine, BLE_RenderResult *result);
    
    void (*draw_viewport)(BLE_RenderEngine *engine, void *viewport_data);
    void (*viewport_update)(BLE_RenderEngine *engine, void *viewport_data);
    
    void (*settings_ui_draw)(BLE_RenderEngine *engine, void *ui_context);
    
    void (*gpu_resources_init)(BLE_RenderEngine *engine);
    void (*gpu_resources_free)(BLE_RenderEngine *engine);
} BLE_RenderEngineVTable;

struct BLE_RenderEngine {
    BLE_RenderEngineVTable *vtable;
    void *private_data;
    BLE_RenderSettings settings;
    int is_active;
};

struct BLE_RenderContext {
    BLE_ModuleContext *module_ctx;
    BLE_RenderEngine *active_engine;
    BLE_RenderEngine **engines;
    int num_engines;
    int max_engines;
    BLE_RenderSettings global_settings;
    void *gpu_context;
    void *scene_data;
};

typedef struct BLE_RenderModule {
    BLE_Module base;
    BLE_RenderContext *context;
} BLE_RenderModule;

BLE_RenderContext *BLE_render_context_create(BLE_ModuleContext *module_ctx);
void BLE_render_context_destroy(BLE_RenderContext *ctx);

int BLE_render_engine_register(BLE_RenderContext *ctx, BLE_RenderEngine *engine);
BLE_RenderEngine *BLE_render_engine_find(BLE_RenderContext *ctx, const char *name);
BLE_RenderEngine *BLE_render_engine_find_by_type(BLE_RenderContext *ctx, BLE_RenderEngineType type);
int BLE_render_engine_set_active(BLE_RenderContext *ctx, const char *name);

int BLE_render_scene(BLE_RenderContext *ctx, BLE_RenderScene *scene, BLE_RenderResult *result);
void BLE_render_viewport(BLE_RenderContext *ctx, void *viewport_data);

#ifdef __cplusplus
}
#endif

#endif