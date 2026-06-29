#ifndef __BKE_MESH_H__
#define __BKE_MESH_H__

#include <stdbool.h>

#include "DNA_mesh_types.h"
#include "DNA_customdata_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Object;
struct BMesh;

/* Loop normal space types */
typedef struct MLoopNorSpace {
    float vec_lnor[3];
    float vec_ref[3];
    float vec_ortho[3];
    float vec_lnor_no_clamp[3];
    float ref_alpha;
    float ref_beta;
    struct MLoopNorSpace *next;
    short clnors_data[2];
    int num_loops;
    int index;
    int flag;
} MLoopNorSpace;

typedef struct MLoopNorSpaceArray {
    MLoopNorSpace **lspacearr;
    MLoopNorSpace *spacearr;
    int num_spaces;
    int is_single;
} MLoopNorSpaceArray;

void BKE_mesh_update_customdata_pointers(struct Mesh *me, int do_ensure_tessface);
void BKE_mesh_tessface_calc(struct Mesh *me);

int BKE_mesh_normals_loop_split(
    struct MVert *mvert, int totvert,
    struct MEdge *medge, int totedge,
    struct MLoop *mloop, float (*r_loopnors)[3], int totloop,
    struct MPoly *mpoly, const float (*polynors)[3], int totpoly,
    int (*r_poly_nors)[3]);

void BKE_lnor_spacearr_init(MLoopNorSpaceArray *lnors_spacearr, const int numLoops);
void BKE_lnor_spacearr_free(MLoopNorSpaceArray *lnors_spacearr);
MLoopNorSpace *BKE_lnor_space_create(MLoopNorSpaceArray *lnors_spacearr);
void BKE_lnor_space_define(
    MLoopNorSpace *lnor_space, const float lnor[3],
    float vec_ref[3], float vec_other[3],
    const float bspace[2][3]);
void BKE_lnor_space_add_loop(
    MLoopNorSpaceArray *lnors_spacearr, MLoopNorSpace *lnor_space,
    const int ml_index, const bool add_to_list);
void BKE_lnor_space_custom_data_to_normal(
    const MLoopNorSpace *lnor_space, const short clnor_data[2], float r_custom_lnor[3]);

void BKE_mesh_mdisp_flip(struct MPoly *mpoly, int totpoly);

struct Mesh *BKE_mesh_add(void);
struct Mesh *BKE_mesh_new_from_object(struct Object *ob, int apply_modifiers);
void BKE_mesh_calc_edges(struct Mesh *me);
void BKE_mesh_calc_normals(struct Mesh *me);
void BKE_mesh_from_bmesh(struct BMesh *bm, struct Mesh *me, int calc_face_normal);
void BKE_mesh_to_bmesh(struct Mesh *me, struct Object *ob, struct BMesh *bm, int set_face_nor);

#ifdef __cplusplus
}
#endif

#endif
