#ifndef __DNA_VEC_TYPES_H__
#define __DNA_VEC_TYPES_H__

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

typedef struct vec2i {
    int x, y;
} vec2i;

typedef struct vec2f {
    float x, y;
} vec2f;

typedef struct vec3f {
    float x, y, z;
} vec3f;

#ifdef __cplusplus
}
#endif

#endif
