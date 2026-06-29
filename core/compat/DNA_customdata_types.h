#ifndef __DNA_CUSTOMDATA_TYPES_H__
#define __DNA_CUSTOMDATA_TYPES_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CustomDataLayer {
    int type;
    int offset;
    int flag;
    int active;
    int active_clone;
    int active_mask;
    int uid;
    char name[64];
    void *data;
} CustomDataLayer;

typedef struct CustomData {
    CustomDataLayer *layers;
    int typemap[64];
    int totlayer, maxlayer;
    int totsize;
    int poolsize;
    struct BLI_mempool *pool;
    struct BLI_mempool *block;
} CustomData;

typedef struct CustomDataExternal {
    int type;
    int totlayer;
    CustomDataLayer *layers;
} CustomDataExternal;

#ifdef __cplusplus
}
#endif

#endif
