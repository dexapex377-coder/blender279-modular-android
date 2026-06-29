#ifndef __BLI_UTILDEFINES_ITER_H__
#define __BLI_UTILDEFINES_ITER_H__

/* Iterator utility macros */

#define ITER_BEGIN(ele, iter, ...) \
    { void *iter = NULL; (void)iter; for (int _iter_idx = 0; _iter_idx < (sizeof((const void*[]){__VA_ARGS__})/sizeof(const void*)); _iter_idx++) { void *ele = ((void*[]){__VA_ARGS__})[_iter_idx]; (void)ele; (void)_iter_idx

#define ITER_END }}

#define ITER_INDEX int _iter_idx

#endif
