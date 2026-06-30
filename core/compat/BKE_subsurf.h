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

#endif
