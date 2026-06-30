#ifndef __BKE_COLORMAPPING_H__
#define __BKE_COLORMAPPING_H__

#include "DNA_color_types.h"

struct CurveMapping *curvemapping_add(int tot, float minx, float miny, float maxx, float maxy);
void curvemapping_free(struct CurveMapping *cumap);
struct CurveMapping *curvemapping_copy(struct CurveMapping *cumap);
float curvemapping_evaluateF(struct CurveMapping *cumap, int cur, float value);
void curvemapping_initialize(struct CurveMapping *cumap);

#endif
