#ifndef __DNA_TEXTURE_TYPES_H__
#define __DNA_TEXTURE_TYPES_H__

#include "DNA_ID.h"

#ifdef __cplusplus
extern "C" {
#endif

struct AnimData;

typedef struct Tex {
    ID id;
    struct AnimData *adt;
    float noisesize, turbul;
    float bright, contrast, saturation, rfac, gfac, bfac;
    float filtersize, pad2;
    float mg_H, mg_lacunarity, mg_octaves, mg_offset, mg_gain;
    float dist_amount, ns_outscale;
    float vn_w1, vn_w2, vn_w3, vn_w4, vn_mexp;
    short vn_distm, vn_coltype;
    short type, stype, flag, ima_flag, pad;
    struct Image *ima;
    struct ColorBand *coba;
    struct EnvMap *env;
    struct PreviewImage *preview;
    struct MTex *mtex;
    char use_nodes;
    char pad2s[7];
    int len;
    int pad3;
    struct bNodeTree *nodetree;
    char name[64];
} Tex;

#ifdef __cplusplus
}
#endif

#endif
