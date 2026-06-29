#ifndef __BKE_COLLISION_H__
#define __BKE_COLLISION_H__

#include "DNA_modifier_types.h"

struct Object;

void collision_move_object(struct CollisionModifierData *collmd,
                           float *step, float *prevstep, int numverts);

#endif
