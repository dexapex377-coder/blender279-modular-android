#include "BLE_module_api.h"
#include "BLE_types.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int module_dep_check(BLE_ModuleRegistry *reg, BLE_Module *mod) {
    for (int i = 0; i < mod->info.num_dependencies; i++) {
        if (!BLE_module_find(reg, mod->info.dependencies[i])) {
            fprintf(stderr, "[Module] Missing dependency: %s for module %s\n",
                    mod->info.dependencies[i], mod->info.name);
            return 0;
        }
    }
    return 1;
}

BLE_ModuleRegistry *BLE_module_registry_create(void) {
    BLE_ModuleRegistry *reg = calloc(1, sizeof(BLE_ModuleRegistry));
    reg->max_modules = 64;
    reg->modules = calloc(reg->max_modules, sizeof(BLE_Module*));
    return reg;
}

void BLE_module_registry_destroy(BLE_ModuleRegistry *reg) {
    if (!reg) return;
    BLE_module_unload_all(reg);
    free(reg->modules);
    free(reg);
}

int BLE_module_register(BLE_ModuleRegistry *reg, BLE_Module *module) {
    if (reg->num_modules >= reg->max_modules) {
        fprintf(stderr, "[Module] Registry full\n");
        return 0;
    }
    if (module->info.api_version != BLE_MODULE_API_VERSION) {
        fprintf(stderr, "[Module] API version mismatch for %s\n", module->info.name);
        return 0;
    }
    if (!module_dep_check(reg, module)) {
        return 0;
    }
    reg->modules[reg->num_modules++] = module;
    module->is_loaded = 1;
    fprintf(stderr, "[Module] Registered: %s v%s\n", module->info.name, module->info.version);
    return 1;
}

int BLE_module_unregister(BLE_ModuleRegistry *reg, const char *name) {
    for (int i = 0; i < reg->num_modules; i++) {
        if (strcmp(reg->modules[i]->info.name, name) == 0) {
            if (reg->modules[i]->vtable.shutdown) {
                BLE_ModuleContext ctx = { .registry = reg };
                reg->modules[i]->vtable.shutdown(&ctx);
            }
            reg->modules[i]->is_loaded = 0;
            for (int j = i; j < reg->num_modules - 1; j++) {
                reg->modules[j] = reg->modules[j + 1];
            }
            reg->num_modules--;
            fprintf(stderr, "[Module] Unregistered: %s\n", name);
            return 1;
        }
    }
    return 0;
}

BLE_Module *BLE_module_find(BLE_ModuleRegistry *reg, const char *name) {
    for (int i = 0; i < reg->num_modules; i++) {
        if (strcmp(reg->modules[i]->info.name, name) == 0) {
            return reg->modules[i];
        }
    }
    return NULL;
}

BLE_Module *BLE_module_find_by_type(BLE_ModuleRegistry *reg, BLE_ModuleType type) {
    for (int i = 0; i < reg->num_modules; i++) {
        if (reg->modules[i]->info.type == type) {
            return reg->modules[i];
        }
    }
    return NULL;
}

void BLE_module_unload_all(BLE_ModuleRegistry *reg) {
    for (int i = reg->num_modules - 1; i >= 0; i--) {
        BLE_module_unregister(reg, reg->modules[i]->info.name);
    }
}

BLE_ModuleContext *BLE_module_context_create(BLE_ModuleRegistry *reg) {
    BLE_ModuleContext *ctx = calloc(1, sizeof(BLE_ModuleContext));
    ctx->registry = reg;
    return ctx;
}

void BLE_module_context_destroy(BLE_ModuleContext *ctx) {
    free(ctx);
}