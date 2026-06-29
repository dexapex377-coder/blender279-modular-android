#ifndef __BKE_LIBRARY_H__
#define __BKE_LIBRARY_H__

#include "DNA_listBase.h"

struct Main;
struct Library;

struct Library *BKE_library_new(struct Main *bmain, const char *name);
void BKE_library_free(struct Library *lib);
void BKE_library_make_local(struct Main *bmain, const void *id, const char *name, int flags);
int BKE_library_exists(struct Main *bmain, const char *name);
void BKE_library_filepath_set(struct Library *lib, const char *filepath);

#endif
