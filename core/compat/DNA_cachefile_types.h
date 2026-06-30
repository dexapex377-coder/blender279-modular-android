#ifndef __DNA_CACHEFILE_TYPES_H__
#define __DNA_CACHEFILE_TYPES_H__

#include "DNA_listBase.h"
#include "DNA_ID.h"

#ifdef __cplusplus
extern "C" {
#endif

struct AnimData;
struct AbcArchiveHandle;

typedef struct CacheFile {
    ID id;
    struct AnimData *adt;
    struct AbcArchiveHandle *handle;
    void *handle_mutex;
    ListBase object_paths;
    char filepath[1024];
    char is_sequence;
    char forward_axis;
    char up_axis;
    char override_frame;
    float scale;
    float frame;
    short flag;
    short draw_flag;
} CacheFile;

#ifdef __cplusplus
}
#endif

#endif
