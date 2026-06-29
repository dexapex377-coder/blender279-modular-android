#ifndef __BLI_SMALLSTACK_H__
#define __BLI_SMALLSTACK_H__

#include <stddef.h>

#define BLI_SMALLSTACK_SIZE 256

#define BLI_SMALLSTACK_DECLARE(var, type) \
    type var##_stack_typed[BLI_SMALLSTACK_SIZE]; \
    int var##_stack_index = 0; \
    type *var##_stack = var##_stack_typed

#define BLI_SMALLSTACK_PUSH(var, item) \
    ((void)(var##_stack_typed[var##_stack_index++] = (item)))

#define BLI_SMALLSTACK_POP(var) \
    ((var##_stack_index > 0) ? (var##_stack_typed[--var##_stack_index]) : NULL)

#define BLI_SMALLSTACK_IS_EMPTY(var) ((var##_stack_index) == 0)

#endif
