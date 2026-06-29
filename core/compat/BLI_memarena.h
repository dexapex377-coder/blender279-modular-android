#ifndef __BLI_MEMARENA_H__
#define __BLI_MEMARENA_H__

#include <stdlib.h>

#define MEM_SIZE_OPTIMAL(x) (x)
#define BLI_MEMARENA_STD_BUFSIZE MEM_SIZE_OPTIMAL(1 << 14)

#ifdef __cplusplus
extern "C" {
#endif

typedef struct MemArena MemArena;

MemArena *BLI_memarena_new(size_t bufsize, const char *name);
void BLI_memarena_free(MemArena *arena);
void BLI_memarena_clear(MemArena *arena);
void *BLI_memarena_alloc(MemArena *arena, size_t size);
void *BLI_memarena_calloc(MemArena *arena, size_t size);
void *BLI_memarena_realloc(MemArena *arena, void *ptr, size_t oldsize, size_t newsize);
void BLI_memarena_use_malloc(MemArena *arena);
void BLI_memarena_use_calloc(MemArena *arena);

#ifdef __cplusplus
}
#endif

#endif
