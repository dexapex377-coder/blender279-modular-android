#ifndef __DNA_SMOKE_TYPES_H__
#define __DNA_SMOKE_TYPES_H__

#include "DNA_ID.h"

#ifdef __cplusplus
extern "C" {
#endif

struct SmokeDomainSettings;
struct SmokeFlowSettings;
struct SmokeCollSettings;

typedef struct SmokeModifierData {
    ModifierData modifier;
    struct SmokeDomainSettings *domain;
    struct SmokeFlowSettings *flow;
    struct SmokeCollSettings *coll;
    float time;
    int type;
} SmokeModifierData;

enum {
    MOD_SMOKE_TYPE_DOMAIN = (1 << 0),
    MOD_SMOKE_TYPE_FLOW   = (1 << 1),
    MOD_SMOKE_TYPE_COLL   = (1 << 2),
};

#define MOD_SMOKE_FLOW_SOURCE_MESH 1
#define MOD_SMOKE_FLOW_TEXTURE_MAP_UV 1

#ifdef __cplusplus
}
#endif

#endif
