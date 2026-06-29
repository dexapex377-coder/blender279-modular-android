#ifndef __BKE_MESH_H__
#define __BKE_MESH_H__

#include "DNA_mesh_types.h"
#include "DNA_customdata_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Object;
struct BMesh;

void BKE_mesh_update_customdata_pointers(struct Mesh *me, int do_ensure_tessface);
void BKE_mesh_tessface_calc(struct Mesh *me);

int BKE_mesh_normals_loop_split(
    struct MVert *mvert, int totvert,
    struct MEdge *medge, int totedge,
    struct MLoop *mloop, float (*r_loopnors)[3], int totloop,
    struct MPoly *mpoly, const float (*polynors)[3], int totpoly,
    int (*r_poly_nors)[3]);

void BKE_lnor_spacearr_init(int *r_lnor_spacearr, int numLoops, char data_type);
void BKE_lnor_spacearr_free(int *lnor_spacearr);
void BKE_lnor_space_define(int *lnor_space, const float lnor[3], const float vec_ref[3], const float vec_ortho[3]);
void BKE_lnor_space_add_loop(int *lnor_spacearr, int *lnor_space, int ml_index, int *r_ml_index, int do_compact);
void BKE_lnor_space_custom_data_to_normal(int *lnor_spacearr, int ml_index, float r_custom_lnor[3]);

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
