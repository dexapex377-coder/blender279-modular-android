#ifndef __DNA_IMAGE_TYPES_H__
#define __DNA_IMAGE_TYPES_H__

#include "DNA_ID.h"
#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Image {
    ID id;
    char name[1024];
    int flag;
    int type;
    int source;
    struct Image **rr;
    int xrep, yrep;
    float aspx, aspy;
    struct anim *anim;
    struct MovieCache *cache;
    int ok;
    int lastframe;
    struct GPUTexture *gputexture;
    int tpageflag;
    int totbind;
} Image;

#define IMA_OK 1

#ifdef __cplusplus
}
#endif

#endif
