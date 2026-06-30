#ifndef __BKE_CACHEFILE_H__
#define __BKE_CACHEFILE_H__

struct Main;
struct Scene;
struct Object;

void BKE_cachefile_init(struct Main *bmain);
struct CacheFile *BKE_cachefile_new(struct Main *bmain, const char *name);
void BKE_cachefile_reload(struct Depsgraph *depsgraph, struct CacheFile *cache_file);
void BKE_cachefile_unpack(struct Main *bmain, struct Scene *scene, struct Object *ob, int unpack_mode);

#endif
