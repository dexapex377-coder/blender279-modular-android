#ifndef __BKE_OBJECT_H__
#define __BKE_OBJECT_H__

#include "DNA_object_types.h"

struct Object;
struct Scene;
struct DerivedMesh;

bool BKE_object_is_in_editmode(const struct Object *ob);
void BKE_object_handle_update(struct Scene *scene, struct Object *ob);

#endif
