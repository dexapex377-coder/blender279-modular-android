#ifndef __BLI_MATH_H__
#define __BLI_MATH_H__

#include <math.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define M_PI_2 1.57079632679489661923

#ifndef M_SQRT3
#define M_SQRT3     1.73205080756887729352  /* sqrt(3) */
#endif
#ifndef M_SQRT1_3
#define M_SQRT1_3   0.57735026918962576450  /* 1/sqrt(3) */
#endif

/* Vector math */
void zero_v2(float r[2]);
void zero_v3(float r[3]);
void zero_v4(float r[4]);

void copy_v2_v2(float r[2], const float a[2]);
void copy_v3_v3(float r[3], const float a[3]);
void copy_v4_v4(float r[4], const float a[4]);

void add_v2_v2(float r[2], const float a[2]);
void add_v3_v3(float r[3], const float a[3]);
void add_v4_v4(float r[4], const float a[4]);

void sub_v2_v2(float r[2], const float a[2]);
void sub_v3_v3(float r[3], const float a[3]);
void sub_v4_v4(float r[4], const float a[4]);

void mul_v2_fl(float r[2], float f);
void mul_v3_fl(float r[3], float f);
void mul_v4_fl(float r[4], float f);

void mul_v2_v2(float r[2], const float a[2]);
void mul_v3_v3(float r[3], const float a[3]);
void mul_v4_v4(float r[4], const float a[4]);

void madd_v3_v3fl(float r[3], const float a[3], float f);

float dot_v3v3(const float a[3], const float b[3]);
float dot_v2v2(const float a[2], const float b[2]);

void cross_v3_v3v3(float r[3], const float a[3], const float b[3]);

float len_v3(const float a[3]);
float len_v2(const float a[2]);
float len_squared_v3(const float a[3]);
float len_squared_v2(const float a[2]);

float len_v3v3(const float a[3], const float b[3]);
float len_squared_v3v3(const float a[3], const float b[3]);

float normalize_v3(float r[3]);
float normalize_v2(float r[2]);

int is_zero_v3(const float a[3]);
int is_zero_v2(const float a[2]);

void negate_v3(float r[3]);
void negate_v2(float r[2]);
void negate_v4(float r[4]);

void invert_v3(float r[3]);
void invert_v2(float r[2]);

void interp_v3_v3v3(float r[3], const float a[3], const float b[3], float t);
void interp_v2_v2v2(float r[2], const float a[2], const float b[2], float t);

void mid_v3_v3v3(float r[3], const float a[3], const float b[3]);
void mid_v2_v2v2(float r[2], const float a[2], const float b[2]);

void project_v3_v3v3(float r[3], const float a[3], const float b[3]);

void normal_float_to_short_v3(short r[3], const float n[3]);
void normal_short_to_float_v3(float r[3], const short n[3]);

float angle_v3v3(const float a[3], const float b[3]);
float angle_v2v2(const float a[2], const float b[2]);

void rotate_v3_v3v3(float r[3], const float v[3], const float axis[3]);
void rotate_v2_v2v2(float r[2], const float v[2], const float angle);

void reflect_v3_v3v3(float r[3], const float a[3], const float b[3]);

void normalize_v3_v3(float r[3], const float a[3]);
void normalize_v2_v2(float r[2], const float a[2]);

void cross_v3_v3v3_hi_prec(float r[3], const float a[3], const float b[3]);

float dist_v3v3(const float a[3], const float b[3]);
float dist_squared_v3v3(const float a[3], const float b[3]);
float dist_v2v2(const float a[2], const float b[2]);
float dist_squared_v2v2(const float a[2], const float b[2]);

void swap_v3_v3(float a[3], float b[3]);
void swap_v2_v2(float a[2], float b[2]);

float line_point_side_v2(const float l1[2], const float l2[2], const float pt[2]);

/* Matrix math */
void unit_m3(float m[3][3]);
void unit_m4(float m[4][4]);

void copy_m3_m3(float m1[3][3], const float m2[3][3]);
void copy_m4_m4(float m1[4][4], const float m2[4][4]);

void copy_m3_m4(float m1[3][3], const float m2[4][4]);
void copy_m4_m3(float m1[4][4], const float m2[3][3]);

void zero_m3(float m[3][3]);
void zero_m4(float m[4][4]);

