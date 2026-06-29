#ifndef __DNA_OBJECT_FORCE_H__
#define __DNA_OBJECT_FORCE_H__

#include "DNA_object_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ObjectForce {
    struct Object *ob;
    int flag;
    int type;
    float strength;
    float distance;
    float flow;
    float noise;
    float seed;
} ObjectForce;

#ifdef __cplusplus
}
#endif

#endif