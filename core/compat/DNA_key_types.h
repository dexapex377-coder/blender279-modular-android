#ifndef __DNA_KEY_TYPES_H__
#define __DNA_KEY_TYPES_H__

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
    float vgroup;
} KeyBlock;

typedef struct Key {
    struct Key *next, *prev;
    struct ID id;
    int type;
    int totkey;
    int totelem;
    int refkey;
    float ctime;
    float curval;
    char refkey_name[64];
    KeyBlock *blocks;
} Key;

#ifdef __cplusplus
}
#endif

#endif
