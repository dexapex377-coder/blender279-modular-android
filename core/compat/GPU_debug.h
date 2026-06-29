#ifndef __GPU_DEBUG_H__
#define __GPU_DEBUG_H__

#ifdef __cplusplus
extern "C" {
#endif

void GPU_debug_group_begin(const char *name);
void GPU_debug_group_end(void);

#ifdef __cplusplus
}
#endif

#endif
