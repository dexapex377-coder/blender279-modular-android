#ifndef __GPU_FRAMEBUFFER_H__
#define __GPU_FRAMEBUFFER_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GPUFrameBuffer GPUFrameBuffer;
typedef struct GPUTexture GPUTexture;
typedef struct GPUOffScreen GPUOffScreen;

GPUFrameBuffer *GPU_framebuffer_create(const char *name);
void GPU_framebuffer_free(GPUFrameBuffer *fb);
void GPU_framebuffer_bind(GPUFrameBuffer *fb);
void GPU_framebuffer_restore(void);
int GPU_framebuffer_check_valid(GPUFrameBuffer *fb);
void GPU_framebuffer_texture_attach(GPUFrameBuffer *fb, GPUTexture *tex, int slot, int mip);
void GPU_framebuffer_texture_detach(GPUFrameBuffer *fb, GPUTexture *tex);

#ifdef __cplusplus
}
#endif

#endif
