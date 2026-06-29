#ifndef __BKE_REPORT_H__
#define __BKE_REPORT_H__

#include <stdarg.h>

typedef enum eReportType {
    RPT_DEBUG = 0,
    RPT_INFO = 1,
    RPT_WARNING = 2,
    RPT_ERROR = 3,
    RPT_OPERATOR = 4,
    RPT_PROPERTY = 5,
    RPT_WM = 6,
    RPT_HINT = 7,
} eReportType;

#define RPT_STORE 1

typedef struct ReportList {
    void *list;
    int flags;
    int printlevel;
    int storelevel;
} ReportList;

#define BKE_report(reports, type, msg) ((void)(reports), (void)(type), (void)(msg))
#define BKE_reportf(reports, type, fmt, ...) ((void)(reports), (void)(type))
#define BKE_reports_init(reports, flags) ((void)(reports), (void)(flags))

#endif
