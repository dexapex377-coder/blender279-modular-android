#ifndef __DNA_CACHEFILE_TYPES_H__
#define __DNA_CACHEFILE_TYPES_H__

struct CacheFile;
struct Object;
struct Main;

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CacheFile {
    struct CacheFile *next, *prev;
} CacheFile;

#ifdef __cplusplus
}
#endif

#endif
