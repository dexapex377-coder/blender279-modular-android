#ifndef __GPU_CAPABILITIES_H__
#define __GPU_CAPABILITIES_H__

#ifdef __cplusplus
extern "C" {
#endif

int GPU_max_samplers(void);
int GPU_max_texture_size(void);
int GPU_max_texture_layers(void);
int GPU_max_texture_3d_size(void);
int GPU_max_texture_cube_size(void);
int GPU_max_ubo_binds(void);
int GPU_max_ubo_size(void);
int GPU_max_ssbo_binds(void);
int GPU_max_combined_texture_image_units(void);
int GPU_mip_render_workaround(void);
int GPU_depth_blitting_workaround(void);
int GPU_clear_viewport_workaround(void);

#ifdef __cplusplus
}
#endif

#endif
