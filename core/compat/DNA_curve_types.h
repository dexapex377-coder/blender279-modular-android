#ifndef __DNA_CURVE_TYPES_H__
#define __DNA_CURVE_TYPES_H__

#include "DNA_ID.h"
#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Curve {
    ID id;
    struct ListBase nurb;
    struct AnimData *adt;
    int flag;
    int type;
    int actvert;
    int actnu;
} Curve;

#ifdef __cplusplus
}
#endif

#endif
