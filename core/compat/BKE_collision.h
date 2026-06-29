#ifndef __BKE_COLLISION_H__
#define __BKE_COLLISION_H__

struct Object;
struct CollisionModifierData;

void collision_move_object(struct CollisionModifierData *collmd,
                           float *step, float *prevstep, int numverts);

#endif
