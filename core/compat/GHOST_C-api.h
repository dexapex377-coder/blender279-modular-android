#ifndef __GHOST_CAPI_H__
#define __GHOST_CAPI_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GHOST_SystemHandle GHOST_SystemHandle;

GHOST_SystemHandle GHOST_CreateSystem(void);
void GHOST_DisposeSystem(GHOST_SystemHandle system);
int GHOST_ProcessEvents(GHOST_SystemHandle system, int waitForEvent);
void GHOST_DispatchEvents(GHOST_SystemHandle system);
int GHOST_GetMainWindow(GHOST_SystemHandle system);

#ifdef __cplusplus
}
#endif

#endif
