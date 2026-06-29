#ifndef __BKE_GLOBAL_H__
#define __BKE_GLOBAL_H__

#include "BKE_main.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Global {
    struct Main *main;
    char ima[1024], lib[1024];
    bool relbase_valid;
    bool file_loaded;
    bool save_over;
    struct ListBase recent_files;
    bool is_break;
    bool background;
    bool factory_startup;
    short moving;
    bool is_rendering;
    short debug_value;
    int debug;
} Global;

extern Global G;

/* Global flags */
#define G_MOVING 1
#define G_RENDER 2
#define G_DEBUG 1

#ifdef __cplusplus
}
#endif

#endif