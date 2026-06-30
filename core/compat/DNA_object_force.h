#ifndef __DNA_OBJECT_FORCE_H__
#define __DNA_OBJECT_FORCE_H__

#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum PFieldType {
    PFIELD_NULL   = 0,
    PFIELD_FORCE  = 1,
    PFIELD_VORTEX = 2,
    PFIELD_MAGNET = 3,
    PFIELD_WIND   = 4,
    PFIELD_GUIDE      = 5,
    PFIELD_TEXTURE    = 6,
    PFIELD_HARMONIC   = 7,
    PFIELD_CHARGE     = 8,
    PFIELD_LENNARDJ   = 9,
    PFIELD_BOID       = 10,
    PFIELD_TURBULENCE = 11,
    PFIELD_DRAG       = 12,
    PFIELD_SMOKEFLOW  = 13,
    NUM_PFIELD_TYPES
} PFieldType;

typedef struct PartDeflect {
    int   flag;
    short deflect;
    short forcefield;
    short falloff;
    short shape;
    short tex_mode;
    short kink, kink_axis;
    short zdir;

    float f_strength;
    float f_damp;
    float f_flow;
    float f_size;

    float f_power;
    float maxdist;
    float mindist;
    float f_power_r;
    float maxrad;
    float minrad;

    float pdef_damp;
    float pdef_rdamp;
    float pdef_perm;
    float pdef_frict;
    float pdef_rfrict;
    float pdef_stickness;

    float absorption;

    float pdef_sbdamp;
    float pdef_sbift;
    float pdef_sboft;

    float clump_fac, clump_pow;
    float kink_freq, kink_shape, kink_amp, free_end;

    float tex_nabla;
    struct Tex *tex;

    struct RNG *rng;
    float f_noise;
    int seed;

    struct Object *f_source;
} PartDeflect;

typedef struct EffectorWeights {
    struct Group *group;

    float weight[14];
    float global_gravity;
    short flag, rt[3];
    int pad;
} EffectorWeights;

#define EFF_WEIGHT_DO_HAIR      1

#define BPHYS_DATA_INDEX        0
#define BPHYS_DATA_LOCATION     1
#define BPHYS_DATA_SMOKE_LOW    1
#define BPHYS_DATA_VELOCITY     2
#define BPHYS_DATA_SMOKE_HIGH   2
#define BPHYS_DATA_ROTATION     3
#define BPHYS_DATA_DYNAMICPAINT 3
#define BPHYS_DATA_AVELOCITY    4
#define BPHYS_DATA_XCONST       4
#define BPHYS_DATA_SIZE         5
#define BPHYS_DATA_TIMES        6
#define BPHYS_DATA_BOIDS        7

#define BPHYS_TOT_DATA          8

#define BPHYS_EXTRA_FLUID_SPRINGS   1

typedef struct PTCacheExtra {
    struct PTCacheExtra *next, *prev;
    unsigned int type, totdata;
    void *data;
} PTCacheExtra;

typedef struct PTCacheMem {
    struct PTCacheMem *next, *prev;
    unsigned int frame, totpoint;
    unsigned int data_types, flag;

    void *data[BPHYS_TOT_DATA];
    void *cur[BPHYS_TOT_DATA];

    struct ListBase extradata;
} PTCacheMem;

typedef struct PointCache {
    struct PointCache *next, *prev;
    int flag;

    int step;
    int simframe;
    int startframe;
    int endframe;
    int editframe;
    int last_exact;
    int last_valid;
    int pad;

    int totpoint;
    int index;
    short compression, rt;

    char name[64];
    char prev_name[64];
    char info[64];
    char path[1024];
    char *cached_frames;
    struct ListBase mem_cache;

    struct PTCacheEdit *edit;
    void (*free_edit)(struct PTCacheEdit *edit);
} PointCache;

typedef struct SBVertex {
    float vec[4];
} SBVertex;

#define PTCACHE_BAKED 1

#ifdef __cplusplus
}
#endif

#endif