void mul_m4_v3(const float M[4][4], float r[3]);
void mul_m3_v3(const float M[3][3], float r[3]);
void mul_v3_m4v3(float r[3], const float M[4][4], const float v[3]);
void mul_v3_m3v3(float r[3], const float M[3][3], const float v[3]);
void mul_v2_m3v2(float r[2], const float M[3][3], const float v[2]);
void mul_m4_m4m4(float r[4][4], const float a[4][4], const float b[4][4]);
void mul_m3_m3m3(float r[3][3], const float a[3][3], const float b[3][3]);

bool invert_m4_m4(float r[4][4], const float a[4][4]);
void invert_m4(float m[4][4]);
void invert_m3(float m[3][3]);

int invert_m4_m4_safe(float r[4][4], const float a[4][4]);

void transpose_m3(float m[3][3]);
void transpose_m4(float m[4][4]);

void orthogonalize_m3(float m[3][3], int axis);
void orthogonalize_m4(float m[4][4], int axis);

void normalize_m3(float m[3][3]);
void normalize_m3_ex(float m[3][3], float r_scale[3]);

void adjugate_m4_m4(float r[4][4], const float a[4][4]);

void cross_m3_v3(float r[3][3], const float v[3]);

void mul_m3_m3v3(float r[3], const float m[3][3], const float v[3]);
void mul_m4_m4v3(float r[3], const float m[4][4], const float v[3]);

void translate_m4(float m[4][4], float x, float y, float z);
void rotate_m4(float m[4][4], char axis, float angle);
void scale_m4(float m[4][4], float x, float y, float z);
void loc_to_mat4(float M[4][4], const float loc[3]);

void size_to_mat4(float M[4][4], const float size[3]);
void mat4_to_size(float size[3], const float M[4][4]);
void mat4_to_loc(float loc[3], const float M[4][4]);
void mat4_to_quat(float quat[4], const float M[4][4]);
void quat_to_mat4(float M[4][4], const float quat[4]);

/* Quaternion */
void unit_qt(float q[4]);
void copy_qt_qt(float q[4], const float r[4]);
void mul_qt_qtqt(float q[4], const float q1[4], const float q2[4]);
void mul_qt_v3(const float q[4], float r[3]);
void mul_v3_qt_v3(float r[3], const float q[4], const float v[3]);
void invert_qt(float q[4]);
void conjugate_qt(float q[4]);
float dot_qtqt(const float q1[4], const float q2[4]);
float normalize_qt(float q[4]);
int is_zero_qt(const float q[4]);
void quat_to_eul(float eul[3], const float quat[4]);
void eul_to_quat(float quat[4], const float eul[3]);

/* Interpolation */
float lerp(float a, float b, float t);
float clampf(float val, float min, float max);
int clampi(int val, int min, int max);

/* Colors */
void srgb_to_linearrgb(float r[3], const float srgb[3]);
void linearrgb_to_srgb(float r[3], const float srgb[3]);
void srgb_to_linearrgb_v4(float r[4], const float srgb[4]);
void linearrgb_to_srgb_v4(float r[4], const float srgb[4]);

/* Planar */
int isect_line_line_v2(const float p1[2], const float p2[2], const float p3[2], const float p4[2]);
int isect_line_line_v2_int(const int p1[2], const int p2[2], const int p3[2], const int p4[2]);

/* ISECT_LINE_LINE return values */
#define ISECT_LINE_LINE_COLINEAR    -1
#define ISECT_LINE_LINE_NONE         0
#define ISECT_LINE_LINE_EXACT        1
#define ISECT_LINE_LINE_CROSS        2

int isect_line_sphere_v3(const float p1[3], const float p2[3], const float sp[3], float r, float *r_p1, float *r_p2);
int isect_ray_plane_v3(const float p1[3], const float d[3], const float plane[4], float *lambda, float r_isect[3]);
int isect_ray_tri_epsilon_v3(const float p[3], const float d[3], const float v0[3], const float v1[3], const float v2[3], float *r_lambda, float r_uv[2], const float epsilon);
int isect_line_plane_v3(float r[3], const float l1[3], const float l2[3], const float plane_co[3], const float plane_no[3]);

/* Random */

int BLI_rand(void);
float BLI_frand(void);

