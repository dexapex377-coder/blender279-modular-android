#ifndef __DNA_MODIFIER_TYPES_H__
#define __DNA_MODIFIER_TYPES_H__

#include "DNA_scene_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ModifierData {
    struct ModifierData *next, *prev;
    int type, mode;
    int flag;
    char name[64];
} ModifierData;

typedef struct SubsurfModifierData {
    ModifierData modifier;
    short subdivision_types;
    short subdivision_limits;
    short levels, renderLevels;
    short flags;
    short quality;
} SubsurfModifierData;

typedef struct MultiresModifierData {
    ModifierData modifier;
    short lvl, totlvl;
    short flags;
    short subdivision_type;
    short quality;
    short uv_smooth;
    short boundary_smooth;
    int simple;
} MultiresModifierData;

#ifdef __cplusplus
}
#endif

#endif
