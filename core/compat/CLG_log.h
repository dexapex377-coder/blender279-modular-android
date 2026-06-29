#ifndef __CLG_LOG_H__
#define __CLG_LOG_H__

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CLG_LogRef {
    const char *name;
    int flag;
} CLG_LogRef;

void CLG_logf(const CLG_LogRef *clg, int severity, const char *file, int line, const char *fn, const char *fmt, ...);

#define CLOG_INFO(log, severity, ...)   ((void)0)
#define CLOG_WARN(log, ...)             ((void)0)
#define CLOG_ERROR(log, ...)            ((void)0)
#define CLOG_STR_ERROR(log, msg)        ((void)(msg))
#define CLOG_REF(log)                   ((void)0)

#ifdef __cplusplus
}
#endif

#endif
