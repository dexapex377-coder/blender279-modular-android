#ifndef __DRW_ENGINE_H__
#define __DRW_ENGINE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct DRW_Engine {
    char name[64];
    int flag;
} DRW_Engine;

int DRW_engine_type_from_string(const char *name);
void DRW_engine_register(struct DRW_Engine *engine);
void DRW_opengl_context_create(void);
void DRW_opengl_context_destroy(void);

#ifdef __cplusplus
}
#endif

#endif
