#ifndef __BLI_LINKLIST_STACK_H__
#define __BLI_LINKLIST_STACK_H__

#include "BLI_linklist.h"

#define BLI_linklist_stack_push(list, link) BLI_linklist_prepend(list, link)
#define BLI_linklist_stack_pop(list) \
    (*(list) ? ((*list) = (*list)->next, 1) : 0)
#define BLI_linklist_stack_peek(list) ((list) ? (list)->link : NULL)
#define BLI_linklist_stack_is_empty(list) ((list) == NULL)

#ifndef BLI_LINKSTACK_DECLARE
#define BLI_LINKSTACK_DECLARE(var, type) BLI_linklist_stack_declare_static(var, type)
#define BLI_LINKSTACK_INIT(var) BLI_linklist_stack_init(var)
#define BLI_LINKSTACK_PUSH(var, ptr) BLI_linklist_stack_push(var, ptr)
#define BLI_LINKSTACK_POP(var) BLI_linklist_stack_pop(var)
#define BLI_LINKSTACK_SIZE(var) BLI_linklist_stack_size(var)
#define BLI_LINKSTACK_FREE(var) BLI_linklist_stack_free(var)
#define BLI_LINKSTACK_SWAP(var_a, var_b) BLI_linklist_stack_swap(var_a, var_b)
#endif

#endif
