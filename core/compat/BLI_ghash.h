#ifndef __BLI_GHASH_H__
#define __BLI_GHASH_H__

#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GHash GHash;
typedef struct GHashIterator GHashIterator;

typedef unsigned int (*GHashHashFP)(const void *key);
typedef int (*GHashCmpFP)(const void *a, const void *b);
typedef void (*GHashKeyFreeFP)(void *key);
typedef void (*GHashValFreeFP)(void *val);

GHash *BLI_ghash_new(GHashHashFP hashfp, GHashCmpFP cmpfp, const char *info);
GHash *BLI_ghash_int_new(const char *info);
GHash *BLI_ghash_str_new(const char *info);
GHash *BLI_ghash_pair_new(const char *info);
GHash *BLI_ghash_ptr_new(const char *info);
void BLI_ghash_free(GHash *gh, GHashKeyFreeFP keyfreefp, GHashValFreeFP valfreefp);
int BLI_ghash_len(GHash *gh);
void BLI_ghash_insert(GHash *gh, void *key, void *val);
void *BLI_ghash_lookup(GHash *gh, const void *key);
void **BLI_ghash_lookup_p(GHash *gh, const void *key);
int BLI_ghash_haskey(GHash *gh, const void *key);
void *BLI_ghash_popkey(GHash *gh, const void *key, GHashKeyFreeFP keyfreefp);
void BLI_ghash_clear(GHash *gh, GHashKeyFreeFP keyfreefp, GHashValFreeFP valfreefp);
void BLI_ghash_clear_ex(GHash *gh, GHashKeyFreeFP keyfreefp, GHashValFreeFP valfreefp, int n);

GHashIterator *BLI_ghashIterator_new(GHash *gh);
void BLI_ghashIterator_init(GHashIterator *ghi, GHash *gh);
void BLI_ghashIterator_free(GHashIterator *ghi);
void *BLI_ghashIterator_getKey(GHashIterator *ghi);
void *BLI_ghashIterator_getValue(GHashIterator *ghi);
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

#define GHASH_ITER(gh_iter_, ghash_) \
    for (BLI_ghashIterator_init(&gh_iter_, ghash_); \
         !BLI_ghashIterator_isDone(&gh_iter_); \
         BLI_ghashIterator_step(&gh_iter_))

#ifdef __cplusplus
}
#endif

#endif
