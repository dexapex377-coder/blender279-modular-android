#ifndef __DNA_GROUP_TYPES_H__
#define __DNA_GROUP_TYPES_H__

#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Group {
    ID id;
    struct AnimData *adt;
    ListBase object;
} Group;

#ifdef __cplusplus
}
#endif

#endif
