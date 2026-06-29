#ifndef __BKE_MESH_MAPPING_H__
#define __BKE_MESH_MAPPING_H__

struct MVert;
struct MEdge;
struct MPoly;
struct MLoop;
struct MLoopUV;
struct MLoopTri;
struct MemArena;

typedef struct MeshElemMap {
    int *indices;
    int count;
} MeshElemMap;

typedef struct MeshIslandStore {
    short item_type;
    short island_type;
    short innercut_type;

    int  items_to_islands_num;
    int *items_to_islands;

    int                  islands_num;
    size_t               islands_num_alloc;
    struct MeshElemMap **islands;
    struct MeshElemMap **innercuts;

    struct MemArena *mem;
} MeshIslandStore;

enum {
    MISLAND_TYPE_NONE = 0,
    MISLAND_TYPE_VERT = 1,
    MISLAND_TYPE_EDGE = 2,
    MISLAND_TYPE_POLY = 3,
    MISLAND_TYPE_LOOP = 4,
};

#endif
