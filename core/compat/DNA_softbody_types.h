#ifndef __DNA_SOFTBODY_TYPES_H__
#define __DNA_SOFTBODY_TYPES_H__

#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Group;
struct EffectorWeights;

typedef struct SoftBody {
    struct Group *collision_group;
    struct EffectorWeights *effector_weights;
    int dummy;
} SoftBody;

#ifdef __cplusplus
}
#endif

#endif
