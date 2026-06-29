#ifndef __BLI_LINKLIST_STACK_H__
#define __BLI_LINKLIST_STACK_H__

#include <alloca.h>

#include "BLI_linklist.h"
#include "BLI_compiler_attrs.h"

#ifdef __GNUC__
#  define _BLI_SMALLSTACK_CAST(var) (typeof(_##var##_type))
#else
#  define _BLI_SMALLSTACK_CAST(var)
#endif

#define _BLI_SMALLSTACK_FAKEUSER(var) \
	(void)(&(_##var##_type))

#define BLI_SMALLSTACK_DECLARE(var, type) \
	LinkNode *_##var##_stack = NULL, *_##var##_free = NULL, *_##var##_temp = NULL; \
	type _##var##_type

#define BLI_SMALLSTACK_PUSH(var, data) \
{ \
	CHECK_TYPE_PAIR(data, _##var##_type); \
	if (_##var##_free) { \
		_##var##_temp = _##var##_free; \
		_##var##_free = _##var##_free->next; \
	} \
	else { \
		_##var##_temp = alloca(sizeof(LinkNode)); \
	} \
	_##var##_temp->next = _##var##_stack; \
	_##var##_temp->link = (void *)(intptr_t)data; \
	_##var##_stack = _##var##_temp; \
	_BLI_SMALLSTACK_FAKEUSER(var); \
} (void)0

#define _BLI_SMALLSTACK_DEL_EX(var_src, var_dst) \
	(void)(_BLI_SMALLSTACK_FAKEUSER(var_src), \
	       _BLI_SMALLSTACK_FAKEUSER(var_dst), \
	       (_##var_src##_temp = _##var_src##_stack->next), \
	       (_##var_src##_stack->next = _##var_dst##_free), \
	       (_##var_dst##_free = _##var_src##_stack), \
	       (_##var_src##_stack = _##var_src##_temp))

#define _BLI_SMALLSTACK_DEL(var) \
	_BLI_SMALLSTACK_DEL_EX(var, var)

#define BLI_SMALLSTACK_POP(var) \
	(_BLI_SMALLSTACK_CAST(var) ((_##var##_stack) ? \
	(_BLI_SMALLSTACK_DEL(var), (_##var##_free->link)) : NULL))

#define BLI_SMALLSTACK_POP_EX(var_src, var_dst) \
	(_BLI_SMALLSTACK_CAST(var_src) ((_##var_src##_stack) ? \
	(_BLI_SMALLSTACK_DEL_EX(var_src, var_dst), (_##var_dst##_free->link)) : NULL))

#define BLI_SMALLSTACK_PEEK(var) \
	(_BLI_SMALLSTACK_CAST(var) ((_##var##_stack) ? \
	                             _##var##_stack->link : NULL))

#define BLI_SMALLSTACK_IS_EMPTY(var) \
	((_BLI_SMALLSTACK_CAST(var) _##var##_stack) == NULL)

#define BLI_SMALLSTACK_AS_TABLE(var, data) \
{ \
	LinkNode *_##var##_iter; \
	unsigned int i; \
	for (_##var##_iter = _##var##_stack, i = 0; _##var##_iter; _##var##_iter = _##var##_iter->next, i++) { \
		(data)[i] = _BLI_SMALLSTACK_CAST(var) (_##var##_iter->link); \
	} \
} ((void)0)

#define BLI_SMALLSTACK_ITER_BEGIN(var, item) \
	{ \
		LinkNode *_##var##_iter; \
		for (_##var##_iter = _##var##_stack; _##var##_iter; _##var##_iter = _##var##_iter->next) { \
			item = _BLI_SMALLSTACK_CAST(var) (_##var##_iter->link); \

#define BLI_SMALLSTACK_ITER_END \
		} \
	} (void)0

#define BLI_SMALLSTACK_SWAP(var_a, var_b) \
{ \
	CHECK_TYPE_PAIR(_##var_a##_type, _##var_b##_type); \
	SWAP(LinkNode *, _##var_a##_stack, _##var_b##_stack); \
	SWAP(LinkNode *, _##var_a##_free, _##var_b##_free); \
} (void)0

#endif
