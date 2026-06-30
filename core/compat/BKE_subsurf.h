#ifndef __BKE_SUBSURF_H__
#define __BKE_SUBSURF_H__

struct SubsurfModifierData;
struct Mesh;
struct DerivedMesh;
struct MPoly;
struct GridPaintMask;

void subsurf_calculate_derived_mesh(
    struct Scene *scene,
    struct SubsurfModifierData *smd,
    struct DerivedMesh *dm_original,
    struct Mesh *me,
    struct DerivedMesh **dem,
    int use_subsurf_uv,
    bool *r_was_calculated);

void subsurf_copy_grid_hidden(
    struct DerivedMesh *dm,
    const struct MPoly *mpoly,
    struct MVert *mvert,
    const struct MDisps *mdisps);

void subsurf_copy_grid_paint_mask(
    struct DerivedMesh *dm,
    const struct MPoly *mpoly,
    float *paint_mask,
    const struct GridPaintMask *grid_paint_mask);

#endif
