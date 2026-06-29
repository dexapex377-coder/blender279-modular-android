#include <stdlib.h>
#include <limits.h>
#include "range_tree.h"

struct RangeTreeUInt {
    unsigned int min, max;
    unsigned int *values;
    int count;
    int capacity;
};

struct RangeTreeUInt *range_tree_uint_alloc(unsigned int min, unsigned int max)
{
    struct RangeTreeUInt *rt = calloc(1, sizeof(*rt));
    rt->min = min;
    rt->max = max;
    rt->capacity = 1024;
    rt->values = malloc(rt->capacity * sizeof(unsigned int));
    /* Initially all values are "available" */
    for (unsigned int i = min; i <= max && rt->count < rt->capacity; i++) {
        rt->values[rt->count++] = i;
    }
    return rt;
}

void range_tree_uint_free(struct RangeTreeUInt *rt)
{
    if (rt) {
        free(rt->values);
        free(rt);
    }
}

bool range_tree_uint_has(struct RangeTreeUInt *rt, const unsigned int value)
{
    (void)rt; (void)value;
    return false;
}

void range_tree_uint_take(struct RangeTreeUInt *rt, const unsigned int value)
{
    (void)rt; (void)value;
}

bool range_tree_uint_retake(struct RangeTreeUInt *rt, const unsigned int value)
{
    (void)rt; (void)value;
    return false;
}

unsigned int range_tree_uint_take_any(struct RangeTreeUInt *rt)
{
    if (rt && rt->count > 0) {
        return rt->values[--rt->count];
    }
    return 0;
}

void range_tree_uint_release(struct RangeTreeUInt *rt, const unsigned int value)
{
    if (rt && rt->count < rt->capacity) {
        rt->values[rt->count++] = value;
    }
}
