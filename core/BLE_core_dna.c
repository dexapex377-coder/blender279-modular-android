#include "BLE_core_dna.h"
#include "BLE_core_memory.h"
#include <string.h>
#include <stdlib.h>

static BLE_DNA_Library *g_dna_lib = NULL;

static int dna_type_register(BLE_DNA_Library *lib, BLE_DNA_Type *type) {
    if (lib->num_types >= lib->max_types) {
        int new_max = lib->max_types ? lib->max_types * 2 : 64;
        lib->types = BLE_mem_realloc(lib->types, new_max * sizeof(BLE_DNA_Type*));
        lib->max_types = new_max;
    }
    lib->types[lib->num_types++] = type;
    return 1;
}

static int dna_struct_register(BLE_DNA_Library *lib, BLE_DNA_Struct *st) {
    if (lib->num_structs >= lib->max_structs) {
        int new_max = lib->max_structs ? lib->max_structs * 2 : 64;
        lib->structs = BLE_mem_realloc(lib->structs, new_max * sizeof(BLE_DNA_Struct*));
        lib->max_structs = new_max;
    }
    lib->structs[lib->num_structs++] = st;
    return 1;
}

static BLE_DNA_Type *dna_type_find(BLE_DNA_Library *lib, const char *name) {
    for (int i = 0; i < lib->num_types; i++) {
        if (strcmp(lib->types[i]->name, name) == 0) return lib->types[i];
    }
    return NULL;
}

static BLE_DNA_Struct *dna_struct_find(BLE_DNA_Library *lib, const char *name) {
    for (int i = 0; i < lib->num_structs; i++) {
        if (strcmp(lib->structs[i]->name, name) == 0) return lib->structs[i];
    }
    return NULL;
}

static void *dna_struct_create_impl(BLE_DNA_Library *lib, const char *type_name) {
    BLE_DNA_Struct *st = dna_struct_find(lib, type_name);
    if (!st) return NULL;
    void *ptr = BLE_mem_alloc_aligned(st->size, st->alignment);
    if (st->constructor) st->constructor(ptr);
    return ptr;
}

static void dna_struct_free_impl(BLE_DNA_Library *lib, void *data, const char *type_name) {
    BLE_DNA_Struct *st = dna_struct_find(lib, type_name);
    if (st && st->destructor) st->destructor(data);
    BLE_mem_free_aligned(data);
}

static void dna_struct_copy_impl(BLE_DNA_Library *lib, void *dst, const void *src, const char *type_name) {
    BLE_DNA_Struct *st = dna_struct_find(lib, type_name);
    if (!st) return;
    for (int i = 0; i < st->num_fields; i++) {
        BLE_DNA_Field *f = &st->fields[i];
        if (f->type->copy) {
            f->type->copy((char*)dst + f->offset, (const char*)src + f->offset);
        } else {
            memcpy((char*)dst + f->offset, (const char*)src + f->offset, f->type->size);
        }
    }
}

static size_t dna_struct_size_impl(BLE_DNA_Library *lib, const char *type_name) {
    BLE_DNA_Struct *st = dna_struct_find(lib, type_name);
    return st ? st->size : 0;
}

static BLE_DNA_Type *dna_type_create_primitive(const char *name, BLE_DNA_TypeKind kind, size_t size) {
    BLE_DNA_Type *t = BLE_mem_alloc(sizeof(BLE_DNA_Type));
    t->name = name;
    t->kind = kind;
    t->size = size;
    t->alignment = size < 8 ? size : 8;
    t->element_type = NULL;
    t->array_size = 0;
    t->struct_type = NULL;
    t->constructor = NULL;
    t->destructor = NULL;
    t->copy = NULL;
    return t;
}

static BLE_DNA_Type *dna_type_create_array(const char *name, BLE_DNA_Type *element, int count) {
    BLE_DNA_Type *t = BLE_mem_alloc(sizeof(BLE_DNA_Type));
    t->name = name;
    t->kind = BLE_DNA_TYPE_ARRAY;
    t->size = element->size * count;
    t->alignment = element->alignment;
    t->element_type = element;
    t->array_size = count;
    t->struct_type = NULL;
    t->constructor = NULL;
    t->destructor = NULL;
    t->copy = NULL;
    return t;
}

