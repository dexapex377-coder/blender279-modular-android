#ifndef __BKE_ACTION_H__
#define __BKE_ACTION_H__

#include "DNA_action_types.h"

struct bAction;
struct Object;
struct Scene;

void BKE_action_apply(struct Object *ob, struct bAction *act, float ctime);
struct bPoseChannel *BKE_pose_channel_find_name(struct bPose *pose, const char *name);

#endif
