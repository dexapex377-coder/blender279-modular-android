#ifndef __DNA_CUSTOMDATA_TYPES_H__
#define __DNA_CUSTOMDATA_TYPES_H__

#ifdef __cplusplus
extern "C" {
#endif

/* CustomData types */
enum {
    CD_MVERT = 0,
    CD_MEDGE = 1,
    CD_MFACE = 2,
    CD_MLOOP = 3,
    CD_MPOLY = 4,
    CD_MTFACE = 5,
    CD_MCOL = 6,
    CD_ORIGINDEX = 7,
    CD_NORMAL = 8,
    CD_MDEFORMVERT = 13,
};

#define CD_MASK_MDEFORMVERT (1 << CD_MDEFORMVERT)

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
