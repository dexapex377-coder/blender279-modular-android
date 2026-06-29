#ifndef __GPU_SELECT_H__
#define __GPU_SELECT_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GPUSelectBuffer {
    unsigned int *data;
    int len;
    int pad;
} GPUSelectBuffer;

void GPU_select_begin(GPUSelectBuffer *buf);
int GPU_select_end(void);
void GPU_select_load_id(unsigned int id);
void GPU_select_fake_is_call_do(int enable);

#ifdef __cplusplus
}
#endif

#endif
