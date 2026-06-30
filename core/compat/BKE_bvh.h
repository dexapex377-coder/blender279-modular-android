#ifndef __BKE_BVH_H__
#define __BKE_BVH_H__

#ifdef __cplusplus
extern "C" {
#endif

struct BVHTree;

typedef struct BVHTreeNearest {
    int index;
    float dist, dist_sq;
    float no[3];
    float co[3];
    int flags;
} BVHTreeNearest;

typedef struct BVHTreeFromMesh {
    struct BVHTree *tree;
    void (*nearest_callback)(void *userdata, int index, const float co[3], struct BVHTreeNearest *nearest);
    float epsilon;
    int num_hits;
    int spatest;
    int treetype;
    int numverts;
    int numedges;
    int numfaces;
} BVHTreeFromMesh;

#ifdef __cplusplus
}
#endif

#endif
