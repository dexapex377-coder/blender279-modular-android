#ifndef __BLI_SORT_H__
#define __BLI_SORT_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

void BLI_qsort(void *base, size_t n, size_t size, int (*cmp)(const void *, const void *));

#ifdef __cplusplus
}
#endif

#endif
