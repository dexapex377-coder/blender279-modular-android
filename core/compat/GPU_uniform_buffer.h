#ifndef __GPU_UNIFORM_BUFFER_H__
#define __GPU_UNIFORM_BUFFER_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GPUUniformBuf GPUUniformBuf;

GPUUniformBuf *GPU_uniformbuf_create(int size, const void *data);
void GPU_uniformbuf_free(GPUUniformBuf *ubo);
void GPU_uniformbuf_bind(GPUUniformBuf *ubo, int binding);
void GPU_uniformbuf_unbind(GPUUniformBuf *ubo);
void GPU_uniformbuf_update(GPUUniformBuf *ubo, const void *data);
void GPU_uniformbuf_bind_as_texture(GPUUniformBuf *ubo, int binding);

#ifdef __cplusplus
}
#endif

#endif
