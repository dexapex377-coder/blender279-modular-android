#ifndef __DNA_PARTICLE_TYPES_H__
#define __DNA_PARTICLE_TYPES_H__

#include "DNA_defs.h"
#include "DNA_ID.h"

struct AnimData;
struct CurveMapping;
struct PartDeflect;
struct Curve;
struct Group;
struct ListBase;
struct Object;
struct Ipo;
struct PointCache;
struct MTex;
struct KDTree;
struct BVHTree;
struct LatticeDeformData;
struct ParticleCacheKey;
struct PTCacheEdit;
struct ParticleSpring;
struct ChildParticle;
struct ParticleTarget;
struct ParticleDupliWeight;
struct ParticleRenderData;
struct ParticleDrawData;
struct DerivedMesh;
struct BoidSettings;
struct SPHFluidSettings;
struct ClothModifierData;
struct PointCache;
struct EffectorWeights;
struct Group;
struct ParticleSettings;
struct ParticleData;
struct ParticleSystem;
struct ParticleKey;
struct HairKey;
struct BoidParticle;

typedef struct ParticleKey {
    float co[3];
    float vel[3];
    float rot[4];
    float ave[3];
    float time;
} ParticleKey;

typedef struct HairKey {
    float co[3];
    float time;
    float weight;
    short editflag;
    short pad;
    float world_co[3];
} HairKey;

typedef struct BoidParticle {
    struct Object *ground;
    struct BoidData data;
    float gravity[3];
    float wander[3];
    float rt;
} BoidParticle;

typedef struct ParticleSpring {
    float rest_length;
    unsigned int particle_index[2], delete_flag;
} ParticleSpring;

typedef struct ChildParticle {
    int num, parent;
    int pa[4];
    float w[4];
    float fuv[4], foffset;
    float rt;
} ChildParticle;

typedef struct ParticleTarget {
    struct ParticleTarget *next, *prev;
    struct Object *ob;
    int psys;
    short flag, mode;
    float time, duration;
} ParticleTarget;

typedef struct ParticleDupliWeight {
    struct ParticleDupliWeight *next, *prev;
    struct Object *ob;
    short count;
    short flag;
    short index, rt;
} ParticleDupliWeight;

typedef struct ParticleData {
    ParticleKey state;
    ParticleKey prev_state;
    HairKey *hair;
    ParticleKey *keys;
    BoidParticle *boid;
    int totkey;
    float time, lifetime;
    float dietime;
    int num;
    int num_dmcache;
    float fuv[4], foffset;
    float size;
    float sphdensity;
    int pad;
    int hair_index;
    short flag;
    short alive;
} ParticleData;

typedef struct SPHFluidSettings {
    float radius, spring_k, rest_length;
    float plasticity_constant, yield_ratio;
    float plasticity_balance, yield_balance;
    float viscosity_omega, viscosity_beta;
    float stiffness_k, stiffness_knear, rest_density;
    float buoyancy;
    int flag, spring_frames;
    short solver;
    short pad[3];
} SPHFluidSettings;

#define SPH_VISCOELASTIC_SPRINGS    1
#define SPH_CURRENT_REST_LENGTH     2
#define SPH_FAC_REPULSION           4
#define SPH_FAC_DENSITY             8
#define SPH_FAC_RADIUS              16
#define SPH_FAC_VISCOSITY           32
#define SPH_FAC_REST_LENGTH         64

#define SPH_SOLVER_DDR              0
#define SPH_SOLVER_CLASSICAL        1

typedef struct ParticleSettings {
    ID id;
    struct AnimData *adt;
    struct BoidSettings *boids;
    struct SPHFluidSettings *fluid;
    struct EffectorWeights *effector_weights;
    struct Group *collision_group;
    int flag, rt;
    short type, from, distr, texact;
    short phystype, rotmode, avemode, reactevent;
    int draw, pad1;
    short draw_as, draw_size, childtype, pad2;
    short ren_as, subframes, draw_col;
    short draw_step, ren_step;
    short hair_step, keys_step;
    short adapt_angle, adapt_pix;
    short disp, omat, interpolation, integrator;
    short rotfrom DNA_DEPRECATED;
    short kink, kink_axis;
    short bb_align, bb_uv_split, bb_anim, bb_split_offset;
    float bb_tilt, bb_rand_tilt, bb_offset[2], bb_size[2], bb_vel_head, bb_vel_tail;
    float color_vec_max;
    short simplify_flag, simplify_refsize;
    float simplify_rate, simplify_transition, simplify_viewport;
    float sta, end, lifetime, randlife;
    float timetweak, courant_target;
    float jitfac, eff_hair, grid_rand, ps_offset[1];
    int totpart, userjit, grid_res, effector_amount;
    short time_flag, time_pad[3];
    float normfac, obfac, randfac, partfac, tanfac, tanphase, reactfac;
    float ob_vel[3];
    float avefac, phasefac, randrotfac, randphasefac;
    float mass, size, randsize;
    float acc[3], dragfac, brownfac, dampfac;
    float randlength;
    int child_flag;
    int pad3;
    int child_nbr, ren_child_nbr;
    float parents, childsize, childrandsize;
    float childrad, childflat;
    float clumpfac, clumppow;
    float kink_amp, kink_freq, kink_shape, kink_flat;
    float kink_amp_clump;
    int kink_extra_steps, pad4;
    float kink_axis_random, kink_amp_random;
    float rough1, rough1_size;
    float rough2, rough2_size, rough2_thres;
    float rough_end, rough_end_shape;
    float clength, clength_thres;
    float parting_fac;
    float parting_min, parting_max;
    float branch_thres;
    float draw_line[2];
    float path_start, path_end;
    int trail_count;
    int keyed_loops;
    struct CurveMapping *clumpcurve;
    struct CurveMapping *roughcurve;
    float clump_noise_size;
    float bending_random;
    struct MTex *mtex[18];
    struct Group *dup_group;
    struct ListBase dupliweights;
    struct Group *eff_group DNA_DEPRECATED;
    struct Object *dup_ob;
    struct Object *bb_ob;
    struct Ipo *ipo DNA_DEPRECATED;
    struct PartDeflect *pd;
    struct PartDeflect *pd2;
    short use_modifier_stack;
    short pad5[3];
} ParticleSettings;

