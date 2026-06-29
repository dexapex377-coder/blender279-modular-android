#ifndef __DNA_WORLD_TYPES_H__
#define __DNA_WORLD_TYPES_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct World {
    struct World *next, *prev;
    struct ID id;
    float horr, horg, horb;
    float zenr, zeng, zenb;
    float blr, blg, blb;
    float exposure;
    float range;
    float mistype;
    float miststa;
    float mistdist;
    float mistint;
    float starr, starg, starb;
    float stardist;
    float starsize;
    int mode;
    int flag;
} World;

#ifdef __cplusplus
}
#endif

#endif
