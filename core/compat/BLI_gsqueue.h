#ifndef __BLI_GSQUEUE_H__
#define __BLI_GSQUEUE_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _GSQueue GSQueue;

GSQueue *BLI_gsqueue_new(size_t elem_size);
void BLI_gsqueue_free(GSQueue *gq);
void BLI_gsqueue_push(GSQueue *gq, const void *item);
void BLI_gsqueue_pop(GSQueue *gq, void *item);
int BLI_gsqueue_len(GSQueue *gq);
int BLI_gsqueue_is_empty(GSQueue *gq);
void *BLI_gsqueue_peek(GSQueue *gq);

#ifdef __cplusplus
}
#endif

#endif
