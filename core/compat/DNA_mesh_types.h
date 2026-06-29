#ifndef __DNA_MESH_TYPES_H__
#define __DNA_MESH_TYPES_H__

#include "DNA_listBase.h"
#include "DNA_customdata_types.h"
#include "DNA_key_types.h"
#include "DNA_meshdata_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ID {
    void *next, *prev;
    int us, flag;
    int icon_id;
    int recalc;
    char name[70];
    short session_uuid;
} ID;

typedef struct Mesh {
    ID id;
    int totvert, totedge, totface, totloop, totpoly;
    int totselect;
    int cd_flag;
    struct MVert *mvert;
    struct MEdge *medge;
    struct MFace *mface;
    struct MLoop *mloop;
    struct MPoly *mpoly;
    struct MSelect *mselect;
    CustomData vdata, edata, fdata, ldata, pdata;
    int *triangles;
    struct Key *key;
    struct EditMesh *edit_mesh;
    ListBase fcache;
} Mesh;

#ifdef __cplusplus
}
#endif

#endif
