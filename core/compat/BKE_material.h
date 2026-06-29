#ifndef __BKE_MATERIAL_H_H__
#define __BKE_MATERIAL_H_H__

#include "DNA_material_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Material *BKE_material_add(struct ID *id, const char *name);
struct Material *BKE_material_from_object(struct Object *ob);
void BKE_material_resize_object(struct Object *ob, int totcol);
void BKE_material_assign(struct Object *ob, struct Material *ma, int actcol);
int BKE_object_material_get_index(struct Object *ob, struct Material *ma);

#ifdef __cplusplus
}
#endif

#endif
