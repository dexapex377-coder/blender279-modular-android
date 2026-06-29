#ifndef __BLI_EDGEHASH_H__
#define __BLI_EDGEHASH_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EdgeHash EdgeHash;
typedef struct EdgeHashIterator EdgeHashIterator;

EdgeHash *BLI_edgehash_new(const char *info);
void BLI_edgehash_free(EdgeHash *eh, void (*free_value)(void *));
void BLI_edgehash_insert(EdgeHash *eh, unsigned int v1, unsigned int v2, void *val);
void *BLI_edgehash_lookup(EdgeHash *eh, unsigned int v1, unsigned int v2);
void **BLI_edgehash_lookup_p(EdgeHash *eh, unsigned int v1, unsigned int v2);
int BLI_edgehash_size(EdgeHash *eh);
int BLI_edgehash_len(EdgeHash *eh);
void BLI_edgehash_clear(EdgeHash *eh, void (*free_value)(void *));
int BLI_edgehash_haskey(EdgeHash *eh, unsigned int v1, unsigned int v2);
void BLI_edgehash_remove(EdgeHash *eh, unsigned int v1, unsigned int v2, void (*free_value)(void *));

EdgeHashIterator *BLI_edgehashIterator_new(EdgeHash *eh);
void BLI_edgehashIterator_free(EdgeHashIterator *ehi);
void BLI_edgehashIterator_getKey(EdgeHashIterator *ehi, unsigned int *r_v1, unsigned int *r_v2);
void *BLI_edgehashIterator_getValue(EdgeHashIterator *ehi);
void BLI_edgehashIterator_setValue(EdgeHashIterator *ehi, void *val);
void BLI_edgehashIterator_step(EdgeHashIterator *ehi);
int BLI_edgehashIterator_isDone(EdgeHashIterator *ehi);

#define EDGEHASH_SIZE_AT_LEAST 256

#ifdef __cplusplus
}
#endif

#endif
