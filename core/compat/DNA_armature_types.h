#ifndef __DNA_ARMATURE_TYPES_H__
#define __DNA_ARMATURE_TYPES_H__

#include "DNA_ID.h"
#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

struct AnimData;
struct EditBone;

typedef struct Bone {
    struct Bone *next, *prev;
    void *prop;
    struct Bone *parent;
    ListBase childbase;
    char name[64];
    float roll;
    float head[3];
    float tail[3];
    float bone_mat[3][3];
    int flag;
    float arm_head[3];
    float arm_tail[3];
    float arm_mat[4][4];
    float arm_roll;
    float dist, weight;
    float xwidth, length, zwidth;
    float ease1, ease2;
    float rad_head, rad_tail;
    float roll1, roll2;
    float curveInX, curveInY;
} Bone;

#define BONE_SELECTED 1

typedef struct bArmature {
    ID id;
    struct AnimData *adt;
    ListBase bonebase;
    ListBase chainbase;
    ListBase *edbo;
    struct Bone *act_bone;
    struct EditBone *act_edbone;
    int flag;
    int drawtype;
    short layer;
    short layer_protected;
    int layer_used;
    char ghostype;
    char ghost_step;
    char ghost_size;
    char flag2;
    char pathlength;
    char ik_solver;
    short ghost_bc;
    short ghost_bc_threshold;
    short pad2;
    float ghost_frame;
    float ghost_stepf;
    short pathsteps;
    short pad;
} bArmature;

enum {
    ARM_HAS_VIZ_DEPS = (1 << 5),
};

#ifdef __cplusplus
}
#endif

#endif
