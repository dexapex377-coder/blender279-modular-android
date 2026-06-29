#ifndef __DEPSGRAPH_PRIVATE_H__
#define __DEPSGRAPH_PRIVATE_H__

#include "BKE_main.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Depsgraph Depsgraph;
typedef struct DepsNode DepsNode;
typedef struct DepsRelation DepsRelation;

void DEG_id_type_tag(struct Main *bmain, int id_type);
void DEG_relations_tag_update(struct Main *bmain);

#ifdef __cplusplus
}
#endif

#endif