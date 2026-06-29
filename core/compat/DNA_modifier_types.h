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

typedef struct HookModifierData {
    ModifierData modifier;
    struct Object *object;
    char subtarget[64];
    short flag;
    short falloff_type;
    int totindex;
    int *indexar;
    float *weights;
    float cent[3];
    float falloff_rad;
    float force;
    float curfalloff;
} HookModifierData;

/* Modifier types */
enum {
    eModifierType_Hook = 18,
};

/* TriangulateModifier flags (deprecated) */
#ifdef DNA_DEPRECATED
enum {
	MOD_TRIANGULATE_BEAUTY = (1 << 0),
};
#endif

/* Triangulate methods - NGons */
enum {
	MOD_TRIANGULATE_NGON_BEAUTY = 0,
	MOD_TRIANGULATE_NGON_EARCLIP,
};

/* Triangulate methods - Quads */
enum {
	MOD_TRIANGULATE_QUAD_BEAUTY = 0,
	MOD_TRIANGULATE_QUAD_FIXED,
	MOD_TRIANGULATE_QUAD_ALTERNATE,
	MOD_TRIANGULATE_QUAD_SHORTEDGE
};

#ifdef __cplusplus
}
#endif

#endif
