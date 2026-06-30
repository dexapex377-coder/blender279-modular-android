#ifndef __DNA_TEXTURE_TYPES_H__
#define __DNA_TEXTURE_TYPES_H__

#include "DNA_ID.h"
#include "DNA_listBase.h"

struct Image;

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Tex {
    ID id;
    short type;
    short flag;
    int imaflag;
    int extend;
    int crop[4];
    float size[3];
    float bright, contrast, saturation, rfac, gfac, bfac;
    float filtersize;
    float checkersize, checkerdist;
    float negate;
    float pad;
    short which_output;
    short color_space;
    short env_map;
    short ix, iy, iz;
    short texfilter;
    short afmax;
    short xsize, ysize;
    int xrepeat, yrepeat;
    char name[12];
    int stub;
    struct Image *ima;
    void *iuser;
} Tex;

#ifdef __cplusplus
}
#endif

#endif
