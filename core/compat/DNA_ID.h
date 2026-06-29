#ifndef __DNA_ID_H__
#define __DNA_ID_H__

#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ID {
    void *next, *prev;
    struct ID *newid;
    struct ID *lib;
    char name[66];
    short flag;
    int us;
    int icon_id;
    int tag;
    void *properties;
} ID;

#define LIB_TAG_ID_RECALC 1

#ifdef __cplusplus
}
#endif

#endif
