#ifndef __GPU_INDEX_BUFFER_H__
#define __GPU_INDEX_BUFFER_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GPUIndexBuf GPUIndexBuf;

GPUIndexBuf *GPU_indexbuf_create(int index_type);
void GPU_indexbuf_discard(GPUIndexBuf *buf);
void GPU_indexbuf_init(GPUIndexBuf *buf, int index_type, int vertex_len, int index_len);
void GPU_indexbuf_add_tri_verts(GPUIndexBuf *buf, int v1, int v2, int v3);
void GPU_indexbuf_add_line_verts(GPUIndexBuf *buf, int v1, int v2);
void GPU_indexbuf_upload(GPUIndexBuf *buf);
int GPU_indexbuf_index_len(GPUIndexBuf *buf);
int GPU_indexbuf_primitive_len(GPUIndexBuf *buf);
void GPU_indexbuf_bind(GPUIndexBuf *buf);

#ifdef __cplusplus
}
#endif

#endif
