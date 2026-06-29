#ifndef __BKE_DATA_TRANSFER_H__
#define __BKE_DATA_TRANSFER_H__

#include "DNA_listBase.h"

#define DT_MULTILAYER_INDEX_MAX 4

enum {
    DT_TYPE_BWEIGHT_VERT   = (1 << 0),
    DT_TYPE_BWEIGHT_EDGE   = (1 << 1),
    DT_TYPE_CREASE         = (1 << 2),
    DT_TYPE_SHARP_EDGE     = (1 << 3),
    DT_TYPE_LNOR           = (1 << 4),
    DT_TYPE_SHARP_FACE     = (1 << 5),
};

#define DT_LAYERS_ALL_SRC 0
#define DT_LAYERS_NAME_DST 1

enum {
    CDT_MIX_TRANSFER = 0,
    CDT_MIX_REPLACE  = 1,
    CDT_MIX_ADD      = 2,
    CDT_MIX_SUB      = 3,
    CDT_MIX_MUL      = 4,
    CDT_MIX_DIV      = 5,
    CDT_MIX_DIF      = 6,
    CDT_MIX_AVG      = 7,
};

#endif
