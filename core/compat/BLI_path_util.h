#ifndef __BLI_PATH_UTIL_H__
#define __BLI_PATH_UTIL_H__

void BLI_make_file_string(const char *relabase, char *string, const char *dir, const char *file);
void BLI_cleanup_path(const char *relabase, char *path);
bool BLI_path_is_rel(const char *path);

#endif
