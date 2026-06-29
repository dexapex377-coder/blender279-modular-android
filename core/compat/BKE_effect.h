#ifndef __BKE_EFFECT_H__
#define __BKE_EFFECT_H__

struct Object;
struct Scene;
struct EffectorWeights;

void BKE_effectors_apply(struct Object *ob, struct Scene *scene,
                         struct EffectorWeights *effector_weights,
                         float *force, float *vel, float *pos);

#endif
