#ifndef __DNA_BOID_TYPES_H__
#define __DNA_BOID_TYPES_H__

#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BoidData {
    float health, acc[3];
    short state_id, mode;
} BoidData;

typedef struct BoidSettings {
    int options, last_state_id;
    float landing_smoothness, height;
    float banking, pitch;
    float health, aggression;
    float strength, accuracy, range;
    float air_min_speed, air_max_speed;
    float air_max_acc, air_max_ave;
    float air_personal_space;
    float land_jump_speed, land_max_speed;
    float land_max_acc, land_max_ave;
    float land_personal_space;
    float land_stick_force;
    struct ListBase states;
} BoidSettings;

#ifdef __cplusplus
}
#endif

#endif
