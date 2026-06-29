#ifndef __GPU_MATRIX_H__
#define __GPU_MATRIX_H__

#ifdef __cplusplus
extern "C" {
#endif

void GPU_matrix_mode(int mode);
void GPU_matrix_push(void);
void GPU_matrix_pop(void);
void GPU_matrix_identity_set(void);
void GPU_matrix_scale_1f(float factor);
void GPU_matrix_translate_3f(float x, float y, float z);
void GPU_matrix_rotate_2d(float angle);
void GPU_matrix_rotate_3f(float angle, float x, float y, float z);
void GPU_matrix_mult_matrix(const float m[4][4]);
void GPU_matrix_get(float m[4][4]);
void GPU_matrix_set(const float m[4][4]);
void GPU_matrix_ortho_set(float left, float right, float bottom, float top, float near, float far);
void GPU_matrix_perspective_set(float fovy, float aspect, float near, float far);
void GPU_matrix_look_at(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);
void GPU_matrix_projection_get(float m[4][4]);
void GPU_matrix_model_view_get(float m[4][4]);
void GPU_matrix_normal_get(float m[3][3]);

#ifdef __cplusplus
}
#endif

#endif