static BLE_DNA_Type *dna_type_create_pointer(const char *name, BLE_DNA_Type *element) {
    BLE_DNA_Type *t = BLE_mem_alloc(sizeof(BLE_DNA_Type));
    t->name = name;
    t->kind = BLE_DNA_TYPE_POINTER;
    t->size = sizeof(void*);
    t->alignment = sizeof(void*);
    t->element_type = element;
    t->array_size = 0;
    t->struct_type = NULL;
    t->constructor = NULL;
    t->destructor = NULL;
    t->copy = NULL;
    return t;
}

static BLE_DNA_Struct *dna_struct_create_def(const char *name, BLE_DNA_Field *fields, int num_fields) {
    BLE_DNA_Struct *st = BLE_mem_alloc(sizeof(BLE_DNA_Struct));
    st->name = name;
    st->fields = fields;
    st->num_fields = num_fields;
    st->size = 0;
    st->alignment = 1;
    st->constructor = st->destructor = NULL;
    
    for (int i = 0; i < num_fields; i++) {
        size_t align = fields[i].type->alignment;
        size_t offset = (st->size + align - 1) & ~(align - 1);
        fields[i].offset = offset;
        st->size = offset + fields[i].type->size;
        if (align > st->alignment) st->alignment = align;
    }
    return st;
}

static BLE_DNA_API dna_api = {
    .library_create = BLE_dna_library_create,
    .library_destroy = BLE_dna_library_destroy,
    .type_register = dna_type_register,
    .struct_register = dna_struct_register,
    .type_find = dna_type_find,
    .struct_find = dna_struct_find,
    .struct_create = dna_struct_create_impl,
    .struct_free = dna_struct_free_impl,
    .struct_copy = dna_struct_copy_impl,
    .struct_size = dna_struct_size_impl,
    .type_create_primitive = dna_type_create_primitive,
    .type_create_array = dna_type_create_array,
    .type_create_pointer = dna_type_create_pointer,
    .struct_create_def = dna_struct_create_def,
};

BLE_DNA_API *BLE_dna_api_get(void) { return &dna_api; }

BLE_DNA_Library *BLE_dna_library_create(void) {
    BLE_DNA_Library *lib = BLE_mem_alloc(sizeof(BLE_DNA_Library));
    memset(lib, 0, sizeof(BLE_DNA_Library));
    return lib;
}

void BLE_dna_library_destroy(BLE_DNA_Library *lib) {
    BLE_mem_free(lib->types);
    BLE_mem_free(lib->structs);
    BLE_mem_free(lib);
}

int BLE_dna_type_register(BLE_DNA_Library *lib, BLE_DNA_Type *type) {
    return dna_type_register(lib, type);
}
int BLE_dna_struct_register(BLE_DNA_Library *lib, BLE_DNA_Struct *st) {
    return dna_struct_register(lib, st);
}
BLE_DNA_Type *BLE_dna_type_find(BLE_DNA_Library *lib, const char *name) {
    return dna_type_find(lib, name);
}
BLE_DNA_Struct *BLE_dna_struct_find(BLE_DNA_Library *lib, const char *name) {
    return dna_struct_find(lib, name);
}
void *BLE_dna_struct_create(BLE_DNA_Library *lib, const char *type_name) {
    return dna_struct_create_impl(lib, type_name);
}
void BLE_dna_struct_free(BLE_DNA_Library *lib, void *data, const char *type_name) {
    dna_struct_free_impl(lib, data, type_name);
}
void BLE_dna_struct_copy(BLE_DNA_Library *lib, void *dst, const void *src, const char *type_name) {
    dna_struct_copy_impl(lib, dst, src, type_name);
}
size_t BLE_dna_struct_size(BLE_DNA_Library *lib, const char *type_name) {
    return dna_struct_size_impl(lib, type_name);
}
BLE_DNA_Type *BLE_dna_type_create_primitive(const char *name, BLE_DNA_TypeKind kind, size_t size) {
    return dna_type_create_primitive(name, kind, size);
}
BLE_DNA_Type *BLE_dna_type_create_array(const char *name, BLE_DNA_Type *element, int count) {
    return dna_type_create_array(name, element, count);
}
BLE_DNA_Type *BLE_dna_type_create_pointer(const char *name, BLE_DNA_Type *element) {
    return dna_type_create_pointer(name, element);
}
BLE_DNA_Struct *BLE_dna_struct_create_def(const char *name, BLE_DNA_Field *fields, int num_fields) {
    return dna_struct_create_def(name, fields, num_fields);
}