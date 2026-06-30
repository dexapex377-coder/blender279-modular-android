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

struct DerivedMesh *multires_make_derived_from_derived(
    struct DerivedMesh *dm,
    struct MultiresModifierData *mmd,
    struct Object *ob,
    MultiresFlags flags);
int multires_reshape_totvert(const struct MultiresModifierData *mmd, int totvert);
int multires_reshape_totpoly(const struct MultiresModifierData *mmd, int totpoly);
int multires_reshape_totloop(const struct MultiresModifierData *mmd, int totloop);

void multiresModifier_do(
    struct Scene *scene,
    struct MultiresModifierData *mmd,
    struct Mesh *me,
    struct DerivedMesh *dm_deform,
    struct DerivedMesh **dm_result);

#ifdef __cplusplus
}
#endif

#endif
