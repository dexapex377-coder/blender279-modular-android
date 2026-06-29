#ifndef __GPU_CONTEXT_H__
#define __GPU_CONTEXT_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GPUContext GPUContext;

GPUContext *GPU_context_create(void);
void GPU_context_discard(GPUContext *ctx);
void GPU_context_active_set(GPUContext *ctx);
GPUContext *GPU_context_active_get(void);
void GPU_context_begin_frame(GPUContext *ctx);
void GPU_context_end_frame(GPUContext *ctx);

#ifdef __cplusplus
}
#endif

#endif
