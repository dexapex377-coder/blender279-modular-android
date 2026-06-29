#ifndef BLE_MODULE_DEPSGRAPH_H
#define BLE_MODULE_DEPSGRAPH_H

#include "BLE_types.h"
#include "BLE_module_api.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BLE_Depsgraph BLE_Depsgraph;
typedef struct BLE_DepsgraphNode BLE_DepsgraphNode;
typedef struct BLE_DepsgraphRelation BLE_DepsgraphRelation;
typedef struct BLE_Scene BLE_Scene;
typedef struct BLE_Object BLE_Object;
typedef struct BLE_ViewLayer BLE_ViewLayer;

typedef struct BLE_DepsgraphModule {
    BLE_Module base;
    
    // Depsgraph API
    BLE_Depsgraph* (*depsgraph_new)(BLE_Scene* scene, BLE_ViewLayer* view_layer);
    void (*depsgraph_free)(BLE_Depsgraph* dg);
    
    // Build
    int (*depsgraph_build)(BLE_Depsgraph* dg);
    int (*depsgraph_rebuild)(BLE_Depsgraph* dg);
    
    // Evaluation
    int (*depsgraph_eval)(BLE_Depsgraph* dg);
    int (*depsgraph_flush_updates)(BLE_Depsgraph* dg);
    
    // Node access
    BLE_DepsgraphNode* (*depsgraph_get_node)(BLE_Depsgraph* dg, BLE_Object* ob);
    BLE_DepsgraphNode* (*depsgraph_get_eval_node)(BLE_Depsgraph* dg, BLE_Object* ob);
    
    // Query
    BLE_Object* (*depsgraph_get_eval_object)(BLE_Depsgraph* dg, BLE_Object* ob);
    void* (*depsgraph_get_eval_data)(BLE_Depsgraph* dg, BLE_Object* ob);
    
    // Debug
    void (*depsgraph_debug_print)(BLE_Depsgraph* dg);
} BLE_DepsgraphModule;

BLE_Module* BLE_depsgraph_module_create(void);
BLE_Module* BLE_module_get_ble_depsgraph(void);

// Depsgraph API
BLE_Depsgraph* BLE_depsgraph_new(BLE_Scene* scene, BLE_ViewLayer* view_layer);
void BLE_depsgraph_free(BLE_Depsgraph* dg);
int BLE_depsgraph_build(BLE_Depsgraph* dg);
int BLE_depsgraph_rebuild(BLE_Depsgraph* dg);
int BLE_depsgraph_eval(BLE_Depsgraph* dg);
int BLE_depsgraph_flush_updates(BLE_Depsgraph* dg);
BLE_DepsgraphNode* BLE_depsgraph_get_node(BLE_Depsgraph* dg, BLE_Object* ob);
BLE_DepsgraphNode* BLE_depsgraph_get_eval_node(BLE_Depsgraph* dg, BLE_Object* ob);
BLE_Object* BLE_depsgraph_get_eval_object(BLE_Depsgraph* dg, BLE_Object* ob);
void* BLE_depsgraph_get_eval_data(BLE_Depsgraph* dg, BLE_Object* ob);
void BLE_depsgraph_debug_print(BLE_Depsgraph* dg);

#ifdef __cplusplus
}
#endif

#endif