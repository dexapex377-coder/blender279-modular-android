#ifndef __DNA_KEY_TYPES_H__
#define __DNA_KEY_TYPES_H__

#include "DNA_ID.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct KeyBlock {
    struct KeyBlock *next, *prev;
    short type;
    short flag;
    int totelem;
    int refkey;
    float *data;
    char name[64];
    float curval;
    int uid;
    short relative;
    short pad;
    float vgroup;
    float pos[3];
} KeyBlock;

typedef struct Key {
    struct Key *next, *prev;
    struct ID id;
    struct AnimData *adt;
    KeyBlock *refkey;
    char elemstr[32];
    int elemsize;
    int pad;
    ListBase block;
    void *ipo;
    ID *from;
    int totkey;
    short flag;
    char type;
    char pad2;
    float ctime;
    int uidgen;
} Key;

/* Key types */
enum {
    KEY_NORMAL   = 0,
    KEY_RELATIVE = 1,
};

#ifdef __cplusplus
}
#endif

#endif
