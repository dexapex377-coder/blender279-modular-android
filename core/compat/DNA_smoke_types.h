#ifndef __DNA_SMOKE_TYPES_H__
#define __DNA_SMOKE_TYPES_H__

#include "DNA_ID.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Group;
struct EffectorWeights;
struct Tex;

typedef struct SmokeDomainSettings {
    struct Group *fluid_group;
    struct Group *eff_group;
    struct Group *coll_group;
    struct EffectorWeights *effector_weights;
    int dummy;
} SmokeDomainSettings;

typedef struct SmokeFlowSettings {
    int source;
    int texture_type;
    struct Tex *noise_texture;
    char vgroup_density[64];
    char vgroup_name[64];
    int flags;
} SmokeFlowSettings;

typedef struct SmokeCollSettings {
    int dummy;
} SmokeCollSettings;

#ifdef __cplusplus
}
#endif

#endif
