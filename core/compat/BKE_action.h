#ifndef __BKE_ACTION_H__
#define __BKE_ACTION_H__

struct bAction;
struct Object;
struct Scene;

void BKE_action_apply(struct Object *ob, struct bAction *act, float ctime);

#endif
