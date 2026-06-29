#ifndef __BKE_KEY_H__
#define __BKE_KEY_H__

#include "DNA_key_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Key *BKE_key_add(struct ID *id);
struct Key *BKE_key_from_object(struct Object *ob);
struct KeyBlock *BKE_keyblock_add(struct Key *key, const char *name);
struct KeyBlock *BKE_keyblock_find_by_name(struct Key *key, const char *name);
void BKE_keyblock_convert_to_mesh(struct KeyBlock *kb, struct Mesh *me);
void BKE_keyblock_convert_from_mesh(struct Mesh *me, struct Key *key, struct KeyBlock *kb);
int BKE_keyblock_is_basis(struct Key *key, int index);
void BKE_keyblock_update_from_mesh(struct Mesh *me, struct Key *key);

#ifdef __cplusplus
}
#endif

#endif
