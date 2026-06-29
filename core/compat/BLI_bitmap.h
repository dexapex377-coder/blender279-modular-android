#ifndef __BLI_BITMAP_H__
#define __BLI_BITMAP_H__

#include <string.h>
#include <stdlib.h>

#define BLI_BITMAP_SIZE(n) ((n + 7) / 8)
#define BLI_BITMAP_NEW(n, str) ((unsigned int *)calloc(1, BLI_BITMAP_SIZE(n)))
#define BLI_BITMAP_FREE(bitmap) free(bitmap)
#define BLI_BITMAP_TEST(bitmap, bit) ((bitmap)[(bit) >> 5] & (1u << ((bit) & 31)))
#define BLI_BITMAP_SET(bitmap, bit) ((bitmap)[(bit) >> 5] |= (1u << ((bit) & 31)))
#define BLI_BITMAP_CLR(bitmap, bit) ((bitmap)[(bit) >> 5] &= ~(1u << ((bit) & 31)))
#define BLI_BITMAP_GET(bitmap, bit) BLI_BITMAP_TEST(bitmap, bit)
#define BLI_BITMAP_SET_ALL(bitmap, bit, set) ((set) ? BLI_BITMAP_SET(bitmap, bit) : BLI_BITMAP_CLR(bitmap, bit))

typedef unsigned int BLI_bitmap;

#endif
