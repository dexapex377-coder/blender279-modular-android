#ifndef __GPU_VERTEX_BUFFER_H__
#define __GPU_VERTEX_BUFFER_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GPUVertBuf GPUVertBuf;

GPUVertBuf *GPU_vertbuf_create(int format_len);
void GPU_vertbuf_discard(GPUVertBuf *buf);
void GPU_vertbuf_init(GPUVertBuf *buf, int format_len);
void GPU_vertbuf_data_alloc(GPUVertBuf *buf, int vertex_len);
void GPU_vertbuf_attr_fill(GPUVertBuf *buf, int attr_id, const void *data);
void GPU_vertbuf_attr_set(GPUVertBuf *buf, int attr_id, int vertex, const void *data);
void GPU_vertbuf_attr_get(const GPUVertBuf *buf, int attr_id, int vertex, void *data);
void *GPU_vertbuf_attr_get_raw(GPUVertBuf *buf, int attr_id, int vertex);
void GPU_vertbuf_upload(GPUVertBuf *buf);
void GPU_vertbuf_bind(GPUVertBuf *buf);
int GPU_vertbuf_vertex_count(GPUVertBuf *buf);
int GPU_vertbuf_vertex_stride(GPUVertBuf *buf);
void GPU_vertbuf_attr_set_safe(GPUVertBuf *buf, int attr_id, int vertex, const void *data);

#ifdef __cplusplus
}
#endif

#endif
