#ifndef __BLI_KDOPBVH_H__
#define __BLI_KDOPBVH_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BVHTree BVHTree;
typedef struct BVHTreeOverlap BVHTreeOverlap;
typedef struct BVHTreeNearest BVHTreeNearest;
typedef struct BVHTreeRay BVHTreeRay;
typedef struct BVHTreeRayHit BVHTreeRayHit;

typedef void (*BVHTree_RayCastCallback)(void *userdata, int index, const BVHTreeRay *ray, BVHTreeRayHit *hit);
typedef void (*BVHTree_NearestPointCallback)(void *userdata, int index, const float co[3], BVHTreeNearest *nearest);

enum {
    BVH_OVERLAP_USE_DUPLICATES = (1 << 0),
    BVH_OVERLAP_SELF = (1 << 1),
    BVH_OVERLAP_RETURN_PAIRS = (1 << 2),
};

BVHTree *BLI_bvhtree_new(int maxleaf, float epsilon, int tree_type, int axis);
void BLI_bvhtree_free(BVHTree *tree);
int BLI_bvhtree_insert(BVHTree *tree, int index, const float co[3], int numpoints);
void BLI_bvhtree_balance(BVHTree *tree);
int BLI_bvhtree_find_nearest(BVHTree *tree, const float co[3], BVHTreeNearest *nearest, BVHTree_NearestPointCallback callback, void *userdata);
int BLI_bvhtree_find_nearest_range(BVHTree *tree, const float co[3], BVHTreeNearest *nearest, float range, BVHTree_NearestPointCallback callback, void *userdata);
void BLI_bvhtree_ray_cast(BVHTree *tree, const float co[3], const float dir[3], BVHTreeRayHit *hit, BVHTree_RayCastCallback callback, void *userdata);
int BLI_bvhtree_overlap(BVHTree *tree1, BVHTree *tree2, BVHTreeOverlap **overlap, void (*callback)(void *userdata, int index_a, int index_b), void *userdata, int flag);

#ifdef __cplusplus
}
#endif

#endif
