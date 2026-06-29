#ifndef __BLI_MEMPOOL_H__
#define __BLI_MEMPOOL_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BLI_mempool BLI_mempool;
typedef struct BLI_mempool_chunk BLI_mempool_chunk;

typedef void (*BLI_mempool_freefunc)(void *ptr);

BLI_mempool *BLI_mempool_create(unsigned int esize, unsigned int totelem, unsigned int pchunk, unsigned int flag);
void *BLI_mempool_alloc(BLI_mempool *pool);
void *BLI_mempool_calloc(BLI_mempool *pool);
void BLI_mempool_free(BLI_mempool *pool, void *addr);
void BLI_mempool_destroy(BLI_mempool *pool);
int BLI_mempool_count(BLI_mempool *pool);
void BLI_mempool_clear(BLI_mempool *pool);
void **BLI_mempool_get_hash(BLI_mempool *pool, int hashsize);
void *BLI_mempool_findelem(BLI_mempool *pool, unsigned int index);
int BLI_mempool_len(BLI_mempool *pool);
void BLI_mempool_set_max(BLI_mempool *pool, int max);

typedef struct BLI_mempool_iter {
    BLI_mempool *pool;
    BLI_mempool_chunk *curchunk;
    unsigned int curidx;
} BLI_mempool_iter;

void BLI_mempool_iternew(BLI_mempool *pool, BLI_mempool_iter *iter);
void *BLI_mempool_iterstep(BLI_mempool_iter *iter);

#define BLI_MEMPOOL_ALLOW_ITER 1

/* Flags */
#define BLI_MEMPOOL_NOP 0
#define BLI_MEMPOOL_ALLOW_MIXED 1

#ifdef __cplusplus
}
#endif

#endif
