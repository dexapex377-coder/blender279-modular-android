#ifndef __CARVE_CAPI_H__
#define __CARVE_CAPI_H__

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

struct CarveMeshDescr;
struct ImportMeshData;

typedef int (*CarveImporter_GetNumVerts)(struct ImportMeshData *import_data);
typedef int (*CarveImporter_GetNumEdges)(struct ImportMeshData *import_data);
typedef int (*CarveImporter_GetNumLoops)(struct ImportMeshData *import_data);
typedef int (*CarveImporter_GetNumPolys)(struct ImportMeshData *import_data);
typedef void (*CarveImporter_GetVertCoord)(struct ImportMeshData *import_data, int vert_index, float coord[3]);
typedef void (*CarveImporter_GetEdgeVerts)(struct ImportMeshData *import_data, int edge_index, int *v1, int *v2);
typedef int (*CarveImporter_GetPolyNumVerts)(struct ImportMeshData *import_data, int poly_index);
typedef void (*CarveImporter_GetPolyVerts)(struct ImportMeshData *import_data, int poly_index, int *verts);
typedef int (*CarveImporter_Triangulate2DPoly)(struct ImportMeshData *import_data,
                                               const float (*vertices)[2], int num_vertices,
                                               unsigned int (*triangles)[3]);

typedef struct CarveMeshImporter {
    CarveImporter_GetNumVerts getNumVerts;
    CarveImporter_GetNumEdges getNumEdges;
    CarveImporter_GetNumLoops getNumLoops;
    CarveImporter_GetNumPolys getNumPolys;
    CarveImporter_GetVertCoord getVertCoord;
    CarveImporter_GetEdgeVerts getEdgeVerts;
    CarveImporter_GetPolyNumVerts getNumPolyVerts;
    CarveImporter_GetPolyVerts getPolyVerts;
    CarveImporter_Triangulate2DPoly triangulate2DPoly;
} CarveMeshImporter;

struct ExportMeshData;

typedef void (*CarveExporter_InitGeomArrays)(struct ExportMeshData *export_data,
                                              int num_verts, int num_edges,
                                              int num_loops, int num_polys);
typedef void (*CarveExporter_SetVert)(struct ExportMeshData *export_data,
                                       int vert_index, float coord[3],
                                       int which_orig_mesh, int orig_vert_index);
typedef void (*CarveExporter_SetEdge)(struct ExportMeshData *export_data,
                                       int edge_index, int v1, int v2,
                                       int which_orig_mesh, int orig_edge_index);
typedef void (*CarveExporter_SetPoly)(struct ExportMeshData *export_data,
                                       int poly_index, int start_loop, int num_loops,
                                       int which_orig_mesh, int orig_poly_index);
typedef void (*CarveExporter_SetLoop)(struct ExportMeshData *export_data,
                                       int loop_index, int vertex, int edge,
                                       int which_orig_mesh, int orig_loop_index);
typedef int (*CarveExporter_MapLoopToEdge)(struct ExportMeshData *export_data,
                                            int which_mesh, int loop_index);

typedef struct CarveMeshExporter {
    CarveExporter_InitGeomArrays initGeomArrays;
    CarveExporter_SetVert setVert;
    CarveExporter_SetEdge setEdge;
    CarveExporter_SetPoly setPoly;
    CarveExporter_SetLoop setLoop;
    CarveExporter_MapLoopToEdge mapLoopToEdge;
} CarveMeshExporter;

enum {
    CARVE_OP_UNION,
    CARVE_OP_INTERSECTION,
    CARVE_OP_A_MINUS_B,
};

enum {
    CARVE_MESH_NONE,
    CARVE_MESH_LEFT,
    CARVE_MESH_RIGHT
};

struct CarveMeshDescr *carve_addMesh(struct ImportMeshData *import_data,
                                     CarveMeshImporter *mesh_importer);
void carve_deleteMesh(struct CarveMeshDescr *mesh_descr);
bool carve_performBooleanOperation(struct CarveMeshDescr *left_mesh,
                                   struct CarveMeshDescr *right_mesh,
                                   int operation,
                                   struct CarveMeshDescr **output_mesh);
void carve_exportMesh(struct CarveMeshDescr *mesh_descr,
                      CarveMeshExporter *mesh_exporter,
                      struct ExportMeshData *export_data);
void carve_unionIntersections(struct CarveMeshDescr **left_mesh_r, struct CarveMeshDescr **right_mesh_r);

#ifdef __cplusplus
}
#endif

#endif
