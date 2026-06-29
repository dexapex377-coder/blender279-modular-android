#ifndef __BMESH_OPERATOR_API_H__
#define __BMESH_OPERATOR_API_H__

#include "BLI_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BMOperator BMOperator;
typedef struct BMOpSlot BMOpSlot;

enum BMO_Delimit {
    BMO_DELIM_NORMAL = 1 << 0,
    BMO_DELIM_MATERIAL = 1 << 1,
    BMO_DELIM_SEAM = 1 << 2,
    BMO_DELIM_SHARP = 1 << 3,
    BMO_DELIM_UV = 1 << 4,
};
typedef enum BMO_Delimit BMO_Delimit;

void BMO_op_flag_enable(BMesh *bm, BMOperator *op, const int op_flag);
void BMO_op_flag_disable(BMesh *bm, BMOperator *op, const int op_flag);

void BMO_slot_float_set(BMOpSlot slot_args[], const char *slot_name, const float f);
float BMO_slot_float_get(BMOpSlot slot_args[], const char *slot_name);
void BMO_slot_int_set(BMOpSlot slot_args[], const char *slot_name, const int i);
int BMO_slot_int_get(BMOpSlot slot_args[], const char *slot_name);
void BMO_slot_bool_set(BMOpSlot slot_args[], const char *slot_name, const bool i);
bool BMO_slot_bool_get(BMOpSlot slot_args[], const char *slot_name);
void *BMO_slot_as_arrayN(BMOpSlot slot_args[], const char *slot_name, int *len);

void BMO_slot_ptr_set(BMOpSlot slot_args[], const char *slot_name, void *p);
void *BMO_slot_ptr_get(BMOpSlot slot_args[], const char *slot_name);

#define BMO_OP_MAX_SLOTS 64

#ifdef __cplusplus
}
#endif

#endif /* __BMESH_OPERATOR_API_H__ */