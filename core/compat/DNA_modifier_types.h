#ifndef __DNA_MODIFIER_TYPES_H__
#define __DNA_MODIFIER_TYPES_H__

#include "DNA_scene_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ModifierData {
    struct ModifierData *next, *prev;
    int type, mode;
    int stackindex, pad;
    char name[64];  /* MAX_NAME */

    /* XXX for timing info set by caller... solve later? (ton) */
    struct Scene *scene;

    char *error;
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
typedef enum ModifierType {
	eModifierType_None              = 0,
	eModifierType_Subsurf           = 1,
	eModifierType_Lattice           = 2,
	eModifierType_Curve             = 3,
	eModifierType_Build             = 4,
	eModifierType_Mirror            = 5,
	eModifierType_Decimate          = 6,
	eModifierType_Wave              = 7,
	eModifierType_Armature          = 8,
	eModifierType_Hook              = 9,
	eModifierType_Softbody          = 10,
	eModifierType_Boolean           = 11,
	eModifierType_Array             = 12,
	eModifierType_EdgeSplit         = 13,
	eModifierType_Displace          = 14,
	eModifierType_UVProject         = 15,
	eModifierType_Smooth            = 16,
	eModifierType_Cast              = 17,
	eModifierType_MeshDeform        = 18,
	eModifierType_ParticleSystem    = 19,
	eModifierType_ParticleInstance  = 20,
	eModifierType_Explode           = 21,
	eModifierType_Cloth             = 22,
	eModifierType_Collision         = 23,
	eModifierType_Bevel             = 24,
	eModifierType_Shrinkwrap        = 25,
	eModifierType_Fluidsim          = 26,
	eModifierType_Mask              = 27,
	eModifierType_SimpleDeform      = 28,
	eModifierType_Multires          = 29,
	eModifierType_Surface           = 30,
	eModifierType_Smoke             = 31,
	eModifierType_ShapeKey          = 32,
	eModifierType_Solidify          = 33,
	eModifierType_Screw             = 34,
	eModifierType_Warp              = 35,
	eModifierType_WeightVGEdit      = 36,
	eModifierType_WeightVGMix       = 37,
	eModifierType_WeightVGProximity = 38,
	eModifierType_Ocean             = 39,
	eModifierType_DynamicPaint      = 40,
	eModifierType_Remesh            = 41,
	eModifierType_Skin              = 42,
	eModifierType_LaplacianSmooth   = 43,
	eModifierType_Triangulate       = 44,
	eModifierType_UVWarp            = 45,
	eModifierType_MeshCache         = 46,
	eModifierType_LaplacianDeform   = 47,
	eModifierType_Wireframe         = 48,
	eModifierType_DataTransfer      = 49,
	eModifierType_NormalEdit        = 50,
	eModifierType_CorrectiveSmooth  = 51,
	eModifierType_MeshSequenceCache = 52,
	eModifierType_SurfaceDeform     = 53,
	eModifierType_NUM_TYPES
} ModifierType;

typedef enum ModifierMode {
	eModifierMode_Realtime          = (1 << 0),
	eModifierMode_Render            = (1 << 1),
	eModifierMode_Editmode          = (1 << 2),
	eModifierMode_OnCage            = (1 << 3),
	eModifierMode_Expanded          = (1 << 4),
	eModifierMode_Virtual           = (1 << 5),
	eModifierMode_ApplyOnSpline     = (1 << 6),
	eModifierMode_DisableTemporary  = (1u << 31)
} ModifierMode;

typedef struct ArmatureModifierData {
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