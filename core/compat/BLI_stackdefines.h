#ifndef __BLI_STACKDEFINES_H__
#define __BLI_STACKDEFINES_H__

#define STACK_INIT(array, count) ((void)(array), (void)(count))
#define STACK_SIZE(array) 0
#define STACK_PUSH(array, item) ((void)(array), (void)(item))
#define STACK_PUSH_RET(array) (NULL)
#define STACK_POP(array) (NULL)
#define STACK_POP_PEEK(array) (NULL)
#define STACK_DISCARD(array, count) ((void)(array), (void)(count))
#define STACK_DEC_COUNT(array) ((void)(array))
#define STACK_COUNT(array) 0
#define STACK_REMOVE(array, count, i) ((void)(array), (void)(count), (void)(i))

#endif
