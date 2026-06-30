#ifndef __BLI_KDTREE_H__
#define __BLI_KDTREE_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct KDTree KDTree;
typedef struct KDTreeNearest KDTreeNearest;

KDTree *BLI_kdtree_new(int maxsize);
void BLI_kdtree_free(KDTree *tree);
void BLI_kdtree_balance(KDTree *tree);
int BLI_kdtree_insert(KDTree *tree, int index, const float co[3]);
int BLI_kdtree_find_nearest(KDTree *tree, const float co[3], KDTreeNearest *nearest);
int BLI_kdtree_find_nearest_cb(KDTree *tree, const float co[3], int (*filter_cb)(void *userdata, int index, const float co[3], void *payload), void *userdata, KDTreeNearest *nearest);
int BLI_kdtree_range_search(KDTree *tree, const float co[3], KDTreeNearest **nearest, float range);
int BLI_kdtree_range_search_cb(KDTree *tree, const float co[3], float range, int (*search_cb)(void *userdata, int index, const float *co, void *payload), void *userdata);

#ifdef __cplusplus
}
#endif

#endif
