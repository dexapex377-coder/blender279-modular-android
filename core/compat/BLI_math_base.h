#ifndef __BLI_MATH_BASE_H__
#define __BLI_MATH_BASE_H__

#include <cmath>
#include <algorithm>

namespace BLI {

template<typename T> inline T min(const T &a, const T &b) { return std::min(a, b); }
template<typename T> inline T max(const T &a, const T &b) { return std::max(a, b); }
template<typename T> inline T clamp(const T &a, const T &minv, const T &maxv) { return std::max(minv, std::min(maxv, a)); }
template<typename T> inline int sign(const T &a) { return (a > 0) ? 1 : ((a < 0) ? -1 : 0); }
template<typename T> inline T abs(const T &a) { return std::abs(a); }
template<typename T> inline T sq(const T &a) { return a * a; }
template<typename T> inline T lerp(const T &a, const T &b, float t) { return a + (b - a) * t; }

inline float safe_divide(float a, float b) { return (b != 0.0f) ? a / b : 0.0f; }
inline float safe_sqrtf(float f) { return (f > 0.0f) ? std::sqrt(f) : 0.0f; }
inline float safe_logf(float f, float base) { return (f > 0.0f) ? std::log(f) / std::log(base) : 0.0f; }

}  // namespace BLI

#endif
