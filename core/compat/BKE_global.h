#ifndef __BKE_GLOBAL_H__
#define __BKE_GLOBAL_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Global {
    int f;
    int moving;
    int pad;
} Global;

extern Global G;

/* Global flags */
#define G_MOVING 1
#define G_RENDER 2

#ifdef __cplusplus
}
#endif

#endif
