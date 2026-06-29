#ifndef __BKE_DISPLIST_H__
#define __BKE_DISPLIST_H__

struct Scene;
struct Object;
struct ListBase;

void BKE_displist_make_curveTypes(struct Scene *scene, struct Object *ob, bool for_render);
void BKE_displist_free(struct ListBase *lb);
void BKE_displist_copy(struct ListBase *dst, struct ListBase *src);

#endif
