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

typedef struct ArrayModifierData {
    ModifierData modifier;
    struct Object *start_cap;
    struct Object *end_cap;
    struct Object *curve_ob;
    struct Object *offset_ob;
    float offset[3];
    float scale[3];
    float length;
    float merge_dist;
    int fit_type;
    int offset_type;
    int flags;
    int count;
} ArrayModifierData;

enum {
    MOD_ARR_FIXEDCOUNT = 0,
    MOD_ARR_FITLENGTH  = 1,
    MOD_ARR_FITCURVE   = 2,
};

enum {
    MOD_ARR_OFF_CONST    = (1 << 0),
    MOD_ARR_OFF_RELATIVE = (1 << 1),
    MOD_ARR_OFF_OBJ      = (1 << 2),
};

enum {
    MOD_ARR_MERGE      = (1 << 0),
    MOD_ARR_MERGEFINAL = (1 << 1),
};

typedef struct BuildModifierData {
    ModifierData modifier;
    float start, length;
    short flag;
    short randomize;
    int seed;
} BuildModifierData;

enum {
    MOD_BUILD_FLAG_RANDOMIZE = (1 << 0),
    MOD_BUILD_FLAG_REVERSE   = (1 << 1),
};

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

    short deformflag, multi;
    int pad2;
    struct Object *object;
    float *prevCos;
    char defgrp_name[64];
} ArmatureModifierData;

typedef struct BevelModifierData {
    ModifierData modifier;
    float value;
    int res;
    short flags;
    short val_flags;
    short lim_flags;
    short e_flags;
    short mat;
    short pad;
    int pad2;
    float profile;
    float bevel_angle;
    char defgrp_name[64];
} BevelModifierData;

enum {
    MOD_BEVEL_VERT        = (1 << 1),
    MOD_BEVEL_ANGLE       = (1 << 3),
    MOD_BEVEL_WEIGHT      = (1 << 4),
    MOD_BEVEL_VGROUP      = (1 << 5),
    MOD_BEVEL_EMIN        = (1 << 7),
    MOD_BEVEL_EMAX        = (1 << 8),
    MOD_BEVEL_OVERLAP_OK  = (1 << 13),
    MOD_BEVEL_EVEN_WIDTHS = (1 << 14),
};

enum {
    MOD_BEVEL_AMT_OFFSET = 0,
    MOD_BEVEL_AMT_WIDTH  = 1,
    MOD_BEVEL_AMT_DEPTH  = 2,
    MOD_BEVEL_AMT_PERCENT = 3,
    MOD_BEVEL_AMT_ABSOLUTE = 4,
};

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