typedef struct ParticleSystem {
    struct ParticleSystem *next, *prev;
    ParticleSettings *part;
    ParticleData *particles;
    ChildParticle *child;
    struct PTCacheEdit *edit;
    void (*free_edit)(struct PTCacheEdit *edit);
    struct ParticleCacheKey **pathcache;
    struct ParticleCacheKey **childcache;
    struct ListBase pathcachebufs, childcachebufs;
    struct ClothModifierData *clmd;
    struct DerivedMesh *hair_in_dm, *hair_out_dm;
    struct Object *target_ob;
    struct LatticeDeformData *lattice_deform_data;
    struct Object *parent;
    struct ListBase targets;
    char name[64];
    float imat[4][4];
    float cfra, tree_frame, bvhtree_frame;
    int seed, child_seed;
    int flag, totpart, totunexist, totchild, totcached, totchildcache;
    short recalc, target_psys, totkeyed, bakespace;
    char bb_uvname[3][64];
    short vgroup[12], vg_neg, rt3;
    struct ParticleRenderData *renderdata;
    struct PointCache *pointcache;
    struct ListBase ptcaches;
    struct ListBase *effectors;
    ParticleSpring *fluid_springs;
    int tot_fluidsprings, alloc_fluidsprings;
    struct KDTree *tree;
    struct BVHTree *bvhtree;
    struct ParticleDrawData *pdd;
    float dt_frac;
    float lattice_strength;
} ParticleSystem;

typedef enum eParticleDrawFlag {
    PART_DRAW_VEL           = (1 << 0),
    PART_DRAW_GLOBAL_OB     = (1 << 1),
    PART_DRAW_SIZE          = (1 << 2),
    PART_DRAW_EMITTER       = (1 << 3),
    PART_DRAW_HEALTH        = (1 << 4),
    PART_ABS_PATH_TIME      = (1 << 5),
    PART_DRAW_COUNT_GR      = (1 << 6),
    PART_DRAW_BB_LOCK       = (1 << 1 << 7,
    PART_DRAW_ROTATE_OB     = 1 << 7,
    PART_DRAW_PARENT        = 1 << 8,
    PART_DRAW_NUM           = 1 << 9,
    PART_DRAW_RAND_GR       = 1 << 10,
    PART_DRAW_REN_ADAPT     = 1 << 11,
    PART_DRAW_VEL_LENGTH    = 1 << 12,
    PART_DRAW_MAT_COL       = 1 << 13,
    PART_DRAW_WHOLE_GR      = 1 << 14,
    PART_DRAW_REN_STRAND    = 1 << 15,
    PART_DRAW_NO_SCALE_OB   = 1 << 16,
    PART_DRAW_GUIDE_HAIRS   = 1 << 17,
    PART_DRAW_HAIR_GRID     = 1 << 18,
} eParticleDrawFlag;

typedef enum eParticleFlag {
    PART_STICKY       = (1 << 0),
    PART_DIEHIT       = (1 << 1),
    PART_CACHED       = (1 << 2),
    PART_CHILD        = (1 << 3),
    PART_ROT_DYN      = (1 << 4),
    PART_UNBORN       = (1 << 5),
    PART_DYING        = (1 << 6),
    PART_DEAD         = (1 << 7),
    PART_VECTOR_ROT   = (1 << 8),
    PART_ABS_PARENT   = (1 << 9),
} eParticleFlag;

#ifdef __cplusplus
extern "C" {
#endif

void BKE_particle_system_free(ParticleSystem *psys);

#ifdef __cplusplus
}
#endif

#endif /* __DNA_PARTICLE_TYPES_H__ */