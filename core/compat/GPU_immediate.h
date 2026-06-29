#ifndef __GPU_IMMEDIATE_H__
#define __GPU_IMMEDIATE_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GPUImmediate GPUImmediate;

void GPU_immediate_begin(void);
void GPU_immediate_end(void);
void GPU_immediate_attr4f(int attr, float a, float b, float c, float d);
void GPU_immediate_attr3f(int attr, float a, float b, float c);
void GPU_immediate_attr2f(int attr, float a, float b);
void GPU_immediate_attr1f(int attr, float a);
void GPU_immediate_attr4ub(int attr, unsigned char a, unsigned char b, unsigned char c, unsigned char d);
void GPU_immediate_attr3ub(int attr, unsigned char a, unsigned char b, unsigned char c);
void GPU_immediate_vert4f(float x, float y, float z, float w);
void GPU_immediate_vert3f(float x, float y, float z);
void GPU_immediate_vert2f(float x, float y);
int GPU_immediate_vertex_count(void);

#ifdef __cplusplus
}
#endif

#endif
