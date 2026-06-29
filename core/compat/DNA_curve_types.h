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

typedef struct PathPoint {
    float vec[4];
    float quat[4];
    float radius, weight;
} PathPoint;

typedef struct Path {
    struct PathPoint *data;
    int len;
    float totdist;
} Path;

#ifdef __cplusplus
}
#endif

#endif
