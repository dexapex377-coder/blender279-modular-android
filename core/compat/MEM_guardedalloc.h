#ifndef __MEM_GUARDEDALLOC_H__
#define __MEM_GUARDEDALLOC_H__

#include "BLE_core_memory.h"
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MEM_mallocN(size, str) BLE_mem_alloc(size)
#define MEM_callocN(size, str) BLE_mem_alloc(size)
#define MEM_reallocN(ptr, size) BLE_mem_realloc(ptr, size)
#define MEM_freeN(ptr) BLE_mem_free(ptr)
#define MEM_dupallocN(ptr) BLE_mem_alloc(sizeof(*(ptr)))
#define MEM_recallocN(ptr, size) BLE_mem_realloc(ptr, size)
#define MEM_lockfree_callocN(size, str) calloc(1, size)
#define MEM_lockfree_mallocN(size, str) malloc(size)
#define MEM_lockfree_freeN(ptr) free(ptr)

void *MEM_mallocN_aligned(size_t size, size_t alignment, const char *str);
void *MEM_mallocN(size_t size, const char *str);
void *MEM_callocN(size_t size, const char *str);
void *MEM_reallocN(void *ptr, size_t size);
void MEM_freeN(void *ptr);
void MEM_printmemlist(void);
int MEM_test_error(void);
void MEM_set_error_callback(void (*func)(const char *));

#ifdef __cplusplus
}
#endif

#endif
