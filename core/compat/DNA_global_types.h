#ifndef __DNA_GLOBAL_TYPES_H__
#define __DNA_GLOBAL_TYPES_H__

#include "BKE_main.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Global {
    struct Main *main;
    int fileflags;
    int rundir;
    int pad;
} Global;

#ifdef __cplusplus
}
#endif

#endif
