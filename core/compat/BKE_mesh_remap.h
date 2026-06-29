#ifndef __BKE_MESH_REMAP_H__
#define __BKE_MESH_REMAP_H__

#include "DNA_listBase.h"

struct MVert;
struct MEdge;
struct MLoop;
struct MPoly;
struct DerivedMesh;
struct CustomData;
struct SpaceTransform;
struct MeshIslandStore;

enum {
    MREMAP_USE_VERT    = 1 << 4,
    MREMAP_USE_EDGE    = 1 << 5,
    MREMAP_USE_LOOP    = 1 << 6,
    MREMAP_USE_POLY    = 1 << 7,

    MREMAP_USE_NEAREST = 1 << 8,
    MREMAP_USE_NORPROJ = 1 << 9,
    MREMAP_USE_INTERP  = 1 << 10,
    MREMAP_USE_NORMAL  = 1 << 11,
};

typedef struct MeshPairRemapItem {
    int    sources_num;
    int   *indices_src;
    float *weights_src;
    int    island;
} MeshPairRemapItem;

typedef struct MeshPairRemap {
    int                items_num;
    MeshPairRemapItem *items;
    struct MemArena   *mem;
} MeshPairRemap;

void BKE_mesh_remap_init(MeshPairRemap *map, const int items_num);
void BKE_mesh_remap_free(MeshPairRemap *map);

typedef bool (*MeshRemapIslandsCalc)(
        struct MVert *verts, const int totvert,
        struct MEdge *edges, const int totedge,
        struct MPoly *polys, const int totpoly,
        struct MLoop *loops, const int totloop,
        struct MeshIslandStore *r_island_store);

#endif
