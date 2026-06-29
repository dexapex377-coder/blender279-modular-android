#ifndef __GPU_SHADER_H__
#define __GPU_SHADER_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GPUShader GPUShader;

GPUShader *GPU_shader_create(const char *vertexcode, const char *fragmentcode, const char *geocode, const char *libcode, const char *defines);
GPUShader *GPU_shader_create_ex(const char *vertexcode, const char *fragmentcode, const char *geocode, const char *libcode, const char *defines, int flags);
void GPU_shader_free(GPUShader *shader);
void GPU_shader_bind(GPUShader *shader);
void GPU_shader_unbind(void);
int GPU_shader_get_uniform(GPUShader *shader, const char *name);
int GPU_shader_get_attribute(GPUShader *shader, const char *name);
void GPU_shader_uniform_float(GPUShader *shader, int location, float value);
void GPU_shader_uniform_int(GPUShader *shader, int location, int value);
void GPU_shader_uniform_vector(GPUShader *shader, int location, int length, int count, const float *value);
void GPU_shader_uniform_vector_int(GPUShader *shader, int location, int length, int count, const int *value);
void GPU_shader_uniform_matrix(GPUShader *shader, int location, int length, int count, const float *value);
void GPU_shader_uniform_buffer_bind(GPUShader *shader, int location);

#ifdef __cplusplus
}
#endif

#endif
