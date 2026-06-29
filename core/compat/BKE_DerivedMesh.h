#ifndef __BKE_DERIVEDMESH_H__
#define __BKE_DERIVEDMESH_H__

#include "DNA_meshdata_types.h"
#include "DNA_customdata_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct DerivedMesh {
    int type;
    int numVertData;
    int numEdgeData;
    int numTessFaceData;
    int numLoopData;
    int numPolyData;
    int needsFree;
    int deformedOnly;
    int (*getNumVerts)(struct DerivedMesh *dm);
    int (*getNumEdges)(struct DerivedMesh *dm);
    int (*getNumLoops)(struct DerivedMesh *dm);
    int (*getNumPolys)(struct DerivedMesh *dm);
    int (*getNumTessFaces)(struct DerivedMesh *dm);
    void (*getVertCos)(struct DerivedMesh *dm, float (*r_cos)[3]);
    void (*getVertDataArray)(struct DerivedMesh *dm, int type, void **r_data);
    void (*getEdgeDataArray)(struct DerivedMesh *dm, int type, void **r_data);
    void (*getTessFaceDataArray)(struct DerivedMesh *dm, int type, void **r_data);
    void (*getLoopDataArray)(struct DerivedMesh *dm, int type, void **r_data);
    void (*getPolyDataArray)(struct DerivedMesh *dm, int type, void **r_data);
    void (*release)(struct DerivedMesh *dm);

    CustomData vertData, edgeData, tessFaceData, loopData, polyData;
    struct Mesh *mesh;
} DerivedMesh;

void DM_to_mesh(DerivedMesh *dm, struct Mesh *me, struct Object *ob);

#ifdef __cplusplus
}
#endif

#endif
