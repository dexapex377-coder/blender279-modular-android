#ifndef __BLI_UTILDEFINES_H__
#define __BLI_UTILDEFINES_H__

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "BLI_compiler_attrs.h"
#include "BLI_sys_types.h"

/* Math macros */
#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif
#ifndef ABS
#define ABS(a) ((a) < 0 ? -(a) : (a))
#endif

#define CLAMPIS(a, b, c) ((a) < (b) ? (b) : (a) > (c) ? (c) : (a))
#define CLAMP(a, b, c) { if ((a) < (b)) (a) = (b); else if ((a) > (c)) (a) = (c); } (void)0
#define CLAMP_MAX(a, c) { if ((a) > (c)) (a) = (c); } (void)0
#define CLAMP_MIN(a, b) { if ((a) < (b)) (a) = (b); } (void)0

#define IN_RANGE(a, b, c) ((a) >= (b) && (a) <= (c))
#define IN_RANGE_INCL(a, b, c) IN_RANGE(a, b, c)

#define SWAP(type, a, b) { type swaptmp; swaptmp = (a); (a) = (b); (b) = swaptmp; } (void)0

#define FTOCHAR(val) ((unsigned char)((val) * 255.0f))
#define F3TOCHAR(val1, val2, val3) ((unsigned char)((val1) * 255.0f)), ((unsigned char)((val2) * 255.0f)), ((unsigned char)((val3) * 255.0f))

#define SIGN(a) ((a) > 0.0f ? 1.0f : ((a) < 0.0f ? -1.0f : 0.0f))

#define UNIT_V2_0 1.0f, 0.0f
#define UNIT_V3_0 1.0f, 0.0f, 0.0f
#define UNIT_V4_0 1.0f, 0.0f, 0.0f, 0.0f

#define ZERO_V2 0.0f, 0.0f
#define ZERO_V3 0.0f, 0.0f, 0.0f
#define ZERO_V4 0.0f, 0.0f, 0.0f, 0.0f

/* Compiler macros */
#define UNUSED(x) ((void)(x))
#define UNUSED_VARS(...) ((void)0)

#define CHECK_TYPE(var, type) { typeof(var) *__tmp; __tmp = (type *)NULL; (void)__tmp; } (void)0
#define CHECK_TYPE_PAIR(var_a, var_b) { CHECK_TYPE(var_a, typeof(var_b)); } (void)0
#define CHECK_TYPE_ANY(var, ...) ((void)0)

#define BLI_assert(assertion) assert(assertion)
#define BLI_assert_msg(assertion, msg) assert(assertion)
#define BLI_STATIC_ASSERT(assertion, msg) static_assert(assertion, msg)

#define BLI_assert_unreachable() assert(0)

/* Array helpers */
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(*(arr)))
#define ARRAY_LAST_ITEM(arr) ((arr)[ARRAY_SIZE(arr) - 1])
#define ARRAY_HAS_ITEM(item, arr) (((((unsigned int)(item) - (unsigned int)(arr))) < (unsigned int)(ARRAY_SIZE(arr))))
#define POINTER_OFFSET(ptr, ofs) ((void *)((char *)(ptr) + (ofs)))

#define ELEM(a, ...) ({ \
    const typeof(a) _a = (a); \
    int _result = 0; \
    { const typeof(a) _elems[] = {__VA_ARGS__}; \
      for (int _i = 0; _i < (int)(sizeof(_elems) / sizeof(*_elems)); _i++) { \
          if (_elems[_i] == _a) { _result = 1; break; } } } \
    _result; })

/* Type checking */
#define CHECK_TYPE_INLINE(val, type) ((void)(((type)0) != (val)))
#define CHECK_TYPE_NONCONST(val) ((void)0)

/* Range */
#define RANGE(type, start, end) ((struct{type s, e;}){start, end})

/* String helpers */
#define STRINGIFY(x) #x
#define STRNCPY(dst, src, max) BLI_strncpy(dst, src, max)

/* Misc */
#define INIT_MINMAX(min, max) { \
    (min)[0] = (min)[1] = (min)[2] = 1e30f; \
    (max)[0] = (max)[1] = (max)[2] = -1e30f; \
} (void)0

#define DO_MIN(a, b) { if ((b) < (a)) (a) = (b); } (void)0
#define DO_MAX(a, b) { if ((b) > (a)) (a) = (b); } (void)0

#define DO_MIN_2(a, b, c, d) { DO_MIN(a, b); DO_MIN(c, d); } (void)0
#define DO_MAX_2(a, b, c, d) { DO_MAX(a, b); DO_MAX(c, d); } (void)0

#define IS_TMS_EQUAL(a, b) (memcmp(&(a), &(b), sizeof(a)) == 0)

/* Generic math */
#define M_PI 3.14159265358979323846
#define M_SQRT2 1.41421356237309504880

#ifndef FLT_MAX
#define FLT_MAX 3.402823466e+38F
#endif
#ifndef FLT_EPSILON
#define FLT_EPSILON 1.192092896e-07F
#endif

#define IS_EQ(a, b) ((float)(a) == (float)(b))
#define IS_EQF(a, b) ((a) == (b))
#define IS_EQT(a, b, t) (((a) > (b) ? (a) - (b) : (b) - (a)) <= (t))

/* Sign */
#define signum_i(val) ((val) > 0 ? 1 : ((val) < 0 ? -1 : 0))
#define signum_f(val) ((val) > 0.0f ? 1.0f : ((val) < 0.0f ? -1.0f : 0.0f))

/* Vector compare */
#define IN_RANGE_V2(v, min, max) (IN_RANGE((v)[0], (min)[0], (max)[0]) && IN_RANGE((v)[1], (min)[1], (max)[1]))
#define IN_RANGE_V3(v, min, max) (IN_RANGE((v)[0], (min)[0], (max)[0]) && IN_RANGE((v)[1], (min)[1], (max)[1]) && IN_RANGE((v)[2], (min)[2], (max)[2]))
#define IN_RANGE_V4(v, min, max) (IN_RANGE((v)[0], (min)[0], (max)[0]) && IN_RANGE((v)[1], (min)[1], (max)[1]) && IN_RANGE((v)[2], (min)[2], (max)[2]) && IN_RANGE((v)[3], (min)[3], (max)[3]))

#define CLAMP4(a, b, c) { CLAMP((a)[0], b, c); CLAMP((a)[1], b, c); CLAMP((a)[2], b, c); CLAMP((a)[3], b, c); } (void)0

/* Bit operations */
#define BMELEM_HTYPE_TO_STR(htype) (((htype) == BM_VERT) ? "vert" : ((htype) == BM_EDGE) ? "edge" : ((htype) == BM_LOOP) ? "loop" : ((htype) == BM_FACE) ? "face" : "unknown")

/* Memory */
#define MEM_SAFE_FREE(ptr) do { if (ptr) { MEM_freeN(ptr); (ptr) = NULL; } } while (0)

/* C++ guard */
#ifdef __cplusplus
#define BLI_STRUCT_FORWARD(struct_name) struct struct_name
#else
#define BLI_STRUCT_FORWARD(struct_name) typedef struct struct_name struct_name
#endif

#endif
