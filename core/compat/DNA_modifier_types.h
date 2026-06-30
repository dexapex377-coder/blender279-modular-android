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
struct FluidsimSettings;

typedef struct ModifierData {
    struct ModifierData *next, *prev;
    int type, mode;
    int stackindex, pad;
    char name[64];  /* MAX_NAME */

    /* XXX for timing info set by caller... solve later? (ton) */
    struct Scene *scene;

    char *error;
} ModifierData;

typedef struct MappingInfoModifierData {
    ModifierData modifier;
    struct Tex *texture;
    struct Object *map_object;
    char uvlayer_name[64];
    int uvlayer_tmp;
    int texmapping;
} MappingInfoModifierData;

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
    char lvl, sculptlvl, renderlvl, totlvl;
    char simple, flags, pad[2];
} MultiresModifierData;

typedef enum {
    eMultiresModifierFlag_ControlEdges = (1 << 0),
    eMultiresModifierFlag_PlainUv      = (1 << 1),
} MultiresModifierFlag;

typedef enum {
    MULTIRES_USE_LOCAL_MMD = 1,
    MULTIRES_USE_RENDER_PARAMS = 2,
    MULTIRES_ALLOC_PAINT_MASK = 4,
    MULTIRES_IGNORE_SIMPLIFY = 8,
} MultiresFlags;

typedef struct HookModifierData {
    ModifierData modifier;
    struct Object *object;
    char subtarget[64];
    char flag;
    char falloff_type;
    char pad[6];
    float parentinv[4][4];
    float cent[3];
    float falloff;
    struct CurveMapping *curfalloff;
    int *indexar;
    int totindex;
    float force;
    char name[64];
} HookModifierData;

enum {
    MOD_HOOK_UNIFORM_SPACE = (1 << 0),
};

enum {
    eHook_Falloff_None   = 0,
    eHook_Falloff_Curve  = 1,
    eHook_Falloff_Sharp  = 2,
    eHook_Falloff_Smooth = 3,
    eHook_Falloff_Root   = 4,
    eHook_Falloff_Linear = 5,
    eHook_Falloff_Const  = 6,
    eHook_Falloff_Sphere = 7,
    eHook_Falloff_InvSquare = 8,
};

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
    char name[64];
    float strength;
    char pad[4];
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

/* *************** FluidsimModifier *************** */
typedef struct FluidsimModifierData {
    ModifierData modifier;
    struct FluidsimSettings *fss;
    struct PointCache *point_cache;
} FluidsimModifierData;

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

/* *************** ParticleInstanceModifier *************** */
typedef struct ParticleInstanceModifierData {
    ModifierData modifier;
    struct Object *ob;
    short psys, flag, axis, pad;
    float position, random_position;
} ParticleInstanceModifierData;

typedef enum {
    eParticleInstanceFlag_Parents   = (1 << 0),
    eParticleInstanceFlag_Children  = (1 << 1),
    eParticleInstanceFlag_Path      = (1 << 2),
    eParticleInstanceFlag_Unborn    = (1 << 3),
    eParticleInstanceFlag_Alive     = (1 << 4),
    eParticleInstanceFlag_Dead      = (1 << 5),
    eParticleInstanceFlag_KeepShape = (1 << 6),
    eParticleInstanceFlag_UseSize   = (1 << 7),
} ParticleInstanceModifierFlag;

/* *************** LaplacianDeformModifier *************** */
typedef struct LaplacianDeformModifierData {
    ModifierData modifier;
    char anchor_grp_name[64];
    int total_verts, repeat;
    float *vertexco;
    void *cache_system;
    short flag, pad[3];
} LaplacianDeformModifierData;

enum {
    MOD_LAPLACIANDEFORM_BIND = 1,
};

/* *************** LaplacianSmoothModifier *************** */
typedef struct LaplacianSmoothModifierData {
    ModifierData modifier;
    float lambda, lambda_border, pad1;
    char defgrp_name[64];
    short flag, repeat;
} LaplacianSmoothModifierData;

enum {
    MOD_LAPLACIANSMOOTH_X               = (1 << 1),
    MOD_LAPLACIANSMOOTH_Y               = (1 << 2),
    MOD_LAPLACIANSMOOTH_Z               = (1 << 3),
    MOD_LAPLACIANSMOOTH_PRESERVE_VOLUME = (1 << 4),
    MOD_LAPLACIANSMOOTH_NORMALIZED      = (1 << 5),
};

/* *************** MaskModifier *************** */
typedef struct MaskModifierData {
    ModifierData modifier;
    struct Object *ob_arm;
    char vgroup[64];
    int mode;
    int flag;
} MaskModifierData;

