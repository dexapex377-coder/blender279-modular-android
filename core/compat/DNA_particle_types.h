#ifndef __DNA_PARTICLE_TYPES_H__
#define __DNA_PARTICLE_TYPES_H__

#include "DNA_ID.h"
#include "DNA_listBase.h"
#include "DNA_object_types.h"
#include "DNA_object_force.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ParticleSettings {
    int type;
    int flag;
    int pad;
    int numkeys;
    int num;
    int num_dmcache;
    int num_vertices;
    int totpart;
    int start, end;
    int lifetime, lifetime_rand;
    int display;
    int render;
    int react;
    int texture;
    int childrens;
    int clump;
    int use_rotations;
    int use_dynamic_rotation;
    int use_path;
    int seed;
    int maxcount;
    int reactnum;
    int timetrack;
    int reacttype;
    int reactflag;
    int reactdist;
    int reactbounce;
    int reactdie;
    int reactstick;
    int reactfalloff;
    int use_emitter;
    int reactnum_rand;
    int use_react;
    int reactkill;
    int reactvel;
    int reactdamp;
    int use_brownian;
    int use_drag;
    int use_force;
    int use_path;
    int use_size;
    int use_rotation;
    int use_velocity;
    int use_rotation_dynamic;
    int use_path_random;
    int use_path_emit;
    int use_path_step;
    int use_path_force;
    int use_path_velocity;
    int use_path_damping;
    int use_path_force_field;
    int use_path_force_field_strength;
    int use_path_force_field_shape;
    int use_path_force_field_flow;
    int use_path_force_field_noise;
    int use_path_force_field_wind;
    int use_path_force_field_gravity;
    int use_path_force_field_harmonic;
    int use_path_force_field_texture;
    int use_path_force_field_object;
    int use_path_force_field_curve;
    int use_path_force_field_point;
    int use_path_force_field_surface;
    int use_path_force_field_lattice;
    int use_path_force_field_text;
    int use_path_force_field_meta;
    int use_path_force_field_empty;
    int use_path_force_field_camera;
    int use_path_force_field_light;
    int use_path_force_field_speaker;
    int use_path_force_field_armature;
    int use_path_force_field_curve;
    int use_path_force_field_mesh;
    int use_path_force_field_surface;
    int use_path_force_field_lattice;
    int use_path_force_field_text;
    int use_path_force_field_meta;
    int use_path_force_field_empty;
    int use_path_force_field_camera;
    int use_path_force_field_light;
    int use_path_force_field_speaker;
    int use_path_force_field_armature;
    int use_path_force_field_curve;
    int use_path_force_field_mesh;
    int use_path_force_field_surface;
    int use_path_force_field_lattice;
    int use_path_force_field_text;
    int use_path_force_field_meta;
    int use_path_force_field_empty;
    int use_path_force_field_camera;
    int use_path_force_field_light;
    int use_path_force_field_speaker;
    int use_path_force_field_armature;
} ParticleSettings;

#ifdef __cplusplus
}
#endif

#endif