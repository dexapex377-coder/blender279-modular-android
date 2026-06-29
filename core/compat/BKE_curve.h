#ifndef __BKE_CURVE_H__
#define __BKE_CURVE_H__

#include "DNA_curve_types.h"
#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Path;

typedef struct CurveCache {
    ListBase disp;
    ListBase bev;
    ListBase deformed_nurbs;
    struct Path *path;
} CurveCache;

void BKE_curve_free(Curve *cu);

#ifdef __cplusplus
}
#endif

#endif