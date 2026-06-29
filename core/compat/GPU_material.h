#ifndef __GPU_MATERIAL_H__
#define __GPU_MATERIAL_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GPUMaterial GPUMaterial;
typedef struct GPUNodeGraph GPUNodeGraph;
typedef struct GPUPass GPUPass;

GPUMaterial *GPU_material_create(struct Material *ma);
void GPU_material_free(GPUMaterial *mat);
int GPU_material_status(GPUMaterial *mat);
void GPU_material_compile(GPUMaterial *mat);
int GPU_material_bound(GPUMaterial *mat);
struct GPUPass *GPU_material_get_pass(GPUMaterial *mat);
int GPU_material_get_vertex_attributes(GPUMaterial *mat);
int GPU_material_get_vertex_attributes_len(GPUMaterial *mat);
void GPU_material_bind(GPUMaterial *mat, int view, int output, int object, int stereoscopy);
void GPU_material_unbind(GPUMaterial *mat);

#ifdef __cplusplus
}
#endif

#endif
