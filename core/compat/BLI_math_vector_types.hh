#ifndef __BLI_MATH_VECTOR_TYPES_HH__
#define __BLI_MATH_VECTOR_TYPES_HH__

#include <cstdint>
#include <cmath>

namespace BLI {

struct float2 {
    float x, y;
    float2() : x(0), y(0) {}
    float2(float x_, float y_) : x(x_), y(y_) {}
    explicit float2(const float *v) : x(v[0]), y(v[1]) {}
    float &operator[](int i) { return (&x)[i]; }
    const float &operator[](int i) const { return (&x)[i]; }
};

struct float3 {
    float x, y, z;
    float3() : x(0), y(0), z(0) {}
    float3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
    explicit float3(const float *v) : x(v[0]), y(v[1]), z(v[2]) {}
    explicit float3(const float2 &v, float z_ = 0.0f) : x(v.x), y(v.y), z(z_) {}
    float &operator[](int i) { return (&x)[i]; }
    const float &operator[](int i) const { return (&x)[i]; }

    float3 &operator+=(const float3 &b) { x += b.x; y += b.y; z += b.z; return *this; }
    float3 &operator-=(const float3 &b) { x -= b.x; y -= b.y; z -= b.z; return *this; }
    float3 &operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    float3 &operator/=(float s) { x /= s; y /= s; z /= s; return *this; }
};

struct float4 {
    float x, y, z, w;
    float4() : x(0), y(0), z(0), w(0) {}
    float4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
    explicit float4(const float *v) : x(v[0]), y(v[1]), z(v[2]), w(v[3]) {}
    explicit float4(const float3 &v, float w_ = 0.0f) : x(v.x), y(v.y), z(v.z), w(w_) {}
    float &operator[](int i) { return (&x)[i]; }
    const float &operator[](int i) const { return (&x)[i]; }
};

struct int2 {
    int x, y;
    int2() : x(0), y(0) {}
    int2(int x_, int y_) : x(x_), y(y_) {}
};

struct int3 {
    int x, y, z;
    int3() : x(0), y(0), z(0) {}
    int3(int x_, int y_, int z_) : x(x_), y(y_), z(z_) {}
};

struct int4 {
    int x, y, z, w;
    int4() : x(0), y(0), z(0), w(0) {}
    int4(int x_, int y_, int z_, int w_) : x(x_), y(y_), z(z_), w(w_) {}
};

}  // namespace BLI

#endif
