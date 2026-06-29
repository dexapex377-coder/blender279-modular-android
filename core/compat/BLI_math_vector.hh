#ifndef __BLI_MATH_VECTOR_HH__
#define __BLI_MATH_VECTOR_HH__

#include "BLI_math_vector_types.hh"
#include <cmath>

namespace BLI {

template<typename T, int Size>
inline float3 operator+(const float3 &a, const float3 &b) {
    return float3(a.x + b.x, a.y + b.y, a.z + b.z);
}
template<typename T, int Size>
inline float3 operator-(const float3 &a, const float3 &b) {
    return float3(a.x - b.x, a.y - b.y, a.z - b.z);
}
template<typename T, int Size>
inline float3 operator*(const float3 &a, float s) {
    return float3(a.x * s, a.y * s, a.z * s);
}
template<typename T, int Size>
inline float3 operator/(const float3 &a, float s) {
    return float3(a.x / s, a.y / s, a.z / s);
}

inline float dot(const float3 &a, const float3 &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
inline float3 cross(const float3 &a, const float3 &b) {
    return float3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}
inline float length(const float3 &a) { return std::sqrt(dot(a, a)); }
inline float length_squared(const float3 &a) { return dot(a, a); }
inline float3 normalize(const float3 &a) {
    float len = length(a);
    return (len > 0.0f) ? a / len : float3(0.0f, 0.0f, 0.0f);
}
inline float3 normalize_and_get_length(const float3 &a, float &len) {
    len = length(a);
    return (len > 0.0f) ? a / len : float3(0.0f, 0.0f, 0.0f);
}
inline float distance(const float3 &a, const float3 &b) { return length(a - b); }
inline float distance_squared(const float3 &a, const float3 &b) { return length_squared(a - b); }
inline float3 interp(const float3 &a, const float3 &b, float t) { return a + (b - a) * t; }
inline float3 mid(const float3 &a, const float3 &b) { return (a + b) * 0.5f; }
inline float3 reflect(const float3 &incident, const float3 &normal) {
    return incident - 2.0f * dot(incident, normal) * normal;
}
inline float3 project(const float3 &v, const float3 &n) {
    return n * (dot(v, n) / dot(n, n));
}

}  // namespace BLI

#endif
