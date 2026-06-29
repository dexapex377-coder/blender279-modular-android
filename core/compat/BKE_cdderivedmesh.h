#ifndef __BKE_CDDERIVEDMESH_H__
#define __BKE_CDDERIVEDMESH_H__

#include "BKE_DerivedMesh.h"

#ifdef __cplusplus
extern "C" {
#endif

DerivedMesh *CDDM_from_mesh(struct Mesh *me);
DerivedMesh *CDDM_new(int numVerts, int numEdges, int numFaces, int numLoops, int numPolys);
void CDDM_free(DerivedMesh *dm);

#ifdef __cplusplus
}
#endif

#endif
