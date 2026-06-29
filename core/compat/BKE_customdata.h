#ifndef __BKE_CUSTOMDATA_H__
#define __BKE_CUSTOMDATA_H__

#include <stdbool.h>

#include "DNA_customdata_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Standard data types */
enum {
    CD_MVERT = 0,
    CD_MEDGE = 1,
    CD_MFACE = 2,
    CD_MLOOP = 3,
    CD_MPOLY = 4,
    CD_MTFACE = 5,
    CD_MCOL = 6,
    CD_ORIGINDEX = 7,
    CD_NORMAL = 8,
    CD_FACEMAP = 9,
    CD_BM_ELEM_PYPTR = 10,
    CD_PROP_FLT = 11,
    CD_PROP_INT = 12,
    CD_PROP_STR = 13,
    CD_ORCO = 14,
    CD_BAKE_VERT = 15,
    CD_CLOTH_ORCO = 16,
    CD_MDISPS = 17,
    CD_TANGENT = 18,
    CD_MLOOPTANGENT = 19,
    CD_MCOL_LAYER = 20,
    CD_MTFACE_LAYER = 21,
    CD_PAINT_MASK = 22,
    CD_MVERT_SKIN = 23,
    CD_SHAPE_KEYINDEX = 24,
    CD_SHAPEKEY = 25,
    CD_EASY = 26,
    CD_MTEXPOLY = 27,
    CD_MLOOPUV = 28,
    CD_BWEIGHT = 29,
    CD_CREASE = 30,
    CD_MDEFORMVERT = 31,
    CD_NUM = 32,
};

/* Flags */
#define CD_FLAG_NOCOPY 1
#define CD_FLAG_NOFREE 2
#define CD_FLAG_NOSET 4
#define CD_FLAG_TEMPORARY 8

/* Layer type flags */
#define CD_LAYER_TYPE_MASK 0xFFFF
#define CD_LAYER_FLAG_ACTIVE 0x10000
#define CD_LAYER_FLAG_DEFAULT 0x20000

/* Copy modes */
#define CD_ASSIGN 0
#define CD_CALLOC 1
#define CD_DEFAULT 2
#define CD_REFERENCE 3
#define CD_DUPLICATE 4

/* BMesh mask includes all standard mesh layers */
#define CD_MASK_BMESH ((1 << CD_NUM) - 1)

#define CD_MASK_MDEFORMVERT (1 << CD_MDEFORMVERT)
#define CD_MASK_MTFACE ((CD_MASK_BMESH) & (1 << CD_MTFACE))
#define CD_MASK_MEDGE ((CD_MASK_BMESH) & (1 << CD_MEDGE))
#define CD_MASK_ORIGINDEX (1 << CD_ORIGINDEX)
#define CD_MASK_DERIVEDMESH (((CustomDataMask)1 << CD_NUM) - 1)


/* Special index value for original indices */
#define ORIGINDEX_NONE -1

typedef void (*CDInterpFunction)(const void **sources, const float *weights, void *dest, int count);
typedef void (*CDEqualsFunction)(const void *a, const void *b, int *equal);
typedef int (*CDSizeFunction)(const int type);

int CustomData_get_layer_index(const CustomData *data, int type);
int CustomData_get_layer_index_n(const CustomData *data, int type, int n);
int CustomData_get_n_offset(const CustomData *data, int type, int n);
int CustomData_get_offset(const CustomData *data, int type);
int CustomData_number_of_layers(const CustomData *data, int type);
int CustomData_has_layer(const CustomData *data, int type);
int CustomData_has_interp(const CustomData *data, int type);
bool CustomData_has_math(const CustomData *data);
bool CustomData_layer_has_math(const CustomData *data, int layer_n);
int CustomData_sizeof(int type);
int CustomData_data_equals(int type, const void *data1, const void *data2);

void *CustomData_get_layer(const CustomData *data, int type);
void *CustomData_set_layer(const CustomData *data, int type, void *ptr);
void CustomData_set_layer_name(CustomData *data, int type, int n, const char *name);
void CustomData_set_layer_unique_name(CustomData *data, int index);
void CustomData_add_layer(CustomData *data, int type, int flag, void *layer, int count);
void CustomData_add_layer_named(CustomData *data, int type, int flag, void *layer, int count, const char *name);
bool CustomData_free_layer(CustomData *data, int type, int count, int index);
bool CustomData_free_layer_active(CustomData *data, int type, int count);
void CustomData_free(CustomData *data, int count);
void CustomData_reset(CustomData *data);
void CustomData_copy(const CustomData *source, CustomData *dest, int mask, int flag, int count);
void CustomData_copy_elements(int type, void *dest, const void *src, int count);

void *CustomData_bmesh_get(const CustomData *data, void *block, int type);
void *CustomData_bmesh_get_n(const CustomData *data, void *block, int type, int n);
int CustomData_bmesh_has_free(const CustomData *data);
void CustomData_bmesh_free_block(CustomData *data, void **block);
void CustomData_bmesh_free_block_data(CustomData *data, void *block);
void CustomData_bmesh_set_default(CustomData *data, void **block);
void CustomData_bmesh_set_n(CustomData *data, void *block, int type, int n, const void *source);
void CustomData_bmesh_interp(CustomData *data, void **blocks, const float *weights, float *sub_weights, int count, void *dest);
void CustomData_bmesh_interp_n(CustomData *data, void **blocks, const float *weights, float *sub_weights, int count, void *dest, int n);
void CustomData_bmesh_copy_data(CustomData *source, CustomData *dest, void *src_block, void **dest_block);
void CustomData_bmesh_init_pool(CustomData *data, int totelem, int htype);
void CustomData_from_bmesh_block(CustomData *source, CustomData *dest, void *src_block, void **dest_block);
void CustomData_to_bmesh_block(CustomData *source, CustomData *dest, int src_index, void **dest_block, int alloc);

typedef unsigned long long CustomDataMask;

#define CD_MASK_MESH (CD_TYPE_AS_MASK(CD_MVERT) | CD_TYPE_AS_MASK(CD_MEDGE) | CD_TYPE_AS_MASK(CD_MFACE) | CD_TYPE_AS_MASK(CD_MLOOP) | CD_TYPE_AS_MASK(CD_MPOLY))

#ifdef __cplusplus
}
#endif

#endif
