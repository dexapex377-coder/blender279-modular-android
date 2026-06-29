#ifndef __BKE_MULTIRES_H__
#define __BKE_MULTIRES_H__

#ifdef __cplusplus
extern "C" {
#endif

struct Object;
struct Mesh;
struct MultiresModifierData;
struct DerivedMesh;

int multires_mdisp_corners(struct MDisps *mdisp);
void multires_modifier_update_hidden(struct Mesh *me);
void multires_set_tot_disp(struct Mesh *me);
int multires_reshape_totvert(const struct MultiresModifierData *mmd, int totvert);
int multires_reshape_totpoly(const struct MultiresModifierData *mmd, int totpoly);
int multires_reshape_totloop(const struct MultiresModifierData *mmd, int totloop);

#ifdef __cplusplus
}
#endif

#endif
