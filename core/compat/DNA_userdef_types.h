#ifndef __DNA_USERDEF_TYPES_H__
#define __DNA_USERDEF_TYPES_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct UserDef {
    int pad;
    int flag;
    float pad2;
} UserDef;

extern UserDef U;

#ifdef __cplusplus
}
#endif

#endif
