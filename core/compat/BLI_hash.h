#ifndef __BLI_HASH_H__
#define __BLI_HASH_H__

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

unsigned int BLI_hash_int_2d(unsigned int x, unsigned int y);
unsigned int BLI_hash_int_3d(unsigned int x, unsigned int y, unsigned int z);
float BLI_hash_int_2d_to_float(unsigned int x, unsigned int y);
float BLI_hash_int_3d_to_float(unsigned int x, unsigned int y, unsigned int z);
unsigned int BLI_hash_string(const char *str);

#ifdef __cplusplus
}
#endif

#endif
