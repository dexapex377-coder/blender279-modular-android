#ifndef __GPU_VIEWPORT_H__
#define __GPU_VIEWPORT_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GPUViewport GPUViewport;

GPUViewport *GPU_viewport_create(void);
void GPU_viewport_free(GPUViewport *vp);
void GPU_viewport_bind(GPUViewport *vp, int view);
void GPU_viewport_unbind(GPUViewport *vp);
int GPU_viewport_size_get(GPUViewport *vp, int *r_size);

#ifdef __cplusplus
}
#endif

#endif
