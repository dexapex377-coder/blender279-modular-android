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

#define BLI_SMALLSTACK_AS_TABLE(var) (var##_stack)
#define BLI_SMALLSTACK_POP_EX(var, type) ((type)BLI_SMALLSTACK_POP(var))
#define BLI_SMALLSTACK_SWAP(var_a, var_b) \
    { typeof(var_a##_stack) _tmp_stack = var_a##_stack; \
      int _tmp_idx = var_a##_stack_index; \
      var_a##_stack = var_b##_stack; \
      var_a##_stack_index = var_b##_stack_index; \
      var_b##_stack = _tmp_stack; \
      var_b##_stack_index = _tmp_idx; }

#endif
