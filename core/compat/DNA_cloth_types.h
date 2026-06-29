#ifndef __DNA_CLOTH_TYPES_H__
#define __DNA_CLOTH_TYPES_H__

#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ClothModifierData {
    struct ClothModifierData *next, *prev;
    struct Object *ob;
    struct Cloth *cloth;
    struct ClothSimSettings *sim_parms;
    struct ClothCollSettings *col_parms;
    short pad;
    short flags;
    struct MVert *xnew;
    struct MVert *x;
    struct MVert *xold;
    struct MVert *current_xnew;
    struct MVert *current_x;
    struct MVert *current_xold;
    int tri_count;
    unsigned int *tri_indices;
} ClothModifierData;

#ifdef __cplusplus
}
#endif

#endif
