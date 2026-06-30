#ifndef __BKE_LIBRARY_QUERY_H__
#define __BKE_LIBRARY_QUERY_H__

#include "DNA_ID.h"
#include "BKE_main.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
    IDWALK_NOP = 0,
    IDWALK_CB_NOP = 0,
    IDWALK_CB_NEVER_NULL = (1 << 0),
    IDWALK_CB_NEVER_SELF = (1 << 1),
    IDWALK_CB_INDIRECT_USAGE = (1 << 2),
    IDWALK_CB_PRIVATE = (1 << 3),
    IDWALK_CB_LOOPBACK = (1 << 4),
    IDWALK_CB_USER = (1 << 8),
};

void BKE_library_query_foreach_id(Main *bmain, void *userdata, bool (*callback)(void *userdata, ID *id));

void BKE_lib_query_foreach_id(Main *bmain, void *userdata, bool (*callback)(void *userdata, ID *id));

void BKE_library_query_free(Main *bmain);

#ifdef __cplusplus
}
#endif

#endif