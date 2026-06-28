#ifndef BLE_MODULE_TOOLS_H
#define BLE_MODULE_TOOLS_H

#include "BLE_types.h"
#include "BLE_module_api.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum BLE_ToolType {
    BLE_TOOL_TYPE_MESH = 0,
    BLE_TOOL_TYPE_SCULPT = 1,
    BLE_TOOL_TYPE_ANIMATION = 2,
    BLE_TOOL_TYPE_PAINT = 3,
    BLE_TOOL_TYPE_CURVES = 4,
    BLE_TOOL_TYPE_GREASE_PENCIL = 5,
} BLE_ToolType;

typedef struct BLE_ToolContext BLE_ToolContext;
typedef struct BLE_Tool BLE_Tool;

typedef struct BLE_ToolVTable {
    const char *name;
    const char *description;
    BLE_ToolType type;
    int (*init)(BLE_Tool *tool, BLE_ToolContext *ctx);
    void (*shutdown)(BLE_Tool *tool);
    void (*activate)(BLE_Tool *tool, BLE_ToolContext *ctx);
    void (*deactivate)(BLE_Tool *tool);
    int (*handle_event)(BLE_Tool *tool, BLE_ToolContext *ctx, int event_type, void *event_data);
    void (*draw)(BLE_Tool *tool, BLE_ToolContext *ctx);
} BLE_ToolVTable;

struct BLE_Tool {
    BLE_ToolVTable *vtable;
    void *private_data;
    int active;
};

typedef struct BLE_ToolContext {
    BLE_ModuleContext *module_ctx;
    void *scene;
    void *object;
    void *mesh;
    BLE_Vec3 mouse_pos;
    BLE_Vec3 ray_origin;
    BLE_Vec3 ray_dir;
    int modifiers;
    float pressure;
} BLE_ToolContext;

typedef struct BLE_ToolsModule {
    BLE_Module base;
    BLE_Tool **tools;
    int num_tools;
    int max_tools;
} BLE_ToolsModule;

BLE_Module *BLE_tools_module_create(void);
int BLE_tools_register_tool(BLE_ToolsModule *mod, BLE_Tool *tool);
BLE_Tool *BLE_tools_find_tool(BLE_ToolsModule *mod, const char *name);
BLE_Tool *BLE_tools_find_by_type(BLE_ToolsModule *mod, BLE_ToolType type);

#ifdef __cplusplus
}
#endif

#endif