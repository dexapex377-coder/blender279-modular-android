#ifndef BLE_CORE_MATH_H
#define BLE_CORE_MATH_H

#include "BLE_types.h"

#ifdef __cplusplus
extern "C" {
#endif

BLE_MathAPI *BLE_math_api_get(void);

void BLE_math_init(void);
void BLE_math_shutdown(void);

#ifdef __cplusplus
}
#endif

#endif