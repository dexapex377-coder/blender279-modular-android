#ifndef __GPU_VERTEX_FORMAT_H__
#define __GPU_VERTEX_FORMAT_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GPUVertFormat GPUVertFormat;

typedef enum {
    GPU_COMP_F32 = 0,
    GPU_COMP_I32 = 1,
    GPU_COMP_U32 = 2,
    GPU_COMP_U8 = 3,
    GPU_COMP_U16 = 4,
    GPU_COMP_I8 = 5,
    GPU_COMP_I16 = 6,
    GPU_COMP_U10 = 7,
} GPUVertComponentType;

typedef enum {
    GPU_FETCH_FLOAT = 0,
    GPU_FETCH_INT = 1,
    GPU_FETCH_UINT = 2,
} GPUVertFetchMode;

int GPU_vertformat_attr_add(GPUVertFormat *format, const char *name, int comp_type, int comp_count, int fetch_mode);
void GPU_vertformat_clear(GPUVertFormat *format);
int GPU_vertformat_attr_id_get(const GPUVertFormat *format, const char *name);

#ifdef __cplusplus
}
#endif

#endif
