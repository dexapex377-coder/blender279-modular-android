#ifndef __BLI_KDOPBVH_H__
#define __BLI_KDOPBVH_H__

#include <float.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

struct BVHTree;
typedef struct BVHTree BVHTree;

typedef struct BVHTreeAxisRange {
    union {
        struct {
            float min, max;
        };
        float range[2];
    };
} BVHTreeAxisRange;

typedef struct BVHTreeOverlap {
    int indexA;
    int indexB;
} BVHTreeOverlap;

typedef struct BVHTreeNearest {
    int index;
    float co[3];
    float no[3];
    float dist_sq;
    int flags;
} BVHTreeNearest;

typedef struct BVHTreeRay {
    float origin[3];
    float direction[3];
    float radius;
    void *isect_precalc;
} BVHTreeRay;

typedef struct BVHTreeRayHit {
    int index;
    float co[3];
    float no[3];
    float dist;
} BVHTreeRayHit;

enum {
    BVH_RAYCAST_WATERTIGHT = (1 << 0),
};
#define BVH_RAYCAST_DEFAULT (BVH_RAYCAST_WATERTIGHT)
#define BVH_RAYCAST_DIST_MAX (FLT_MAX / 2.0f)

typedef void (*BVHTree_NearestPointCallback)(void *userdata, int index, const float co[3], BVHTreeNearest *nearest);
typedef void (*BVHTree_RayCastCallback)(void *userdata, int index, const BVHTreeRay *ray, BVHTreeRayHit *hit);
typedef bool (*BVHTree_OverlapCallback)(void *userdata, int index_a, int index_b, int thread);

void *BLI_kdopbvh_tree_new_ex(
        const float (*co)[3], int num_co,
        const int (*triangles)[3], int num_triangles,
        const float (*vertex_normals)[3],
        int flags);

BVHTree *BLI_kdopbvh_tree_new(
        const float (*co)[3], int num_co,
        const int (*triangles)[3], int num_triangles);

void BLI_kdopbvh_tree_free(BVHTree *tree);

bool BLI_kdopbvh_tree_is_valid(BVHTree *tree);

int BLI_kdopbvh_tree_find_nearest(
        BVHTree *tree, const float co[3], float radius,
        BVHTreeNearest *nearest, BVHTree_NearestPointCallback callback, void *userdata);

int BLI_kdopbvh_tree_find_nearest_ex(
        BVHTree *tree, const float co[3], float radius,
        BVHTreeNearest *nearest, BVHTree_NearestPointCallback callback, void *userdata, int flags);

int BLI_kdopbvh_tree_ray_cast(
        BVHTree *tree, const float co[3], const float dir[3], float radius,
        BVHTreeRayHit *hit, BVHTree_RayCastCallback callback, void *userdata);

int BLI_kdopbvh_tree_ray_cast_ex(
        BVHTree *tree, const float co[3], const float dir[3], float radius,
        BVHTreeRayHit *hit, BVHTree_RayCastCallback callback, void *userdata, int flags);

bool BLI_kdopbvh_tree_overlap(
        BVHTree *tree, const float co[3], const float dir[3], float radius,
        BVHTreeOverlap *overlap, BVHTree_OverlapCallback callback, void *userdata);

bool BLI_kdopbvh_tree_overlap_ex(
        BVHTree *tree, const float co[3], const float dir[3], float radius,
        BVHTreeOverlap *overlap, BVHTree_OverlapCallback callback, void *userdata, int flags);

#ifdef __cplusplus
}
#endif

#endif /* __BLI_KDOPBVH_H__ */