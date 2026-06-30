#ifndef __DNA_MESH_TYPES_H__
#define __DNA_MESH_TYPES_H__

#include "DNA_ID.h"
#include "DNA_listBase.h"
#include "DNA_customdata_types.h"
#include "DNA_key_types.h"
#include "DNA_meshdata_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Mesh {
    ID id;
    int totvert, totedge, totface, totloop, totpoly;
    int totselect;
    int cd_flag;
    short flag;
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
    float smoothresh;
    ListBase fcache;
    int act_face;
} Mesh;

enum {
    ME_AUTOSMOOTH = (1 << 5),
};

#ifdef __cplusplus
}
#endif

#endif
