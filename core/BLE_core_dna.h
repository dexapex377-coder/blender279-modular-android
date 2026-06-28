#ifndef BLE_CORE_DNA_H
#define BLE_CORE_DNA_H

#include "BLE_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum BLE_DNA_TypeKind {
    BLE_DNA_TYPE_VOID = 0,
    BLE_DNA_TYPE_INT8, BLE_DNA_TYPE_INT16, BLE_DNA_TYPE_INT32, BLE_DNA_TYPE_INT64,
    BLE_DNA_TYPE_UINT8, BLE_DNA_TYPE_UINT16, BLE_DNA_TYPE_UINT32, BLE_DNA_TYPE_UINT64,
    BLE_DNA_TYPE_FLOAT, BLE_DNA_TYPE_DOUBLE,
    BLE_DNA_TYPE_BOOL,
    BLE_DNA_TYPE_STRING,
    BLE_DNA_TYPE_POINTER,
    BLE_DNA_TYPE_ARRAY,
    BLE_DNA_TYPE_STRUCT,
} BLE_DNA_TypeKind;

typedef struct BLE_DNA_Type {
    const char *name;
    BLE_DNA_TypeKind kind;
    size_t size;
    size_t alignment;
    struct BLE_DNA_Type *element_type;
    int array_size;
    struct BLE_DNA_Struct *struct_type;
    void (*constructor)(void *ptr);
    void (*destructor)(void *ptr);
    void (*copy)(void *dst, const void *src);
} BLE_DNA_Type;

typedef struct BLE_DNA_Field {
    const char *name;
    BLE_DNA_Type *type;
    size_t offset;
} BLE_DNA_Field;

struct BLE_DNA_Struct {
    const char *name;
    BLE_DNA_Field *fields;
    int num_fields;
    size_t size;
    size_t alignment;
    void (*constructor)(void *ptr);
    void (*destructor)(void *ptr);
};

typedef struct BLE_DNA_Library {
    BLE_DNA_Type **types;
    int num_types;
    int max_types;
    BLE_DNA_Struct **structs;
    int num_structs;
    int max_structs;
} BLE_DNA_Library;

typedef struct BLE_DNA_API {
    BLE_DNA_Library *(*library_create)(void);
    void (*library_destroy)(BLE_DNA_Library *lib);
    int (*type_register)(BLE_DNA_Library *lib, BLE_DNA_Type *type);
    int (*struct_register)(BLE_DNA_Library *lib, BLE_DNA_Struct *st);
    BLE_DNA_Type *(*type_find)(BLE_DNA_Library *lib, const char *name);
    BLE_DNA_Struct *(*struct_find)(BLE_DNA_Library *lib, const char *name);
    void *(*struct_create)(BLE_DNA_Library *lib, const char *type_name);
    void (*struct_free)(BLE_DNA_Library *lib, void *data, const char *type_name);
    void (*struct_copy)(BLE_DNA_Library *lib, void *dst, const void *src, const char *type_name);
    size_t (*struct_size)(BLE_DNA_Library *lib, const char *type_name);
    BLE_DNA_Type *(*type_create_primitive)(const char *name, BLE_DNA_TypeKind kind, size_t size);
    BLE_DNA_Type *(*type_create_array)(const char *name, BLE_DNA_Type *element, int count);
    BLE_DNA_Type *(*type_create_pointer)(const char *name, BLE_DNA_Type *element);
    BLE_DNA_Struct *(*struct_create_def)(const char *name, BLE_DNA_Field *fields, int num_fields);
} BLE_DNA_API;

BLE_DNA_API *BLE_dna_api_get(void);
BLE_DNA_Library *BLE_dna_library_create(void);
void BLE_dna_library_destroy(BLE_DNA_Library *lib);

int BLE_dna_type_register(BLE_DNA_Library *lib, BLE_DNA_Type *type);
int BLE_dna_struct_register(BLE_DNA_Library *lib, BLE_DNA_Struct *st);
BLE_DNA_Type *BLE_dna_type_find(BLE_DNA_Library *lib, const char *name);
BLE_DNA_Struct *BLE_dna_struct_find(BLE_DNA_Library *lib, const char *name);

void *BLE_dna_struct_create(BLE_DNA_Library *lib, const char *type_name);
void BLE_dna_struct_free(BLE_DNA_Library *lib, void *data, const char *type_name);
void BLE_dna_struct_copy(BLE_DNA_Library *lib, void *dst, const void *src, const char *type_name);
size_t BLE_dna_struct_size(BLE_DNA_Library *lib, const char *type_name);

BLE_DNA_Type *BLE_dna_type_create_primitive(const char *name, BLE_DNA_TypeKind kind, size_t size);
BLE_DNA_Type *BLE_dna_type_create_array(const char *name, BLE_DNA_Type *element, int count);
BLE_DNA_Type *BLE_dna_type_create_pointer(const char *name, BLE_DNA_Type *element);
BLE_DNA_Struct *BLE_dna_struct_create_def(const char *name, BLE_DNA_Field *fields, int num_fields);

#ifdef __cplusplus
}
#endif

#endif