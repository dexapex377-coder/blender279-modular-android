#ifndef __DNA_META_TYPES_H__
#define __DNA_META_TYPES_H__

#include "DNA_ID.h"
#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct MetaBall {
    ID id;
    struct AnimData *adt;
    float flag;
    float ofs[3];
    float size[3];
    float texspace[4][4];
    int texflag;
    float wiresize;
    int rendermode;
    int pad;
    ListBase elems;
    struct Object *parent;
    float latmin, latmax;
} MetaBall;

typedef struct MetaElem {
    struct MetaElem *next, *prev;
    short type;
    short flag;
    float x, y, z;
    float rad;
    float s_x, s_y, s_z;
    float rot[3][3];
    float quat[4];
    float expy;
    float ex;
    float *mat;
    float *bb;
    int *bbsize;
} MetaElem;

#ifdef __cplusplus
}
#endif

#endif
