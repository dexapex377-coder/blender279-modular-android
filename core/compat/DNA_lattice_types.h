#ifndef __DNA_LATTICE_TYPES_H__
#define __DNA_LATTICE_TYPES_H__

#include "DNA_ID.h"
#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Lattice {
    ID id;
    struct ListBase lattbase;
    int pntsu, pntsv, pntsw;
    int type;
    int flag;
    int active;
    float twists[3];
    float sw[3];
    float ew[3];
    float gw[3];
    float f[3];
} Lattice;

typedef struct LatticeModifierData LatticeModifierData;

#ifdef __cplusplus
}
#endif

#endif