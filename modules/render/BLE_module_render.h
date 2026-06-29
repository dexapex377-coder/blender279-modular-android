#ifndef BLE_MODULE_RENDER_H
#define BLE_MODULE_RENDER_H

#include "BLE_types.h"
#include "BLE_module_api.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BLE_RenderEngine BLE_RenderEngine;
typedef struct BLE_RenderResult BLE_RenderResult;
typedef struct BLE_Scene BLE_Scene;
typedef struct BLE_Object BLE_Object;
typedef struct BLE_Camera BLE_Camera;

typedef enum BLE_RenderEngineType {
    BLE_RENDER_BLENDER_INTERNAL = 0,
    BLE_RENDER_CYCLES = 1,
} BLE_RenderEngineType;

typedef struct BLE_RenderSettings {
    int xres, yres;
    int xres_final, yres_final;
    int samples;
    int use_oversample;
    int tile_x, tile_y;
    int render_engine; // BLE_RenderEngineType
    float exposure;
    int use_freestyle;
    int use_motion_blur;
    int use_compositing;
} BLE_RenderSettings;

typedef struct BLE_RenderModule {
    BLE_Module base;
    
    // Engine management
    BLE_RenderEngine* (*engine_create)(BLE_RenderEngineType type);
    void (*engine_free)(BLE_RenderEngine* engine);
    int (*engine_render)(BLE_RenderEngine* engine, BLE_Scene* scene, BLE_RenderSettings* settings, BLE_RenderResult* result);
    int (*engine_render_viewport)(BLE_RenderEngine* engine, BLE_Scene* scene, BLE_Camera* camera, void* viewport_data);
    
    // Settings
    void (*settings_default)(BLE_RenderSettings* settings);
    int (*settings_parse)(BLE_RenderSettings* settings, int argc, char** argv);
    
    // Result
    BLE_RenderResult* (*result_new)(int x, int y);
    void (*result_free)(BLE_RenderResult* result);
    void* (*result_get_pixel)(BLE_RenderResult* result, int x, int y);
} BLE_RenderModule;

BLE_Module* BLE_render_module_create(void);
BLE_Module* BLE_module_get_ble_render(void);

// Engine API
BLE_RenderEngine* BLE_engine_create(BLE_RenderEngineType type);
void BLE_engine_free(BLE_RenderEngine* engine);
int BLE_engine_render(BLE_RenderEngine* engine, BLE_Scene* scene, BLE_RenderSettings* settings, BLE_RenderResult* result);
int BLE_engine_render_viewport(BLE_RenderEngine* engine, BLE_Scene* scene, BLE_Camera* camera, void* viewport_data);

// Settings
void BLE_settings_default(BLE_RenderSettings* settings);
int BLE_settings_parse(BLE_RenderSettings* settings, int argc, char** argv);

// Result
BLE_RenderResult* BLE_result_new(int x, int y);
void BLE_result_free(BLE_RenderResult* result);
void* BLE_result_get_pixel(BLE_RenderResult* result, int x, int y);

#ifdef __cplusplus
}
#endif

#endif