/* Triangle */
float area_tri_v3(const float v1[3], const float v2[3], const float v3[3]);
float area_tri_v2(const float v1[2], const float v2[2], const float v3[2]);
float area_poly_v3(const float (*verts)[3], int nr);
int barycentric_weights_v2(const float v1[2], const float v2[2], const float v3[2], const float co[2], float w[3]);
int barycentric_weights_v3(const float v1[3], const float v2[3], const float v3[3], const float co[3], float w[3]);
float dist_to_plane_v3(const float p[3], const float plane[4]);
float dist_squared_to_plane_v3(const float p[3], const float plane[4]);
void plane_from_point_normal_v3(float r_plane[4], const float plane_co[3], const float plane_no[3]);

/* Small number comparisons */
int compare_v2v2(const float a[2], const float b[2], float limit);
int compare_v3v3(const float a[3], const float b[3], float limit);
int compare_ff(float a, float b, float limit);

float floor_pow10(float f);
float ceil_pow10(float f);

void pow_v3_v3(float r[3], const float a[3]);
void pow_v4_v4(float r[4], const float a[4]);

void mat3_to_rot_size(float rot[3][3], float size[3], const float mat3[3][3]);

/* Euler */
void eul_to_mat3(float M[3][3], const float eul[3]);
void eul_to_mat4(float M[4][4], const float eul[3]);
void mat3_to_eul(float eul[3], const float M[3][3]);
void mat4_to_eul(float eul[3], const float M[4][4]);

void eulO_to_quat(float q[4], const float eul[3], const char order);
void eulO_to_mat4(float M[4][4], const float eul[3], const char order);
void mat4_to_eulO(float eul[3], const char order, const float M[4][4]);

/* Axis angle */
void axis_angle_to_quat(float q[4], const float axis[3], float angle);
void axis_angle_to_mat3(float M[3][3], const float axis[3], float angle);
void quat_to_axis_angle(float axis[3], float *angle, const float q[4]);
void mat3_to_axis_angle(float axis[3], float *angle, const float M[3][3]);

/* Box */
int isect_aabb_aabb_v3(const float min1[3], const float max1[3], const float min2[3], const float max2[3]);
int isect_aabb_aabb_plane(const float min[3], const float max[3], const float plane[4]);
int isect_point_aabb_v3(const float p[3], const float min[3], const float max[3]);
int isect_point_plane_v3(const float p[3], const float plane[4]);

/* Geometry utils */
void dist_ensure_v3_v3fl(float r[3], const float p[3], float d);
void closest_to_line_v2(float r[2], const float p[2], const float l1[2], const float l2[2]);
void closest_to_line_segment_v2(float r[2], const float p[2], const float l1[2], const float l2[2]);
void closest_to_line_v3(float r[3], const float p[3], const float l1[3], const float l2[3]);
void closest_to_line_segment_v3(float r[3], const float p[3], const float l1[3], const float l2[3]);
float closest_to_line_v2_fallback(float r[2], const float p[2], const float l1[2], const float l2[2]);
float dist_to_line_segment_v2(const float p[2], const float l1[2], const float l2[2]);
float dist_to_line_segment_v3(const float p[3], const float l1[3], const float l2[3]);
float dist_to_line_v3(const float p[3], const float l1[3], const float l2[3]);
float dist_to_line_v2(const float p[2], const float l1[2], const float l2[2]);
void project_v2_v2v2(float r[2], const float v[2], const float vn[2]);
void project_v3_v3v3(float r[3], const float v[3], const float vn[3]);

/* Smoothing */
void blur_interp_v3(float r[3], const float a[3], float t, int falloff);

#ifndef BLI_ASSERT_UNIT_V2
#define BLI_ASSERT_UNIT_V2(v) (void)0
#define BLI_ASSERT_UNIT_V3(v) (void)0
#endif
#ifndef BLI_FOREACH_SPARSE_RANGE
/* Simplified sparse range: iterates tot times, i takes values 0..range-1 */
#define BLI_FOREACH_SPARSE_RANGE(range, tot, i) \
    for (int _sparse_idx_ = 0, i = 0; _sparse_idx_ < (tot); _sparse_idx_++, i = (int)((float)(range) * (float)_sparse_idx_ / (float)(tot)))
#endif

/* Map range */
float map_range(float val, float src_min, float src_max, float dst_min, float dst_max);

/* Volume utils */
float volume_tetrahedron_v3(const float v1[3], const float v2[3], const float v3[3], const float v4[3]);

/* Cyclic */
void rotate_point_around_axis_v3(float r[3], const float p[3], const float axis[3], float angle);

#ifdef __cplusplus
}
#endif

#endif
