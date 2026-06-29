#ifndef __GPU_STATE_H__
#define __GPU_STATE_H__

#ifdef __cplusplus
extern "C" {
#endif

void GPU_depth_mask(int enable);
void GPU_depth_test(int enable);
void GPU_blend(int enable);
void GPU_blend_func(int sfactor, int dfactor);
void GPU_cull(int enable);
void GPU_cull_front(void);
void GPU_cull_back(void);
void GPU_front_facing(int enable);
void GPU_line_width(float width);
void GPU_point_size(float size);
void GPU_color_mask(int r, int g, int b, int a);
void GPU_stencil_mask(int mask);
void GPU_stencil_op(int fail, int zfail, int zpass);
void GPU_stencil_func(int func, int ref, int mask);
void GPU_stencil_clear(void);
void GPU_viewport(int x, int y, int w, int h);
void GPU_scissor(int x, int y, int w, int h);
void GPU_scissor_test(int enable);
void GPU_enable_alpha_test(void);
void GPU_disable_alpha_test(void);
void GPU_state_copy(void);
void GPU_state_restore(void);
void GPU_apply_state(void);

#ifdef __cplusplus
}
#endif

#endif
