#ifndef __BKE_SUBSURF_H__
#define __BKE_SUBSURF_H__

struct SubsurfModifierData;
struct Mesh;
struct DerivedMesh;
struct MPoly;
struct GridPaintMask;

typedef enum {
    SUBSURF_USE_RENDER_PARAMS = 1,
    SUBSURF_IS_FINAL_CALC = 2,
    SUBSURF_FOR_EDIT_MODE = 4,
    SUBSURF_IN_EDIT_MODE = 8,
    SUBSURF_ALLOC_PAINT_MASK = 16,
    SUBSURF_USE_GPU_BACKEND = 32,
} SubsurfFlags;

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
