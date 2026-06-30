#ifndef __DNA_MODIFIER_TYPES_H__
#define __DNA_MODIFIER_TYPES_H__

#include "DNA_scene_types.h"
#include "DNA_cloth_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct PointCache;
struct Cloth;
struct ClothHairData;
struct ClothSolverResult;

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

typedef struct DecimateModifierData {
    ModifierData modifier;

    float percent;
    short iter;
    char delimit;
    char symmetry_axis;
    float angle;

    char defgrp_name[64];
    float defgrp_factor;
    short flag, mode;

    int face_count;
} DecimateModifierData;

enum {
    MOD_DECIM_FLAG_INVERT_VGROUP      = (1 << 0),
    MOD_DECIM_FLAG_TRIANGULATE        = (1 << 1),
    MOD_DECIM_FLAG_ALL_BOUNDARY_VERTS = (1 << 2),
    MOD_DECIM_FLAG_SYMMETRY           = (1 << 3),
};

enum {
    MOD_DECIM_MODE_COLLAPSE,
    MOD_DECIM_MODE_UNSUBDIV,
    MOD_DECIM_MODE_DISSOLVE,
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
    char name[64];
    short defaxis;
    char pad[6];
} CurveModifierData;

enum {
    MOD_CURVE_POSX = 1,
    MOD_CURVE_POSY = 2,
    MOD_CURVE_POSZ = 3,
    MOD_CURVE_NEGX = 4,
    MOD_CURVE_NEGY = 5,
    MOD_CURVE_NEGZ = 6,
};

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

typedef struct BooleanModifierData {
    ModifierData modifier;
    struct Object *object;
    char operation;
    char solver;
    char pad[2];
    float double_threshold;
    int bm_flag;
} BooleanModifierData;

typedef enum {
    eBooleanModifierOp_Intersect  = 0,
    eBooleanModifierOp_Union      = 1,
    eBooleanModifierOp_Difference = 2,
} BooleanModifierOp;

typedef enum {
    eBooleanModifierSolver_Carve    = 0,
    eBooleanModifierSolver_BMesh = 1,
} BooleanSolver;

enum {
    eBooleanModifierBMeshFlag_BMesh_Separate        = (1 << 0),
    eBooleanModifierBMeshFlag_BMesh_NoDissolve      = (1 << 1),
    eBooleanModifierBMeshFlag_BMesh_NoConnectRegions = (1 << 2),
};

typedef struct CastModifierData {
    ModifierData modifier;
    struct Object *object;
    float fac;
    float radius;
    float size;
    char defgrp_name[64];
    short flag, type;
} CastModifierData;

enum {
    MOD_CAST_X                = (1 << 1),
    MOD_CAST_Y                = (1 << 2),
    MOD_CAST_Z                = (1 << 3),
    MOD_CAST_USE_OB_TRANSFORM = (1 << 4),
    MOD_CAST_SIZE_FROM_RADIUS = (1 << 5),
};

enum {
    MOD_CAST_TYPE_SPHERE   = 0,
    MOD_CAST_TYPE_CYLINDER = 1,
    MOD_CAST_TYPE_CUBOID   = 2,
};

typedef struct ClothModifierData {
    ModifierData modifier;

    struct Scene *scene;
    struct Cloth *clothObject;
    struct ClothSimSettings *sim_parms;
    struct ClothCollSettings *coll_parms;
    struct PointCache *point_cache;
    struct ListBase ptcaches;
    struct ClothHairData *hairdata;
    float hair_grid_min[3];
    float hair_grid_max[3];
    int hair_grid_res[3];
    float hair_grid_cellsize;
    struct ClothSolverResult *solver_result;
} ClothModifierData;

typedef struct CollisionModifierData {
    ModifierData modifier;

    struct MVert *x;
    struct MVert *xnew;
    struct MVert *xold;
    struct MVert *current_xnew;
    struct MVert *current_x;
    struct MVert *current_v;
    struct MVertTri *tri;

    unsigned int mvert_num;
    unsigned int tri_num;
    float time_x, time_xnew;
    char is_static;
    char pad[7];

    struct BVHTree *bvhtree;
} CollisionModifierData;

typedef struct CorrectiveSmoothModifierData {
    ModifierData modifier;

    float (*bind_coords)[3];

    unsigned int bind_coords_num;

    float lambda;
    short repeat, flag;
    char smooth_type, rest_source;
    char pad[2];

    char defgrp_name[64];

    float (*delta_cache)[3];
    unsigned int delta_cache_num;
    char pad2[4];
} CorrectiveSmoothModifierData;

