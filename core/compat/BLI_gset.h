#ifndef __BLI_GSET_H__
#define __BLI_GSET_H__

#include "BLI_ghash.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef GHash GSet;

#define BLI_gset_new(hashfp, cmpfp, info) BLI_ghash_new(hashfp, cmpfp, info)
#define BLI_gset_ptr_new(info) BLI_ghash_ptr_new(info)
#define BLI_gset_add(gs, key) BLI_ghash_insert(gs, key, (void*)(key))
#define BLI_gset_haskey(gs, key) BLI_ghash_haskey(gs, key)
#define BLI_gset_remove(gs, key, kf) BLI_ghash_remove(gs, key, kf, NULL)
#define BLI_gset_free(gs, kf) BLI_ghash_free(gs, kf, NULL)
#define BLI_gset_clear(gs, kf) BLI_ghash_clear(gs, kf, NULL)
#define BLI_gset_size(gs) BLI_ghash_size(gs)
#define BLI_gset_insert(gs, key) BLI_ghash_insert(gs, key, (void*)(key))
#define BLI_gset_new_ex(hashfp, cmpfp, info, n) BLI_ghash_new_ex(hashfp, cmpfp, info, n)
#define BLI_gset_ptr_new_ex(info, n) BLI_ghash_ptr_new_ex(info, n)

typedef GHashIterator GSetIterator;

#define BLI_gsetIterator_getKey(iter) BLI_ghashIterator_getKey(iter)
#define GSET_ITER(iter, gset) GHASH_ITER(iter, gset)

#ifdef __cplusplus
}
#endif

#endif
