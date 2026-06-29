#ifndef __BLI_GHASH_H__
#define __BLI_GHASH_H__

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GHash GHash;
typedef struct GHashIterator {
    GHash *gh;
    int cur;
    void *curEntry;
    int curBucket;
} GHashIterator;

typedef unsigned int (*GHashHashFP)(const void *key);
typedef int (*GHashCmpFP)(const void *a, const void *b);
typedef void (*GHashKeyFreeFP)(void *key);
typedef void (*GHashValFreeFP)(void *val);

GHash *BLI_ghash_new(GHashHashFP hashfp, GHashCmpFP cmpfp, const char *info);
GHash *BLI_ghash_new_ex(GHashHashFP hashfp, GHashCmpFP cmpfp, const char *info, unsigned int nbr_reserve);
GHash *BLI_ghash_int_new(const char *info);
GHash *BLI_ghash_int_new_ex(const char *info, unsigned int nbr_reserve);
GHash *BLI_ghash_str_new(const char *info);
GHash *BLI_ghash_pair_new(const char *info);
GHash *BLI_ghash_ptr_new(const char *info);
GHash *BLI_ghash_ptr_new_ex(const char *info, unsigned int nbr_reserve);
void BLI_ghash_free(GHash *gh, GHashKeyFreeFP keyfreefp, GHashValFreeFP valfreefp);
int BLI_ghash_len(GHash *gh);
unsigned int BLI_ghash_size(GHash *gh);
void BLI_ghash_insert(GHash *gh, void *key, void *val);
void *BLI_ghash_lookup(GHash *gh, const void *key);
void **BLI_ghash_lookup_p(GHash *gh, const void *key);
int BLI_ghash_haskey(GHash *gh, const void *key);
void *BLI_ghash_popkey(GHash *gh, const void *key, GHashKeyFreeFP keyfreefp);
void *BLI_ghash_ensure_p(GHash *gh, void *key, void ***r_val);
bool BLI_ghash_remove(GHash *gh, void *key, GHashKeyFreeFP keyfreefp, GHashValFreeFP valfreefp);
void BLI_ghash_reinsert(GHash *gh, void *key, void *val, GHashKeyFreeFP keyfreefp, GHashValFreeFP valfreefp);
void BLI_ghash_reserve(GHash *gh, unsigned int nbr_reserve);
void BLI_ghash_clear(GHash *gh, GHashKeyFreeFP keyfreefp, GHashValFreeFP valfreefp);
void BLI_ghash_clear_ex(GHash *gh, GHashKeyFreeFP keyfreefp, GHashValFreeFP valfreefp, int n);

GHashIterator *BLI_ghashIterator_new(GHash *gh);
void BLI_ghashIterator_init(GHashIterator *ghi, GHash *gh);
void BLI_ghashIterator_free(GHashIterator *ghi);
void *BLI_ghashIterator_getKey(GHashIterator *ghi);
void *BLI_ghashIterator_getValue(GHashIterator *ghi);
void **BLI_ghashIterator_getValue_p(GHashIterator *ghi);
void BLI_ghashIterator_setValue(GHashIterator *ghi, void *val);
void BLI_ghashIterator_step(GHashIterator *ghi);
int BLI_ghashIterator_isDone(GHashIterator *ghi);
int BLI_ghashIterator_done(GHashIterator *ghi);

typedef struct GHashPair {
    void *first;
    void *second;
} GHashPair;

GHashPair *BLI_ghashPair_new(const void *first, const void *second);
unsigned int BLI_ghashutil_uinthash(const void *key);
int BLI_ghashutil_intcmp(const void *a, const void *b);
unsigned int BLI_ghashutil_strhash(const void *key);
int BLI_ghashutil_strcmp(const void *a, const void *b);
unsigned int BLI_ghashutil_ptrhash(const void *key);
int BLI_ghashutil_ptrcmp(const void *a, const void *b);
unsigned int BLI_ghashutil_uinthash_v4(const unsigned int key[4]);
unsigned int BLI_ghashutil_inthash_v4(const void *key);
int BLI_ghashutil_inthash_v4_cmp(const void *a, const void *b);
unsigned int BLI_ghashutil_inthash_p_simple(const void *key);
int BLI_ghashutil_uinthash_v4_cmp(const void *a, const void *b);

#define BLI_ghashutil_inthash_v4_p ((GHashHashFP)BLI_ghashutil_uinthash_v4)
#define BLI_ghashutil_uinthash_v4_p ((GHashHashFP)BLI_ghashutil_uinthash_v4)
#define BLI_ghashutil_inthash_v4_cmp BLI_ghashutil_uinthash_v4_cmp

#define GHASH_ITER(gh_iter_, ghash_) \
    for (BLI_ghashIterator_init(&gh_iter_, ghash_); \
         !BLI_ghashIterator_isDone(&gh_iter_); \
         BLI_ghashIterator_step(&gh_iter_))

#ifdef __cplusplus
}
#endif

#endif
