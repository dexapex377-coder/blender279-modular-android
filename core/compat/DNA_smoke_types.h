#ifndef __DNA_SMOKE_TYPES_H__
#define __DNA_SMOKE_TYPES_H__

#include "DNA_ID.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SmokeDomainSettings {
    int dummy;
} SmokeDomainSettings;

typedef struct SmokeFlowSettings {
    int source;
    int texture_type;
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
