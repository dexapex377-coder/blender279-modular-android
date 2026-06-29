#ifndef __DNA_MATERIAL_TYPES_H__
#define __DNA_MATERIAL_TYPES_H__

#include "DNA_ID.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Material {
    struct Material *next, *prev;
    ID id;
    short flag;
    short type;
    float r, g, b, a;
    float specr, specg, specb;
    float mirr, mirg, mirb;
    float amb, spec, emit, ray_mirror;
    float alpha;
    float halo;

    /* nodes */
    struct bNodeTree *nodetree;
    short use_nodes;
    short pr_type;
    short shader_type;
    short pad;
    char texact;
    char pr_lamp;

    /* preview */
    struct PreviewImage *preview;
} Material;

#ifdef __cplusplus
}
#endif

#endif
