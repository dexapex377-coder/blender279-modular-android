#include "BLE_core_memory.h"
#include "BLE_module_api.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MemHeader {
    size_t size;
    size_t alignment;
    struct MemHeader *next;
    struct MemHeader *prev;
    const char *file;
    int line;
} MemHeader;

static MemHeader *mem_list = NULL;
static size_t total_allocated = 0;
static size_t peak_allocated = 0;
static int mem_initialized = 0;

static void *alloc_impl(size_t size, size_t alignment, const char *file, int line) {
    size_t header_size = sizeof(MemHeader);
    size_t total_size = header_size + size + alignment;
    
    void *raw = malloc(total_size);
    if (!raw) return NULL;
    
    MemHeader *hdr = (MemHeader *)raw;
    hdr->size = size;
    hdr->alignment = alignment;
    hdr->file = file;
    hdr->line = line;
    
    uintptr_t data_ptr = (uintptr_t)raw + header_size;
    uintptr_t aligned = (data_ptr + alignment - 1) & ~(alignment - 1);
    void *data = (void *)aligned;
    
    hdr->next = mem_list;
    hdr->prev = NULL;
    if (mem_list) mem_list->prev = hdr;
    mem_list = hdr;
    
    total_allocated += size;
    if (total_allocated > peak_allocated) peak_allocated = total_allocated;
    
    return data;
}

static void free_impl(void *ptr, size_t alignment) {
    if (!ptr) return;
    
    MemHeader *hdr = NULL;
    for (MemHeader *h = mem_list; h; h = h->next) {
        uintptr_t data_ptr = (uintptr_t)h + sizeof(MemHeader);
        uintptr_t aligned = (data_ptr + h->alignment - 1) & ~(h->alignment - 1);
        if ((void *)aligned == ptr) {
            hdr = h;
            break;
        }
    }
    
    if (!hdr) return;
    
    total_allocated -= hdr->size;
    
    if (hdr->prev) hdr->prev->next = hdr->next;
    if (hdr->next) hdr->next->prev = hdr->prev;
    if (mem_list == hdr) mem_list = hdr->next;
    
    free(hdr);
}

static void *alloc_fn(size_t size) {
    return alloc_impl(size, 8, __FILE__, __LINE__);
}

static void *alloc_aligned_fn(size_t size, size_t alignment) {
    return alloc_impl(size, alignment, __FILE__, __LINE__);
}

static void *realloc_fn(void *ptr, size_t size) {
    if (!ptr) return alloc_fn(size);
    
    MemHeader *hdr = NULL;
    for (MemHeader *h = mem_list; h; h = h->next) {
        uintptr_t data_ptr = (uintptr_t)h + sizeof(MemHeader);
        uintptr_t aligned = (data_ptr + h->alignment - 1) & ~(h->alignment - 1);
        if ((void *)aligned == ptr) {
            hdr = h;
            break;
        }
    }
    
    if (!hdr) return NULL;
    
    void *new_ptr = alloc_impl(size, hdr->alignment, __FILE__, __LINE__);
    if (new_ptr) {
        size_t copy_size = hdr->size < size ? hdr->size : size;
        memcpy(new_ptr, ptr, copy_size);
        free_impl(ptr, hdr->alignment);
    }
    return new_ptr;
}

static void *realloc_aligned_fn(void *ptr, size_t size, size_t alignment) {
    if (!ptr) return alloc_aligned_fn(size, alignment);
    (void)alignment;
    return realloc_fn(ptr, size);
}

static void free_fn(void *ptr) {
    free_impl(ptr, 8);
}

static void free_aligned_fn(void *ptr) {
    free_impl(ptr, 16);
}

static BLE_MemoryAPI mem_api = {
    .alloc = alloc_fn,
    .realloc = realloc_fn,
    .free = free_fn,
    .alloc_aligned = alloc_aligned_fn,
    .realloc_aligned = realloc_aligned_fn,
    .free_aligned = free_aligned_fn,
};

BLE_MemoryAPI *BLE_memory_api_get(void) {
    return &mem_api;
}

void *BLE_mem_alloc(size_t size) { return alloc_fn(size); }
void *BLE_mem_alloc_aligned(size_t size, size_t alignment) { return alloc_aligned_fn(size, alignment); }
void *BLE_mem_realloc(void *ptr, size_t size) { return realloc_fn(ptr, size); }
void *BLE_mem_realloc_aligned(void *ptr, size_t size, size_t alignment) { return realloc_aligned_fn(ptr, size, alignment); }
void BLE_mem_free(void *ptr) { free_fn(ptr); }
void BLE_mem_free_aligned(void *ptr) { free_aligned_fn(ptr); }

void BLE_mem_init(void) {
    mem_initialized = 1;
}

void BLE_mem_shutdown(void) {
    while (mem_list) {
        fprintf(stderr, "[Mem] Leak: %zu bytes at %s:%d\n", mem_list->size, mem_list->file, mem_list->line);
        MemHeader *next = mem_list->next;
        free(mem_list);
        mem_list = next;
    }
    total_allocated = 0;
    peak_allocated = 0;
}

size_t BLE_mem_usage(void) { return total_allocated; }
size_t BLE_mem_peak_usage(void) { return peak_allocated; }