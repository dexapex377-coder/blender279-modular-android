#ifndef __GPU_PRIMITIVE_H__
#define __GPU_PRIMITIVE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    GPU_PRIM_POINTS = 0,
    GPU_PRIM_LINES = 1,
    GPU_PRIM_LINE_STRIP = 2,
    GPU_PRIM_LINE_LOOP = 3,
    GPU_PRIM_TRIS = 4,
    GPU_PRIM_TRI_STRIP = 5,
    GPU_PRIM_TRI_FAN = 6,
    GPU_PRIM_LINES_ADJ = 7,
    GPU_PRIM_TRIS_ADJ = 8,
} GPUPrimType;

#ifdef __cplusplus
}
#endif

#endif
