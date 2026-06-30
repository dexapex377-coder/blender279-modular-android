#ifndef __BLI_FILEOPS_H__
#define __BLI_FILEOPS_H__

#include <stdio.h>
#include <stdbool.h>

bool BLI_exists(const char *path);
bool BLI_is_dir(const char *path);
bool BLI_is_file(const char *path);
size_t BLI_file_descriptor_size(int file);
size_t BLI_file_size(const char *path);

FILE *BLI_fopen(const char *filename, const char *mode);
int BLI_open(const char *filename, int oflag, int pmode);

int BLI_rename(const char *from, const char *to);

#endif
