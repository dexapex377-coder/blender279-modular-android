#ifndef BLE_MODULE_API_H
#define BLE_MODULE_API_H

#include "BLE_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BLE_MODULE_API_VERSION 1

typedef struct BLE_Module BLE_Module;
typedef struct BLE_ModuleRegistry BLE_ModuleRegistry;
typedef struct BLE_ModuleContext BLE_ModuleContext;

typedef enum BLE_ModuleType {
    BLE_MODULE_TYPE_CORE = 0,
    BLE_MODULE_TYPE_TOOLS = 1,
    BLE_MODULE_TYPE_RENDER = 2,
    BLE_MODULE_TYPE_PHYSICS = 3,
    BLE_MODULE_TYPE_IO = 4,
    BLE_MODULE_TYPE_PYTHON = 5,
    BLE_MODULE_TYPE_UI = 6,
} BLE_ModuleType;

typedef struct BLE_ModuleInfo {
    const char *name;
    const char *version;
    int api_version;
    BLE_ModuleType type;
    const char **dependencies;
    int num_dependencies;
} BLE_ModuleInfo;

typedef struct BLE_ModuleVTable {
    int (*init)(BLE_ModuleContext *ctx);
    void (*shutdown)(BLE_ModuleContext *ctx);
    void (*register_types)(BLE_ModuleContext *ctx);
    void (*register_tools)(BLE_ModuleContext *ctx);
    void (*register_render_engines)(BLE_ModuleContext *ctx);
    void (*register_physics)(BLE_ModuleContext *ctx);
} BLE_ModuleVTable;

struct BLE_Module {
    BLE_ModuleInfo info;
    BLE_ModuleVTable vtable;
    void *private_data;
    int is_loaded;
};

typedef struct BLE_ModuleRegistry {
    BLE_Module **modules;
    int num_modules;
    int max_modules;
} BLE_ModuleRegistry;

typedef struct BLE_ModuleContext {
    BLE_ModuleRegistry *registry;
    void *core_api;
    void *dna_api;
    void *math_api;
    void *mem_api;
} BLE_ModuleContext;

BLE_ModuleRegistry *BLE_module_registry_create(void);
void BLE_module_registry_destroy(BLE_ModuleRegistry *reg);
int BLE_module_register(BLE_ModuleRegistry *reg, BLE_Module *module);
int BLE_module_unregister(BLE_ModuleRegistry *reg, const char *name);
BLE_Module *BLE_module_find(BLE_ModuleRegistry *reg, const char *name);
BLE_Module *BLE_module_find_by_type(BLE_ModuleRegistry *reg, BLE_ModuleType type);
void BLE_module_unload_all(BLE_ModuleRegistry *reg);
BLE_ModuleContext *BLE_module_context_create(BLE_ModuleRegistry *reg);
void BLE_module_context_destroy(BLE_ModuleContext *ctx);

#ifdef __cplusplus
}
#endif

#endif