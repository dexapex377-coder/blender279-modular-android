#ifndef __DNA_CLOTH_TYPES_H__
#define __DNA_CLOTH_TYPES_H__

#include "DNA_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ClothSimSettings {
    struct LinkNode *cache;
    float mingoal;
    float Cdis;
    float Cvi;
    float gravity[3];
    float dt;
    float mass;
    float structural;
    float shear;
    float bending;
    float max_bend;
    float max_struct;
    float max_shear;
    float max_sewing;
    float avg_spring_len;
    float timescale;
    float time_scale;
    float maxgoal;
    float eff_force_scale;
    float eff_wind_scale;
    float sim_time_old;
    float defgoal;
    float goalspring;
    float goalfrict;
    float velocity_smooth;
    float density_target;
    float density_strength;
    float collider_friction;
    float vel_damping;
    float shrink_min;
    float shrink_max;
    float bending_damping;
    float voxel_cell_size;
    int pad;
    int stepsPerFrame;
    int flags;
    int preroll DNA_DEPRECATED;
    int maxspringlen;
    short solver_type;
    short vgroup_bend;
    short vgroup_mass;
    short vgroup_struct;
    short vgroup_shrink;
    short shapekey_rest;
    short presets;
    short reset;
    char pad0[4];
    struct EffectorWeights *effector_weights;
} ClothSimSettings;

typedef struct ClothCollSettings {
    struct LinkNode *collision_list;
    float epsilon;
    float self_friction;
    float friction;
    float damping;
    float selfepsilon;
    float repel_force, distance_repel;
    int flags;
    short self_loop_count;
    short loop_count;
    int pad;
    struct Group *group;
    short vgroup_selfcol;
    short pad2[3];
} ClothCollSettings;

#ifdef __cplusplus
}
#endif

#endif
