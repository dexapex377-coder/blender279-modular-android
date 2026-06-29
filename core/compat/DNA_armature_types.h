#ifndef __DNA_ARMATURE_TYPES_H__
#define __DNA_ARMATURE_TYPES_H__

#include "DNA_ID.h"
#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Armature {
    ID id;
    struct ListBase bonebase;
    struct Pose *pose;
    int flag;
    int active_bone;
    float ghost_size;
    int edit_bone;
    struct Bone *bones;
} Armature;

typedef struct ArmatureModifierData ArmatureModifierData;

#ifdef __cplusplus
}
#endif

#endif