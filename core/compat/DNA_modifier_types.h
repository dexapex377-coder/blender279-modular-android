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
enum ModifierType {
    eModifierType_Subsurf = 0,
    eModifierType_Multires = 1,
    eModifierType_Hook = 2,
    eModifierType_Armature = 3,
    eModifierType_Curve = 4,
    eModifierType_Lattice = 5,
    eModifierType_ShapeKey = 6,
};
    ModifierData modifier;
    struct Armature *object;
    short flag;
    short mode;
    int limit;
    short use_deform_preserve_volume;
    short pad;
    float mult;
} ArmatureModifierData;

typedef struct CurveModifierData {
    ModifierData modifier;
    struct Object *object;
    struct Curve *curve;
    char subtarget[64];
    short flag;
    short mode;
    short deform_axis;
    short pad;
} CurveModifierData;

typedef struct LatticeModifierData {
    ModifierData modifier;
    struct Object *object;
    struct Lattice *lattice;
    short flag;
    short pad;
} LatticeModifierData;

typedef struct ShapeKeyModifierData {
    ModifierData modifier;
    struct Key *key;
    struct Object *object;
    char name[64];
    short flag;
    short pad;
} ShapeKeyModifierData;

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
