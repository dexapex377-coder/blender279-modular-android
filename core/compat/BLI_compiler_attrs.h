#ifndef __BLI_COMPILER_ATTRS_H__
#define __BLI_COMPILER_ATTRS_H__

#define BLI_INLINE static inline

/* Compiler attributes/macros used by Blender 2.79 */
#if defined(__GNUC__) || defined(__clang__)
#  define ATTR_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#  define ATTR_NONNULL(...)       __attribute__((nonnull(__VA_ARGS__)))
#  define ATTR_NONNULL_ALL        __attribute__((nonnull))
#  define ATTR_NONNULL_TOT        __attribute__((nonnull))
#  define ATTR_UNUSED             __attribute__((unused))
#  define ATTR_RETURNS_TWICE      __attribute__((returns_twice))
#  define ATTR_FALLTHROUGH        __attribute__((fallthrough))
#  define ATTR_NO_OPT             __attribute__((optimize("O0")))
#  define ATTR_PRINTF_FORMAT(a, b) __attribute__((format(printf, a, b)))
#else
#  define ATTR_WARN_UNUSED_RESULT
#  define ATTR_NONNULL(...)
#  define ATTR_NONNULL_ALL
#  define ATTR_NONNULL_TOT(...)
#  define ATTR_UNUSED
#  define ATTR_RETURNS_TWICE
#  define ATTR_FALLTHROUGH
#  define ATTR_NO_OPT
#  define ATTR_PRINTF_FORMAT(a, b)
#endif

/* Use for bounds checking */
#ifdef __GNUC__
#  define CHECK_TYPE(var, type)  { const typeof(var) *__tmp __attribute__((unused)) = NULL; (void)__tmp; }
#  define CHECK_TYPE_PAIR(var_a, var_b) \
    { const typeof(var_a) *__tmp __attribute__((unused)) = NULL; \
      const typeof(var_b) *__tmp2 __attribute__((unused)) = NULL; (void)__tmp; (void)__tmp2; }
#  define CHECK_TYPE_NONCONST(var) \
    { typeof(var) *__tmp __attribute__((unused)) = NULL; (void)__tmp; }
#else
#  define CHECK_TYPE(var, type)
#  define CHECK_TYPE_PAIR(var_a, var_b)
#  define CHECK_TYPE_NONCONST(var)
#endif

#ifndef LIKELY
#ifdef __GNUC__
#define LIKELY(x)   __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#define LIKELY(x)   (x)
#define UNLIKELY(x) (x)
#endif
#endif

#endif
