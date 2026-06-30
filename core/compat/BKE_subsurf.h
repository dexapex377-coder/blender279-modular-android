#ifndef __BKE_SUBSURF_H__
#define __BKE_SUBSURF_H__

struct SubsurfModifierData;
struct Mesh;
struct DerivedMesh;

void subsurf_calculate_derived_mesh(
    struct Scene *scene,
    struct SubsurfModifierData *smd,
    struct DerivedMesh *dm_original,
    struct Mesh *me,
    struct DerivedMesh **dem,
    int use_subsurf_uv,
    bool *r_was_calculated);

void subsurf_copy_grid_hidden(
    struct DerivedMesh *result,
    void *mpoly,
    int totpoly,
    void *grid_hidden);

void subsurf_copy_grid_paint_mask(
    struct DerivedMesh *result,
    void *mpoly,
    int totpoly,
    float *grid_paint_mask);

#endif
