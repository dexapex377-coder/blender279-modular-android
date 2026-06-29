#ifndef __BKE_LIBRARY_QUERY_H__
#define __BKE_LIBRARY_QUERY_H__

#include "DNA_ID.h"

#ifdef __cplusplus
extern "C" {
#endif

void BKE_library_query_foreach_id(Main *bmain, void *userdata, bool (*callback)(void *userdata, ID *id));

void BKE_lib_query_foreach_id(Main *bmain, void *userdata, bool (*callback)(void *userdata, ID *id));

void BKE_library_query_free(Main *bmain);

#ifdef __cplusplus
}
#endif

#endif