#ifndef __BLI_HEAP_H__
#define __BLI_HEAP_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Heap Heap;
typedef struct HeapNode HeapNode;

typedef int (*BLI_heap_cmp)(const void *a, const void *b);

Heap *BLI_heap_new(void);
Heap *BLI_heap_new_ex(unsigned int n);
void BLI_heap_free(Heap *heap, void (*free_cb)(void *));
void BLI_heap_clear(Heap *heap, void (*free_cb)(void *));
void BLI_heap_insert(Heap *heap, float value, void *ptr);
void BLI_heap_insert_or_update(Heap *heap, HeapNode **node, float value, void *ptr);
void BLI_heap_remove(Heap *heap, HeapNode *node);
void *BLI_heap_pop_min(Heap *heap);
void *BLI_heap_peek_min(Heap *heap);
float BLI_heap_min_value(Heap *heap);
int BLI_heap_len(Heap *heap);
int BLI_heap_is_empty(Heap *heap);

#ifdef __cplusplus
}
#endif

#endif
