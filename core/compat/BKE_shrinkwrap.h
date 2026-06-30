#ifndef __BKE_SHRINKWRAP_H__
#define __BKE_SHRINKWRAP_H__

struct ShrinkwrapModifierData;
struct Object;
struct DerivedMesh;

void shrinkwrapModifier_deform(
    struct ShrinkwrapModifierData *smd,
    struct Object *ob,
    struct DerivedMesh *dm,
    float (*vertexCos)[3],
    int numVerts,
    bool for_render);

#endif
