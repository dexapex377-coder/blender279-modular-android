#ifndef BLE_MODULE_IO_H
#define BLE_MODULE_IO_H

#include "BLE_types.h"
#include "BLE_module_api.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BLE_BlendFile BLE_BlendFile;
typedef struct BLE_AlembicFile BLE_AlembicFile;
typedef struct BLE_ColladaFile BLE_ColladaFile;

typedef struct BLE_IOModule {
    BLE_Module base;
    
    // Blendfile I/O
    BLE_BlendFile* (*blendfile_read)(const char* filepath);
    int (*blendfile_write)(BLE_BlendFile* bf, const char* filepath);
    void (*blendfile_free)(BLE_BlendFile* bf);
    int (*blendfile_version_check)(BLE_BlendFile* bf);
    
    // RNA/Serialization
    void* (*rna_serialize)(void* data, const char* type_name);
    void* (*rna_deserialize)(const void* data, size_t size, const char* type_name);
    
    // Alembic
    BLE_AlembicFile* (*alembic_read)(const char* filepath);
    int (*alembic_write)(BLE_AlembicFile* af, const char* filepath);
    void (*alembic_free)(BLE_AlembicFile* af);
    
    // Collada
    BLE_ColladaFile* (*collada_read)(const char* filepath);
    int (*collada_write)(BLE_ColladaFile* cf, const char* filepath);
    void (*collada_free)(BLE_ColladaFile* cf);
} BLE_IOModule;

BLE_Module* BLE_io_module_create(void);
BLE_Module* BLE_module_get_ble_io(void);

// Blendfile API
BLE_BlendFile* BLE_blendfile_read(const char* filepath);
int BLE_blendfile_write(BLE_BlendFile* bf, const char* filepath);
void BLE_blendfile_free(BLE_BlendFile* bf);
int BLE_blendfile_version_check(BLE_BlendFile* bf);

// RNA/Serialization
void* BLE_rna_serialize(void* data, const char* type_name);
void* BLE_rna_deserialize(const void* data, size_t size, const char* type_name);

// Alembic
BLE_AlembicFile* BLE_alembic_read(const char* filepath);
int BLE_alembic_write(BLE_AlembicFile* af, const char* filepath);
void BLE_alembic_free(BLE_AlembicFile* af);

// Collada
BLE_ColladaFile* BLE_collada_read(const char* filepath);
int BLE_collada_write(BLE_ColladaFile* cf, const char* filepath);
void BLE_collada_free(BLE_ColladaFile* cf);

#ifdef __cplusplus
}
#endif

#endif