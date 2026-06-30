#ifndef __DNA_OBJECT_FLUIDSIM_H__
#define __DNA_OBJECT_FLUIDSIM_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct FluidsimModifierData {
    struct FluidsimModifierData *next, *prev;
    int type, mode;
    int stackindex, pad;
    char name[64];
    struct Scene *scene;
    char *error;
} FluidsimModifierData;

#ifdef __cplusplus
}
#endif

#endif
