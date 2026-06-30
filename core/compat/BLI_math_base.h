#ifndef __BLI_MATH_BASE_H__
#define __BLI_MATH_BASE_H__

#include <math.h>
#include <float.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#ifndef M_PI_2
#define M_PI_2 1.57079632679489661923
#endif
#ifndef M_PI_4
#define M_PI_4 0.78539816339744830962
#endif
#ifndef M_SQRT2
#define M_SQRT2 1.41421356237309504880
#endif
#ifndef M_SQRT1_2
#define M_SQRT1_2 0.70710678118654752440
#endif

#define min_ff(a, b) ((a) < (b) ? (a) : (b))
#define max_ff(a, b) ((a) > (b) ? (a) : (b))
#define min_ii(a, b) ((a) < (b) ? (a) : (b))
#define max_ii(a, b) ((a) > (b) ? (a) : (b))
#define clamp_f(val, minv, maxv) (((val) < (minv)) ? (minv) : (((val) > (maxv)) ? (maxv) : (val)))
#define clamp_i(val, minv, maxv) (((val) < (minv)) ? (minv) : (((val) > (maxv)) ? (maxv) : (val)))

#define signum_i(val) ((val) > 0 ? 1 : ((val) < 0 ? -1 : 0))
#define signum_f(val) ((val) > 0.0f ? 1.0f : ((val) < 0.0f ? -1.0f : 0.0f))

#define square_f(a) ((a) * (a))
#define lerp_f(a, b, t) ((a) + ((b) - (a)) * (t))

#ifdef __cplusplus

#include <algorithm>
#include <cmath>

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

#endif  /* __cplusplus */

#endif
