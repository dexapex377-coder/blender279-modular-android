#ifndef __BLI_TASK_H__
#define __BLI_TASK_H__

#include "BLI_utildefines.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*TaskParallelRangeFunc)(void *userdata, const int iter);

static inline void BLI_task_parallel_range(
        int start, int stop,
        void *userdata,
        TaskParallelRangeFunc func,
        const bool use_threading)
{
    (void)use_threading;
    for (int i = start; i < stop; i++) {
        func(userdata, i);
    }
}

#ifdef __cplusplus
}
#endif

#endif
