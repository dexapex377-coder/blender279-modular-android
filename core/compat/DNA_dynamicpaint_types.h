#ifndef __DNA_DYNAMICPAINT_TYPES_H__
#define __DNA_DYNAMICPAINT_TYPES_H__

#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

struct PaintSurfaceData;
struct PointCache;
struct EffectorWeights;
struct Group;
struct Tex;
struct Object;

enum {
    MOD_DPAINT_SURFACE_F_PTEX     = 0,
    MOD_DPAINT_SURFACE_F_VERTEX   = 1,
    MOD_DPAINT_SURFACE_F_IMAGESEQ = 2,
};

enum {
    MOD_DPAINT_SURFACE_T_PAINT    = 0,
    MOD_DPAINT_SURFACE_T_DISPLACE = 1,
    MOD_DPAINT_SURFACE_T_WEIGHT   = 2,
    MOD_DPAINT_SURFACE_T_WAVE     = 3,
};

typedef struct DynamicPaintSurface {
    struct DynamicPaintSurface *next, *prev;
    struct DynamicPaintCanvasSettings *canvas;
    struct PaintSurfaceData *data;
    struct Group *brush_group;
    struct EffectorWeights *effector_weights;
    struct PointCache *pointcache;
    struct ListBase ptcaches;
    int current_frame;
    char name[64];
    short format, type;
    short disp_type, image_fileformat;
    short effect_ui;
    short preview_id;
    short init_color_type, pad_s;
    int flags, effect;
    int image_resolution, substeps;
    int start_frame, end_frame, pad;
    float init_color[4];
    struct Tex *init_texture;
    char init_layername[64];
    int dry_speed, diss_speed;
    float color_dry_threshold;
    float depth_clamp, disp_factor;
    float spread_speed, color_spread_speed, shrink_speed;
    float drip_vel, drip_acc;
    float influence_scale, radius_scale;
    float wave_damping, wave_speed, wave_timescale, wave_spring, wave_smoothness;
    int pad2;
    char uvlayer_name[64];
    char image_output_path[1024];
    char output_name[64];
    char output_name2[64];
} DynamicPaintSurface;

enum {
    MOD_DPAINT_ACTIVE             = 1 << 0,
    MOD_DPAINT_ANTIALIAS          = 1 << 1,
    MOD_DPAINT_DISSOLVE           = 1 << 2,
    MOD_DPAINT_MULALPHA           = 1 << 3,
    MOD_DPAINT_DISSOLVE_LOG       = 1 << 4,
    MOD_DPAINT_DRY_LOG            = 1 << 5,
    MOD_DPAINT_PREVIEW            = 1 << 6,
    MOD_DPAINT_WAVE_OPEN_BORDERS  = 1 << 7,
    MOD_DPAINT_DISP_INCREMENTAL   = 1 << 8,
    MOD_DPAINT_USE_DRYING         = 1 << 9,
    MOD_DPAINT_OUT1               = 1 << 10,
    MOD_DPAINT_OUT2               = 1 << 11,
};

typedef struct DynamicPaintCanvasSettings {
    struct DynamicPaintModifierData *pmd;
    struct DerivedMesh *dm;
    struct ListBase surfaces;
    short active_sur, flags;
    int pad;
    char error[64];
} DynamicPaintCanvasSettings;

enum {
    MOD_DPAINT_BAKING             = 1 << 1,
};

enum {
    MOD_DPAINT_PART_RAD           = 1 << 0,
    MOD_DPAINT_USE_MATERIAL       = 1 << 1,
    MOD_DPAINT_ABS_ALPHA          = 1 << 2,
    MOD_DPAINT_ERASE              = 1 << 3,
    MOD_DPAINT_RAMP_ALPHA         = 1 << 4,
    MOD_DPAINT_PROX_PROJECT       = 1 << 5,
    MOD_DPAINT_INVERSE_PROX       = 1 << 6,
    MOD_DPAINT_NEGATE_VOLUME      = 1 << 7,
    MOD_DPAINT_DO_SMUDGE          = 1 << 8,
    MOD_DPAINT_VELOCITY_ALPHA     = 1 << 9,
    MOD_DPAINT_VELOCITY_COLOR     = 1 << 10,
    MOD_DPAINT_VELOCITY_DEPTH     = 1 << 11,
    MOD_DPAINT_USES_VELOCITY      = (MOD_DPAINT_DO_SMUDGE | MOD_DPAINT_VELOCITY_ALPHA |
                                     MOD_DPAINT_VELOCITY_COLOR | MOD_DPAINT_VELOCITY_DEPTH),
};

enum {
    MOD_DPAINT_COL_VOLUME         = 0,
    MOD_DPAINT_COL_DIST           = 1,
    MOD_DPAINT_COL_VOLDIST        = 2,
    MOD_DPAINT_COL_PSYS           = 3,
    MOD_DPAINT_COL_POINT          = 4,
};

enum {
    MOD_DPAINT_PRFALL_CONSTANT    = 0,
    MOD_DPAINT_PRFALL_SMOOTH      = 1,
    MOD_DPAINT_PRFALL_RAMP        = 2,
};

enum {
    MOD_DPAINT_WAVEB_DEPTH        = 0,
    MOD_DPAINT_WAVEB_FORCE        = 1,
    MOD_DPAINT_WAVEB_REFLECT      = 2,
    MOD_DPAINT_WAVEB_CHANGE       = 3,
};

enum {
    MOD_DPAINT_RAY_CANVAS         = 0,
    MOD_DPAINT_RAY_BRUSH_AVG      = 1,
    MOD_DPAINT_RAY_ZPLUS          = 2,
};

typedef struct DynamicPaintBrushSettings {
    struct DynamicPaintModifierData *pmd;
    struct DerivedMesh *dm;
    struct ParticleSystem *psys;
    struct Material *mat;
    int flags;
    int collision;
    float r, g, b, alpha;
    float wetness;
    float particle_radius, particle_smooth;
    float paint_distance;
    struct ColorBand *paint_ramp;
    struct ColorBand *vel_ramp;
    short proximity_falloff;
    short wave_type;
    short ray_dir;
    short pad;
    float wave_factor, wave_clamp;
    float max_velocity, smudge_strength;
} DynamicPaintBrushSettings;

typedef struct DynamicPaintModifierData {
    struct DynamicPaintModifierData *next, *prev;
    struct DynamicPaintCanvasSettings *canvas;
    struct DynamicPaintBrushSettings *brush;
    int type;
} DynamicPaintModifierData;

enum {
    MOD_DYNAMICPAINT_TYPE_CANVAS  = (1 << 0),
    MOD_DYNAMICPAINT_TYPE_BRUSH   = (1 << 1),
};

#ifdef __cplusplus
}
#endif

#endif
