#include "BLE_core_math.h"
#include "BLE_types.h"
#include <math.h>
#include <string.h>

static void vec3_add(BLE_Vec3 *r, const BLE_Vec3 *a, const BLE_Vec3 *b) {
    r->x = a->x + b->x;
    r->y = a->y + b->y;
    r->z = a->z + b->z;
}

static void vec3_sub(BLE_Vec3 *r, const BLE_Vec3 *a, const BLE_Vec3 *b) {
    r->x = a->x - b->x;
    r->y = a->y - b->y;
    r->z = a->z - b->z;
}

static void vec3_mul(BLE_Vec3 *r, const BLE_Vec3 *a, f32 s) {
    r->x = a->x * s;
    r->y = a->y * s;
    r->z = a->z * s;
}

static void vec3_div(BLE_Vec3 *r, const BLE_Vec3 *a, f32 s) {
    r->x = a->x / s;
    r->y = a->y / s;
    r->z = a->z / s;
}

static f32 vec3_dot(const BLE_Vec3 *a, const BLE_Vec3 *b) {
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

static void vec3_cross(BLE_Vec3 *r, const BLE_Vec3 *a, const BLE_Vec3 *b) {
    r->x = a->y * b->z - a->z * b->y;
    r->y = a->z * b->x - a->x * b->z;
    r->z = a->x * b->y - a->y * b->x;
}

static f32 vec3_len(const BLE_Vec3 *a) {
    return sqrtf(a->x * a->x + a->y * a->y + a->z * a->z);
}

static void vec3_norm(BLE_Vec3 *r, const BLE_Vec3 *a) {
    f32 len = vec3_len(a);
    if (len > 0.0f) {
        r->x = a->x / len;
        r->y = a->y / len;
        r->z = a->z / len;
    } else {
        r->x = r->y = r->z = 0.0f;
    }
}

static void mat4_mul(BLE_Mat4 *r, const BLE_Mat4 *a, const BLE_Mat4 *b) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            r->m[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                r->m[i][j] += a->m[i][k] * b->m[k][j];
            }
        }
    }
}

static void mat4_mul_vec3(BLE_Vec3 *r, const BLE_Mat4 *m, const BLE_Vec3 *v) {
    r->x = m->m[0][0] * v->x + m->m[0][1] * v->y + m->m[0][2] * v->z + m->m[0][3];
    r->y = m->m[1][0] * v->x + m->m[1][1] * v->y + m->m[1][2] * v->z + m->m[1][3];
    r->z = m->m[2][0] * v->x + m->m[2][1] * v->y + m->m[2][2] * v->z + m->m[2][3];
}

static void mat4_invert(BLE_Mat4 *r, const BLE_Mat4 *m) {
    BLE_Mat4 tmp = *m;
    BLE_Mat4 inv;
    memset(&inv, 0, sizeof(BLE_Mat4));
    for (int i = 0; i < 4; i++) inv.m[i][i] = 1.0f;

    for (int i = 0; i < 4; i++) {
        int pivot = i;
        for (int j = i + 1; j < 4; j++) {
            if (fabsf(tmp.m[j][i]) > fabsf(tmp.m[pivot][i])) pivot = j;
        }
        if (fabsf(tmp.m[pivot][i]) < 1e-6f) { *r = inv; return; }
        if (pivot != i) {
            for (int k = 0; k < 4; k++) {
                f32 t = tmp.m[i][k]; tmp.m[i][k] = tmp.m[pivot][k]; tmp.m[pivot][k] = t;
                t = inv.m[i][k]; inv.m[i][k] = inv.m[pivot][k]; inv.m[pivot][k] = t;
            }
        }
        f32 div = tmp.m[i][i];
        for (int k = 0; k < 4; k++) { tmp.m[i][k] /= div; inv.m[i][k] /= div; }
        for (int j = 0; j < 4; j++) {
            if (j == i) continue;
            f32 mul = tmp.m[j][i];
            for (int k = 0; k < 4; k++) {
                tmp.m[j][k] -= mul * tmp.m[i][k];
                inv.m[j][k] -= mul * inv.m[i][k];
            }
        }
    }
    *r = inv;
}

static void quat_mul(BLE_Quat *r, const BLE_Quat *a, const BLE_Quat *b) {
    r->w = a->w * b->w - a->x * b->x - a->y * b->y - a->z * b->z;
    r->x = a->w * b->x + a->x * b->w + a->y * b->z - a->z * b->y;
    r->y = a->w * b->y - a->x * b->z + a->y * b->w + a->z * b->x;
    r->z = a->w * b->z + a->x * b->y - a->y * b->x + a->z * b->w;
}

static void quat_slerp(BLE_Quat *r, const BLE_Quat *a, const BLE_Quat *b, f32 t) {
    f32 dot = a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
    BLE_Quat b2 = *b;
    if (dot < 0.0f) { dot = -dot; b2.x = -b2.x; b2.y = -b2.y; b2.z = -b2.z; b2.w = -b2.w; }
    if (dot > 0.9995f) {
        r->x = a->x + t * (b2.x - a->x);
        r->y = a->y + t * (b2.y - a->y);
        r->z = a->z + t * (b2.z - a->z);
        r->w = a->w + t * (b2.w - a->w);
        f32 len = sqrtf(r->x * r->x + r->y * r->y + r->z * r->z + r->w * r->w);
        r->x /= len; r->y /= len; r->z /= len; r->w /= len;
        return;
    }
    f32 theta = acosf(dot);
    f32 sin_theta = sinf(theta);
    f32 s1 = sinf((1.0f - t) * theta) / sin_theta;
    f32 s2 = sinf(t * theta) / sin_theta;
    r->x = s1 * a->x + s2 * b2.x;
    r->y = s1 * a->y + s2 * b2.y;
    r->z = s1 * a->z + s2 * b2.z;
    r->w = s1 * a->w + s2 * b2.w;
}

static BLE_MathAPI math_api = {
    .vec3_add = vec3_add,
    .vec3_sub = vec3_sub,
    .vec3_mul = vec3_mul,
    .vec3_div = vec3_div,
    .vec3_dot = vec3_dot,
    .vec3_cross = vec3_cross,
    .vec3_len = vec3_len,
    .vec3_norm = vec3_norm,
    .mat4_mul = mat4_mul,
    .mat4_mul_vec3 = mat4_mul_vec3,
    .mat4_invert = mat4_invert,
    .quat_mul = quat_mul,
    .quat_slerp = quat_slerp,
};

BLE_MathAPI *BLE_math_api_get(void) { return &math_api; }
void BLE_math_init(void) {}
void BLE_math_shutdown(void) {}