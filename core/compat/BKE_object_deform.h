#ifndef __BKE_OBJECT_DEFORM_H__
#define __BKE_OBJECT_DEFORM_H__

#ifdef __cplusplus
extern "C" {
#endif

struct Object;
struct bDeformGroup;

struct bDeformGroup *BKE_object_defgroup_add(struct Object *ob);
struct bDeformGroup *BKE_object_defgroup_add_name(struct Object *ob, const char *name);
int BKE_object_defgroup_index_get(struct Object *ob, struct bDeformGroup *dg);
void BKE_object_defgroup_remove(struct Object *ob, struct bDeformGroup *defgroup);
void BKE_object_defgroup_remove_all(struct Object *ob);

#ifdef __cplusplus
}
#endif

#endif
