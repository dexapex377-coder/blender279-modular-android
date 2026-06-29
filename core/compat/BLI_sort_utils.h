#ifndef __BLI_SORT_UTILS_H__
#define __BLI_SORT_UTILS_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    float value;
    int index;
} SortFloatByInt;

typedef struct {
    int value;
    int index;
} SortIntByInt;

typedef struct {
    float value;
    void *ptr;
} SortPtrByFloat;

typedef struct {
    float value;
    void *ptr;
} SortPtrByInt;

typedef struct SortIntByFloat {
    float sort_value;
    int data;
} SortIntByFloat;

int BLI_sortutil_cmp_float(const void *a, const void *b);
int BLI_sortutil_cmp_int(const void *a, const void *b);
int BLI_sortutil_cmp_float_reverse(const void *a, const void *b);
int BLI_sortutil_cmp_int_reverse(const void *a, const void *b);

#ifdef __cplusplus
}
#endif

#endif
