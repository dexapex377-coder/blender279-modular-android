#ifndef BLE_TYPES_H
#define BLE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef float f32;
typedef double f64;
typedef uintptr_t usize;
typedef intptr_t isize;

typedef struct BLE_Vec2 { f32 x, y; } BLE_Vec2;
typedef struct BLE_Vec3 { f32 x, y, z; } BLE_Vec3;
typedef struct BLE_Vec4 { f32 x, y, z, w; } BLE_Vec4;
typedef struct BLE_Mat3 { f32 m[3][3]; } BLE_Mat3;
typedef struct BLE_Mat4 { f32 m[4][4]; } BLE_Mat4;
typedef struct BLE_Quat { f32 x, y, z, w; } BLE_Quat;

typedef struct BLE_Bounds2 { BLE_Vec2 min, max; } BLE_Bounds2;
typedef struct BLE_Bounds3 { BLE_Vec3 min, max; } BLE_Bounds3;

typedef struct BLE_ColorRGB { f32 r, g, b; } BLE_ColorRGB;
typedef struct BLE_ColorRGBA { f32 r, g, b, a; } BLE_ColorRGBA;

typedef void (*BLE_FreeFunc)(void *ptr);
typedef void *(*BLE_AllocFunc)(size_t size);
typedef void *(*BLE_ReallocFunc)(void *ptr, size_t size);

typedef struct BLE_MemoryAPI {
    BLE_AllocFunc alloc;
    BLE_ReallocFunc realloc;
    BLE_FreeFunc free;
    void *(*alloc_aligned)(size_t size, size_t alignment);
    void *(*realloc_aligned)(void *ptr, size_t size, size_t alignment);
    void (*free_aligned)(void *ptr);
} BLE_MemoryAPI;

typedef struct BLE_MathAPI {
    void (*vec3_add)(BLE_Vec3 *r, const BLE_Vec3 *a, const BLE_Vec3 *b);
    void (*vec3_sub)(BLE_Vec3 *r, const BLE_Vec3 *a, const BLE_Vec3 *b);
    void (*vec3_mul)(BLE_Vec3 *r, const BLE_Vec3 *a, f32 s);
    void (*vec3_div)(BLE_Vec3 *r, const BLE_Vec3 *a, f32 s);
    f32 (*vec3_dot)(const BLE_Vec3 *a, const BLE_Vec3 *b);
    void (*vec3_cross)(BLE_Vec3 *r, const BLE_Vec3 *a, const BLE_Vec3 *b);
    f32 (*vec3_len)(const BLE_Vec3 *a);
    void (*vec3_norm)(BLE_Vec3 *r, const BLE_Vec3 *a);
    void (*mat4_mul)(BLE_Mat4 *r, const BLE_Mat4 *a, const BLE_Mat4 *b);
    void (*mat4_mul_vec3)(BLE_Vec3 *r, const BLE_Mat4 *m, const BLE_Vec3 *v);
    void (*mat4_invert)(BLE_Mat4 *r, const BLE_Mat4 *m);
    void (*quat_mul)(BLE_Quat *r, const BLE_Quat *a, const BLE_Quat *b);
    void (*quat_slerp)(BLE_Quat *r, const BLE_Quat *a, const BLE_Quat *b, f32 t);
} BLE_MathAPI;

typedef struct BLE_DNA_Type BLE_DNA_Type;
typedef struct BLE_DNA_Struct BLE_DNA_Struct;

typedef struct BLE_CoreAPI {
    BLE_MemoryAPI *mem;
    BLE_MathAPI *math;
    struct BLE_DNA_API *dna;
    void *guardedalloc;
} BLE_CoreAPI;

#ifdef __cplusplus
}
#endif

#endif