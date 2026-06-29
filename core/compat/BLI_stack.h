#ifndef __BLI_STACK_H__
#define __BLI_STACK_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BLI_Stack BLI_Stack;

BLI_Stack *BLI_stack_new(size_t elem_size, const char *name);
void BLI_stack_free(BLI_Stack *stack);
void BLI_stack_push(BLI_Stack *stack, const void *item);
void BLI_stack_pop(BLI_Stack *stack, void *item);
void BLI_stack_pop_n(BLI_Stack *stack, void *item, int n);
void BLI_stack_pop_n_reverse(BLI_Stack *stack, void *ret, unsigned int n);
void *BLI_stack_peek(BLI_Stack *stack);
int BLI_stack_len(BLI_Stack *stack);
unsigned int BLI_stack_count(const BLI_Stack *stack);
int BLI_stack_is_empty(BLI_Stack *stack);
void BLI_stack_clear(BLI_Stack *stack);

#ifdef __cplusplus
}
#endif

#endif
