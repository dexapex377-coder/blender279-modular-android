#ifndef __ATOMIC_OPS_H__
#define __ATOMIC_OPS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define atomic_add_and_fetch_uint32(p, x) __sync_add_and_fetch(p, x)
#define atomic_sub_and_fetch_uint32(p, x) __sync_sub_and_fetch(p, x)
#define atomic_fetch_and_add_uint32(p, x) __sync_fetch_and_add(p, x)
#define atomic_fetch_and_sub_uint32(p, x) __sync_fetch_and_sub(p, x)
#define atomic_cas_uint32(p, oldv, newv)  __sync_val_compare_and_swap(p, oldv, newv)

#define atomic_add_int32(p, x)            __sync_fetch_and_add(p, x)
#define atomic_sub_int32(p, x)            __sync_fetch_and_sub(p, x)
#define atomic_add_and_fetch_int32(p, x)  __sync_add_and_fetch(p, x)
#define atomic_sub_and_fetch_int32(p, x)  __sync_sub_and_fetch(p, x)
#define atomic_fetch_and_add_int32(p, x)  __sync_fetch_and_add(p, x)
#define atomic_fetch_and_sub_int32(p, x)  __sync_fetch_and_sub(p, x)
#define atomic_cas_int32(p, oldv, newv)   __sync_val_compare_and_swap(p, oldv, newv)

#define atomic_add_and_fetch_uint64(p, x) __sync_add_and_fetch(p, x)
#define atomic_sub_and_fetch_uint64(p, x) __sync_sub_and_fetch(p, x)
#define atomic_fetch_and_add_uint64(p, x) __sync_fetch_and_add(p, x)
#define atomic_fetch_and_sub_uint64(p, x) __sync_fetch_and_sub(p, x)
#define atomic_cas_uint64(p, oldv, newv)  __sync_val_compare_and_swap(p, oldv, newv)

#define atomic_fetch_and_or_uint32(p, x)  __sync_fetch_and_or(p, x)
#define atomic_fetch_and_and_uint32(p, x) __sync_fetch_and_and(p, x)

#ifdef __cplusplus
}
#endif

#endif