typedef struct DataTransferModifierData {
    ModifierData modifier;

    struct Object *ob_source;

    int data_types;

    int vmap_mode;
    int emap_mode;
    int lmap_mode;
    int pmap_mode;

    float map_max_distance;
    float map_ray_radius;
    float islands_precision;

    int pad_i1;

    int layers_select_src[4];
    int layers_select_dst[4];

    int mix_mode;
    float mix_factor;
    char defgrp_name[64];

    int flags;
} DataTransferModifierData;

enum {
    MOD_DATATRANSFER_OBSRC_TRANSFORM = 1 << 0,
    MOD_DATATRANSFER_MAP_MAXDIST     = 1 << 1,
    MOD_DATATRANSFER_INVERT_VGROUP   = 1 << 2,
};

enum {
    MOD_CORRECTIVESMOOTH_SMOOTH_SIMPLE         = 0,
    MOD_CORRECTIVESMOOTH_SMOOTH_LENGTH_WEIGHT  = 1,
};

enum {
    MOD_CORRECTIVESMOOTH_RESTSOURCE_ORCO       = 0,
    MOD_CORRECTIVESMOOTH_RESTSOURCE_BIND       = 1,
};

enum {
    MOD_CORRECTIVESMOOTH_INVERT_VGROUP         = (1 << 0),
    MOD_CORRECTIVESMOOTH_ONLY_SMOOTH           = (1 << 1),
    MOD_CORRECTIVESMOOTH_PIN_BOUNDARY          = (1 << 2),
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

/* *************** DisplaceModifier *************** */
typedef struct DisplaceModifierData {
    ModifierData modifier;
    struct Tex *texture;
    struct Object *map_object;
    char uvlayer_name[64];
    int uvlayer_tmp;
    int texmapping;
    float strength;
    int direction;
    char defgrp_name[64];
    float midlevel;
    int space;
} DisplaceModifierData;

enum {
    MOD_DISP_DIR_X       = 0,
    MOD_DISP_DIR_Y       = 1,
    MOD_DISP_DIR_Z       = 2,
    MOD_DISP_DIR_NOR     = 3,
    MOD_DISP_DIR_RGB_XYZ = 4,
    MOD_DISP_DIR_CLNOR   = 5,
};

enum {
    MOD_DISP_MAP_LOCAL  = 0,
    MOD_DISP_MAP_GLOBAL = 1,
    MOD_DISP_MAP_OBJECT = 2,
    MOD_DISP_MAP_UV     = 3,
};

enum {
    MOD_DISP_SPACE_LOCAL  = 0,
    MOD_DISP_SPACE_GLOBAL = 1,
};

/* *************** EdgeSplitModifier *************** */
typedef struct EdgeSplitModifierData {
    ModifierData modifier;
    float split_angle;
    int flags;
} EdgeSplitModifierData;

enum {
    MOD_EDGESPLIT_FROMANGLE  = (1 << 1),
    MOD_EDGESPLIT_FROMFLAG   = (1 << 2),
};

/* *************** ExplodeModifier *************** */
typedef enum {
    eExplodeFlag_CalcFaces = (1 << 0),
    eExplodeFlag_PaSize    = (1 << 1),
    eExplodeFlag_EdgeCut   = (1 << 2),
    eExplodeFlag_Unborn    = (1 << 3),
    eExplodeFlag_Alive     = (1 << 4),
    eExplodeFlag_Dead      = (1 << 5),
} ExplodeModifierFlag;

typedef struct ExplodeModifierData {
    ModifierData modifier;
    int *facepa;
    short flag, vgroup;
    float protect;
    char uvname[64];
} ExplodeModifierData;

/* *************** ParticleSystemModifier *************** */
typedef struct ParticleSystemModifierData {
    ModifierData modifier;
    struct ParticleSystem *psys;
    struct DerivedMesh *dm_final;
    struct DerivedMesh *dm_deformed;
    int totdmvert, totdmedge, totdmface;
    short flag, pad;
} ParticleSystemModifierData;

typedef enum {
    eParticleSystemFlag_Pars         = (1 << 0),
    eParticleSystemFlag_psys_updated = (1 << 1),
    eParticleSystemFlag_file_loaded  = (1 << 2),
} ParticleSystemModifierFlag;

#ifdef __cplusplus
}
#endif

#endif