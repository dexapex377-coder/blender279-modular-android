#ifndef __DNA_ACTION_TYPES_H__
#define __DNA_ACTION_TYPES_H__

#include "DNA_listBase.h"
#include "DNA_ID.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Bone;
struct Object;
struct bPoseChannel;
struct bMotionPath;

typedef struct bPoseChannel {
    struct bPoseChannel *next, *prev;
    void *prop;
    ListBase constraints;
    char name[64];
    short flag;
    short ikflag;
    short protectflag;
    short agrp_index;
    char constflag;
    char selectflag;
    char drawflag;
    char bboneflag;
    char pad0[4];
    struct Bone *bone;
    struct bPoseChannel *parent;
    struct bPoseChannel *child;
    ListBase iktree;
    ListBase siktree;
    struct bMotionPath *mpath;
    struct Object *custom;
    struct bPoseChannel *custom_tx;
    float custom_scale;
} bPoseChannel;

typedef struct bPose {
    ListBase chanbase;
    void *chanhash;
    short flag, pad;
    unsigned int proxy_layer;
    int pad1;
    float ctime;
    float stride_offset[3];
    float cyclic_offset[3];
    ListBase agroups;
    int active_group;
} bPose;

typedef struct bAction {
    ID id;
    struct AnimData *adt;
    ListBase channels;
    short flag, active_marker;
    int pad;
    float endframe;
} bAction;

#ifdef __cplusplus
}
#endif

#endif
