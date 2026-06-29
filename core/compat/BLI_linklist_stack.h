#ifndef __BLI_LINKLIST_STACK_H__
#define __BLI_LINKLIST_STACK_H__

#include "BLI_linklist.h"

#define BLI_linklist_stack_push(list, link) BLI_linklist_prepend(list, link)
#define BLI_linklist_stack_pop(list) \
    (*(list) ? ((*list) = (*list)->next, 1) : 0)
#define BLI_linklist_stack_peek(list) ((list) ? (list)->link : NULL)
#define BLI_linklist_stack_is_empty(list) ((list) == NULL)

#endif
