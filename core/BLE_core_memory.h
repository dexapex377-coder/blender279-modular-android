#ifndef BLE_CORE_MEMORY_H
#define BLE_CORE_MEMORY_H

#include "BLE_types.h"

#ifdef __cplusplus
extern "C" {
#endif

BLE_MemoryAPI *BLE_memory_api_get(void);

void *BLE_mem_alloc(size_t size);
void *BLE_mem_alloc_aligned(size_t size, size_t alignment);
void *BLE_mem_realloc(void *ptr, size_t size);
void *BLE_mem_realloc_aligned(void *ptr, size_t size, size_t alignment);
void BLE_mem_free(void *ptr);
void BLE_mem_free_aligned(void *ptr);

void BLE_mem_init(void);
void BLE_mem_shutdown(void);

size_t BLE_mem_usage(void);
size_t BLE_mem_peak_usage(void);

#ifdef __cplusplus
}
#endif

#endif