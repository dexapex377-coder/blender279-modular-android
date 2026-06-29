#ifndef __BLI_ALLOCA_H__
#define __BLI_ALLOCA_H__

#include <alloca.h>

#define BLI_array_alloca(arr, realsize) (arr = (typeof(arr))alloca(sizeof(*arr) * realsize))

#endif
