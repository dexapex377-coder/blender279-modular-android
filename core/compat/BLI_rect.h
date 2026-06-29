#ifndef __BLI_RECT_H__
#define __BLI_RECT_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rcti {
    int xmin, xmax;
    int ymin, ymax;
} rcti;

typedef struct rctf {
    float xmin, xmax;
    float ymin, ymax;
} rctf;

void BLI_rctf_init(rctf *rect, float xmin, float xmax, float ymin, float ymax);
void BLI_rcti_init(rcti *rect, int xmin, int xmax, int ymin, int ymax);
int BLI_rcti_isect(const rcti *a, const rcti *b, rcti *r);
int BLI_rctf_isect(const rctf *a, const rctf *b, rctf *r);
int BLI_rcti_is_empty(const rcti *rect);
int BLI_rctf_is_empty(const rctf *rect);
void BLI_rcti_union(rcti *rect, const rcti *other);
void BLI_rctf_union(rctf *rect, const rctf *other);

#ifdef __cplusplus
}
#endif

#endif