enum {
    MOD_MASK_INV       = (1 << 0),
    MOD_MASK_MODE_ARM  = 0,
    MOD_MASK_MODE_VGROUP = 1,
};

/* *************** MeshCacheModifier *************** */
enum {
    MOD_MESHCACHE_TYPE_MDD  = 1,
    MOD_MESHCACHE_TYPE_PC2  = 2,
};
enum {
    MOD_MESHCACHE_DEFORM_OVERWRITE = 0,
    MOD_MESHCACHE_DEFORM_INTEGRATE = 1,
};
enum {
    MOD_MESHCACHE_INTERP_NONE   = 0,
    MOD_MESHCACHE_INTERP_LINEAR = 1,
};
enum {
    MOD_MESHCACHE_TIME_FRAME   = 0,
    MOD_MESHCACHE_TIME_SECONDS = 1,
    MOD_MESHCACHE_TIME_FACTOR  = 2,
};
enum {
    MOD_MESHCACHE_PLAY_CFEA = 0,
    MOD_MESHCACHE_PLAY_EVAL = 1,
};

typedef struct MeshCacheModifierData {
    ModifierData modifier;
    char flag;
    char type;
    char time_mode;
    char play_mode;
    char forward_axis;
    char up_axis;
    char flip_axis;
    char interp;
    float factor;
    char deform_mode;
    char pad[7];
    float frame_start;
    float frame_scale;
    float eval_factor;
    float eval_frame;
    float eval_time;
    float eval_length;
    char filepath[1024];
    void *reader;
} MeshCacheModifierData;

/* *************** MeshDeformModifier *************** */
typedef struct MDefInfluence {
    int vertex;
    float weight;
} MDefInfluence;

typedef struct MDefCell {
    int offset;
    int totinfluence;
} MDefCell;

typedef struct MeshDeformModifierData {
    ModifierData modifier;
    struct Object *object;
    char defgrp_name[64];
    short gridsize, flag, pad[2];
    struct MDefInfluence *bindinfluences;
    int *bindoffsets;
    float *bindcagecos;
    int totvert, totcagevert;
    struct MDefCell *dyngrid;
    struct MDefInfluence *dyninfluences;
    int *dynverts;
    int dyngridsize;
    int totinfluence;
    float dyncellmin[3];
    float dyncellwidth;
    float bindmat[4][4];
    float *bindweights;
    float *bindcos;
    void (*bindfunc)(struct Scene *scene, struct MeshDeformModifierData *mmd, struct DerivedMesh *cagedm,
                     float *vertexcos, int totvert, float cagemat[4][4]);
} MeshDeformModifierData;

enum {
    MOD_MDEF_INVERT_VGROUP = (1 << 0),
    MOD_MDEF_DYNAMIC_BIND  = (1 << 1),
};

/* *************** MirrorModifier *************** */
typedef struct MirrorModifierData {
    ModifierData modifier;
    short flag;
    short pad;
    float tolerance;
    float uv_offset[2];
    struct Object *mirror_ob;
} MirrorModifierData;

enum {
    MOD_MIR_CLIPPING  = (1 << 0),
    MOD_MIR_MIRROR_U  = (1 << 1),
    MOD_MIR_MIRROR_V  = (1 << 2),
    MOD_MIR_AXIS_X    = (1 << 3),
    MOD_MIR_AXIS_Y    = (1 << 4),
    MOD_MIR_AXIS_Z    = (1 << 5),
    MOD_MIR_VGROUP    = (1 << 6),
    MOD_MIR_NO_MERGE  = (1 << 7),
};

/* *************** NormalEditModifier *************** */
typedef struct NormalEditModifierData {
    ModifierData modifier;
    char defgrp_name[64];
    struct Object *target;
    short mode;
    short flag;
    short mix_mode;
    char pad[2];
    float mix_factor;
    float mix_limit;
    float offset[3];
    float pad_f1;
} NormalEditModifierData;

enum {
    MOD_NORMALEDIT_MODE_RADIAL        = 0,
    MOD_NORMALEDIT_MODE_DIRECTIONAL   = 1,
};
enum {
    MOD_NORMALEDIT_INVERT_VGROUP          = (1 << 0),
    MOD_NORMALEDIT_USE_DIRECTION_PARALLEL = (1 << 1),
};
enum {
    MOD_NORMALEDIT_MIX_COPY = 0,
    MOD_NORMALEDIT_MIX_ADD  = 1,
    MOD_NORMALEDIT_MIX_SUB  = 2,
    MOD_NORMALEDIT_MIX_MUL  = 3,
};

/* *************** MeshSeqCacheModifier *************** */
typedef struct MeshSeqCacheModifierData {
    ModifierData modifier;
    struct CacheFile *cache_file;
    struct CacheReader *reader;
    char object_path[1024];
    char read_flag;
    char pad[7];
} MeshSeqCacheModifierData;

