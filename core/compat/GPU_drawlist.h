#ifndef __GPU_DRAWLIST_H__
#define __GPU_DRAWLIST_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GPUDrawList GPUDrawList;

GPUDrawList *GPU_drawlist_create(int max_draws);
void GPU_drawlist_discard(GPUDrawList *list);
void GPU_drawlist_add(GPUDrawList *list, struct GPUBatch *batch);
void GPU_drawlist_submit(GPUDrawList *list);

#ifdef __cplusplus
}
#endif

#endif
