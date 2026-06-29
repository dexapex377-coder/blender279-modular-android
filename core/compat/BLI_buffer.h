#ifndef __BLI_BUFFER_H__
#define __BLI_BUFFER_H__

#include <stdlib.h>
#include <string.h>
#include "BLI_compiler_attrs.h"
#include "BLI_utildefines.h"

typedef struct BLI_Buffer {
    void *data;
    int len;
    int max;
    size_t elem_size;
    int flag;
} BLI_Buffer;

void BLI_buffer_init(BLI_Buffer *buffer, size_t elem_size, int elem_len);
void BLI_buffer_free(BLI_Buffer *buffer);
void BLI_buffer_resize(BLI_Buffer *buffer, int new_len);
void BLI_buffer_ensure(BLI_Buffer *buffer, int capacity);
void *BLI_buffer_alloc(BLI_Buffer *buffer);

#ifdef __cplusplus
extern "C" {
#endif

BLI_INLINE void BLI_buffer_resize_data(BLI_Buffer *buf, int elem_len)
{
    BLI_buffer_resize(buf, elem_len);
}

BLI_INLINE void *BLI_buffer_at(BLI_Buffer *buf, int index)
{
    return (char *)buf->data + (size_t)(index * buf->elem_size);
}

#ifdef __cplusplus
}
#endif

#endif
