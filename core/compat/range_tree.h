#ifndef __RANGE_TREE_H__
#define __RANGE_TREE_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct RangeTree RangeTree;

RangeTree *range_tree_alloc(int size);
void range_tree_free(RangeTree *rt);
int range_tree_uint_alloc(RangeTree *rt);
void range_tree_uint_free(RangeTree *rt, int elem);

#ifdef __cplusplus
}
#endif

#endif