enum {
    MOD_MESHSEQ_READ_VERT = (1 << 0),
    MOD_MESHSEQ_READ_POLY = (1 << 1),
    MOD_MESHSEQ_READ_UV   = (1 << 2),
    MOD_MESHSEQ_READ_ALL  = MOD_MESHSEQ_READ_VERT | MOD_MESHSEQ_READ_POLY | MOD_MESHSEQ_READ_UV,
};

typedef struct SubsurfModifierData SubsurfModifierData;

/* *************** ShrinkwrapModifier *************** */
typedef struct ShrinkwrapModifierData {
    ModifierData modifier;
    struct Object *target;
    struct Object *auxTarget;
    char vgroup_name[64];
    float keepDist;
    short shrinkType;
    char  shrinkOpts;
    char  pad1;
    float projLimit;
    char  projAxis;
    char subsurfLevels;
    char pad[2];
} ShrinkwrapModifierData;

enum {
    MOD_SHRINKWRAP_NEAREST_SURFACE = 0,
    MOD_SHRINKWRAP_PROJECT         = 1,
    MOD_SHRINKWRAP_NEAREST_VERTEX  = 2,
};

/* Shrinkwrap->shrinkOpts */
enum {
    MOD_SHRINKWRAP_PROJECT_ALLOW_POS_DIR = (1 << 0),
};

/* Shrinkwrap->projAxis */
enum {
    MOD_SHRINKWRAP_PROJECT_OVER_NORMAL   = 0,
};

/* *************** ScrewModifier *************** */
typedef struct ScrewModifierData {
    ModifierData modifier;
    struct Object *ob_axis;
    unsigned int steps;
    unsigned int render_steps;
    unsigned int iter;
    float screw_ofs;
    float angle;
    float merge_dist;
    short flag;
    char axis;
    char pad[5];
} ScrewModifierData;

enum {
    MOD_SCREW_NORMAL_FLIP    = (1 << 0),
    MOD_SCREW_NORMAL_CALC    = (1 << 1),
    MOD_SCREW_OBJECT_OFFSET  = (1 << 2),
    MOD_SCREW_SMOOTH_SHADING = (1 << 5),
    MOD_SCREW_UV_STRETCH_U   = (1 << 6),
    MOD_SCREW_UV_STRETCH_V   = (1 << 7),
    MOD_SCREW_MERGE          = (1 << 8),
};

/* *************** OceanModifier *************** */
typedef struct OceanModifierData {
    ModifierData modifier;
    struct Ocean *ocean;
    struct OceanCache *oceancache;
    int resolution;
    int spatial_size;
    float wind_velocity;
    float damp;
    float smallest_wave;
    float depth;
    float wave_alignment;
    float wave_direction;
    float wave_scale;
    float chop_amount;
    float foam_coverage;
    float time;
    int bakestart;
    int bakeend;
    char cachepath[1024];
    char foamlayername[64];
    char cached;
    char geometry_mode;
    char flag;
    char refresh;
    short repeat_x;
    short repeat_y;
    int seed;
    float size;
    float foam_fade;
    int pad;
} OceanModifierData;

/* *************** RemeshModifier *************** */
typedef enum RemeshModifierFlags {
    MOD_REMESH_FLOOD_FILL     = 1,
    MOD_REMESH_SMOOTH_SHADING = 2,
} RemeshModifierFlags;

typedef enum RemeshModifierMode {
    MOD_REMESH_CENTROID       = 0,
    MOD_REMESH_MASS_POINT     = 1,
    MOD_REMESH_SHARP_FEATURES = 2,
} RemeshModifierMode;

typedef struct RemeshModifierData {
    ModifierData modifier;
    float threshold;
    float scale;
    float hermite_num;
    char depth;
    char flag;
    char mode;
    char pad;
} RemeshModifierData;

enum {
    MOD_OCEAN_GEOM_GENERATE = 0,
    MOD_OCEAN_GEOM_DISPLACE = 1,
    MOD_OCEAN_GEOM_SIM_ONLY = 2,
};
enum {
    MOD_OCEAN_REFRESH_RESET       = (1 << 0),
    MOD_OCEAN_REFRESH_SIM         = (1 << 1),
    MOD_OCEAN_REFRESH_ADD         = (1 << 2),
    MOD_OCEAN_REFRESH_CLEAR_CACHE = (1 << 3),
    MOD_OCEAN_REFRESH_TOPOLOGY    = (1 << 4),
};
enum {
    MOD_OCEAN_GENERATE_FOAM    = (1 << 0),
    MOD_OCEAN_GENERATE_NORMALS = (1 << 1),
};

#ifdef __cplusplus
}
#endif

#endif