#ifndef __BKE_PBVH_H__
#define __BKE_PBVH_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct PBVH PBVH;
typedef struct PBVHNode PBVHNode;

struct Mesh;
struct Object;
struct DMGridData;
struct MVert;

typedef struct PBVHVertexIter {
    int index;
    int totvert;
    struct MVert *mvert;
    float *co;
    float *no;
    int *vert_indices;
} PBVHVertexIter;

enum {
    PBVH_REFINE_ALL = 1,
    PBVH_REFINE_COLLAPSE = 2,
};

void BKE_pbvh_build(struct PBVH *pbvh, struct Mesh *mesh, const float (*co)[3], int totvert, int totface, int totgrid);
void BKE_pbvh_free(struct PBVH *pbvh);
int BKE_pbvh_totnodes(struct PBVH *pbvh);
void BKE_pbvh_update(struct PBVH *pbvh, int flags, const float (*co)[3], int totvert);
void BKE_pbvh_draw(struct PBVH *pbvh, void *draw_data);
void BKE_pbvh_tex_iter_begin(struct PBVH *pbvh, void *userdata);

#ifdef __cplusplus
}
#endif

#endif
