#ifndef __GPU_BATCH_H__
#define __GPU_BATCH_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GPUBatch GPUBatch;
typedef struct GPUIndexBuf GPUIndexBuf;
typedef struct GPUVertBuf GPUVertBuf;

GPUBatch *GPU_batch_create(int primitive_type, GPUVertBuf *verts, GPUIndexBuf *indices);
GPUBatch *GPU_batch_init(GPUBatch *batch, int primitive_type, GPUVertBuf *verts, GPUIndexBuf *indices);
void GPU_batch_copy(GPUBatch *batch, GPUBatch *source);
void GPU_batch_discard(GPUBatch *batch);
void GPU_batch_draw(GPUBatch *batch);
void GPU_batch_draw_range(GPUBatch *batch, int start, int count);
void GPU_batch_set_type(GPUBatch *batch, int type);
void GPU_batch_vertbuf_add(GPUBatch *batch, GPUVertBuf *verts, int own);

#ifdef __cplusplus
}
#endif

#endif
