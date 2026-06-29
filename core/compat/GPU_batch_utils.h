#ifndef __GPU_BATCH_UTILS_H__
#define __GPU_BATCH_UTILS_H__

#ifdef __cplusplus
extern "C" {
#endif

struct GPUBatch;
struct GPUVertBuf;

struct GPUBatch *GPU_batch_utils_gen_primitive(int primitive_type, int subdivisions);
void GPU_batch_utils_gen_sphere(struct GPUBatch **r_batch, int lod, int mat_id);
void GPU_batch_utils_gen_circle(struct GPUBatch **r_batch, int subdivisions, int mat_id);

#ifdef __cplusplus
}
#endif

#endif
