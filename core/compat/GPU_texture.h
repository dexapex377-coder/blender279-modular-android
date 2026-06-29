#ifndef __GPU_TEXTURE_H__
#define __GPU_TEXTURE_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GPUTexture GPUTexture;

typedef enum {
    GPU_TEXTURE_1D = 0,
    GPU_TEXTURE_2D = 1,
    GPU_TEXTURE_3D = 2,
    GPU_TEXTURE_CUBE = 3,
    GPU_TEXTURE_ARRAY = 4,
} eGPUTextureType;

GPUTexture *GPU_texture_create_1D(int w, int channels, const float *pixels);
GPUTexture *GPU_texture_create_2D(int w, int h, int channels, const float *pixels);
GPUTexture *GPU_texture_create_3D(int w, int h, int d, int channels, const float *pixels);
GPUTexture *GPU_texture_create_cube(int w, int channels, const float *pixels);
GPUTexture *GPU_texture_create_from_image(struct Image *image);
void GPU_texture_free(GPUTexture *tex);
void GPU_texture_bind(GPUTexture *tex, int unit);
void GPU_texture_unbind(GPUTexture *tex);
int GPU_texture_width(GPUTexture *tex);
int GPU_texture_height(GPUTexture *tex);
int GPU_texture_depth(GPUTexture *tex);
int GPU_texture_channels(GPUTexture *tex);
void GPU_texture_filter_set(GPUTexture *tex, int filter);
void GPU_texture_wrap_set(GPUTexture *tex, int wrap);
void GPU_texture_compare_mode(GPUTexture *tex, int mode);

#ifdef __cplusplus
}
#endif

#endif
