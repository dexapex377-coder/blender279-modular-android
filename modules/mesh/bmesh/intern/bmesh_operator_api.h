#ifndef __BMESH_OPERATOR_API_H__
#define __BMESH_OPERATOR_API_H__

#include "BLI_listbase.h"
#include "BLI_compiler_attrs.h"
#include "BLI_memarena.h"
#include "BLI_ghash.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BMO_OP_MAX_SLOTS 64
#define MAX_SLOTNAME 32

typedef enum eBMOpSlotType {
	BMO_SLOT_NONE = 0,
	BMO_OP_SLOT_BOOL = 1,
	BMO_OP_SLOT_INT = 2,
	BMO_OP_SLOT_FLT = 3,
	BMO_OP_SLOT_PTR = 4,
	BMO_OP_SLOT_MAT = 5,
	BMO_OP_SLOT_VEC = 6,

	BMO_OP_SLOT_ELEMENT_BUF = 9,
	BMO_OP_SLOT_MAPPING = 10
} eBMOpSlotType;
#define BMO_OP_SLOT_TOTAL_TYPES 11

typedef enum eBMOpSlotSubType_Elem {
	BMO_OP_SLOT_SUBTYPE_ELEM_VERT = BM_VERT,
	BMO_OP_SLOT_SUBTYPE_ELEM_EDGE = BM_EDGE,
	BMO_OP_SLOT_SUBTYPE_ELEM_FACE = BM_FACE,
	BMO_OP_SLOT_SUBTYPE_ELEM_IS_SINGLE = (BM_FACE << 1),
} eBMOpSlotSubType_Elem;

typedef enum eBMOpSlotSubType_Map {
	BMO_OP_SLOT_SUBTYPE_MAP_EMPTY    = 64,
	BMO_OP_SLOT_SUBTYPE_MAP_ELEM     = 65,
	BMO_OP_SLOT_SUBTYPE_MAP_FLT      = 66,
	BMO_OP_SLOT_SUBTYPE_MAP_INT      = 67,
	BMO_OP_SLOT_SUBTYPE_MAP_BOOL     = 68,
	BMO_OP_SLOT_SUBTYPE_MAP_INTERNAL = 69,
} eBMOpSlotSubType_Map;

typedef enum eBMOpSlotSubType_Ptr {
	BMO_OP_SLOT_SUBTYPE_PTR_BMESH  = 100,
	BMO_OP_SLOT_SUBTYPE_PTR_SCENE  = 101,
	BMO_OP_SLOT_SUBTYPE_PTR_OBJECT = 102,
	BMO_OP_SLOT_SUBTYPE_PTR_MESH   = 103,
} eBMOpSlotSubType_Ptr;

typedef union eBMOpSlotSubType_Union {
	eBMOpSlotSubType_Elem elem;
	eBMOpSlotSubType_Ptr ptr;
	eBMOpSlotSubType_Map map;
} eBMOpSlotSubType_Union;

typedef struct BMOpSlot {
	const char *slot_name;
	eBMOpSlotType          slot_type;
	eBMOpSlotSubType_Union slot_subtype;
	int len;
	union {
		int i;
		float f;
		void *p;
		float vec[3];
		void **buf;
		GHash *ghash;
	} data;
} BMOpSlot;

#define BMO_SLOT_AS_BOOL(slot)         ((slot)->data.i)
#define BMO_SLOT_AS_INT(slot)          ((slot)->data.i)
#define BMO_SLOT_AS_FLOAT(slot)        ((slot)->data.f)
#define BMO_SLOT_AS_VECTOR(slot)       ((slot)->data.vec)
#define BMO_SLOT_AS_MATRIX(slot)       ((float (*)[4])((slot)->data.p))
#define BMO_SLOT_AS_BUFFER(slot)       ((slot)->data.buf)
#define BMO_SLOT_AS_GHASH(slot)        ((slot)->data.ghash)

#define BMO_ASSERT_SLOT_IN_OP(slot, op) \
	BLI_assert(((slot >= (op)->slots_in)  && (slot < &(op)->slots_in[BMO_OP_MAX_SLOTS])) || \
	           ((slot >= (op)->slots_out) && (slot < &(op)->slots_out[BMO_OP_MAX_SLOTS])))

typedef enum BMOpTypeFlag {
	BMO_OPTYPE_FLAG_NOP                 = 0,
	BMO_OPTYPE_FLAG_UNTAN_MULTIRES      = (1 << 0),
	BMO_OPTYPE_FLAG_NORMALS_CALC        = (1 << 1),
	BMO_OPTYPE_FLAG_SELECT_FLUSH        = (1 << 2),
	BMO_OPTYPE_FLAG_SELECT_VALIDATE     = (1 << 3),
} BMOpTypeFlag;

typedef struct BMOperator {
	struct BMOpSlot slots_in[BMO_OP_MAX_SLOTS];
	struct BMOpSlot slots_out[BMO_OP_MAX_SLOTS];
	void (*exec)(BMesh *bm, struct BMOperator *op);
	struct MemArena *arena;
	int type;
	BMOpTypeFlag type_flag;
	int flag;
} BMOperator;

enum {
	BMO_FLAG_RESPECT_HIDE = 1,
};

typedef enum BMO_Delimit {
    BMO_DELIM_NORMAL = 1 << 0,
    BMO_DELIM_MATERIAL = 1 << 1,
    BMO_DELIM_SEAM = 1 << 2,
    BMO_DELIM_SHARP = 1 << 3,
    BMO_DELIM_UV = 1 << 4,
} BMO_Delimit;

enum {
	DEL_VERTS = 1,
	DEL_EDGES,
	DEL_ONLYFACES,
	DEL_EDGESFACES,
	DEL_FACES,
	DEL_FACES_KEEP_BOUNDARY,
	DEL_ONLYTAGGED
};

typedef enum {
	BMO_SYMMETRIZE_NEGATIVE_X,
	BMO_SYMMETRIZE_NEGATIVE_Y,
	BMO_SYMMETRIZE_NEGATIVE_Z,

	BMO_SYMMETRIZE_POSITIVE_X,
	BMO_SYMMETRIZE_POSITIVE_Y,
	BMO_SYMMETRIZE_POSITIVE_Z,
} BMO_SymmDirection;

#define BMO_FLAG_DEFAULTS  BMO_FLAG_RESPECT_HIDE

typedef struct BMOSlotType {
	char name[MAX_SLOTNAME];
	eBMOpSlotType          type;
	eBMOpSlotSubType_Union subtype;
} BMOSlotType;

typedef struct BMOpDefine {
	const char *opname;
	BMOSlotType slot_types_in[BMO_OP_MAX_SLOTS];
	BMOSlotType slot_types_out[BMO_OP_MAX_SLOTS];
	void (*exec)(BMesh *bm, BMOperator *op);
	BMOpTypeFlag type_flag;
} BMOpDefine;

typedef struct BMOIter {
	BMOpSlot *slot;
	int cur;
	GHashIterator giter;
	void **val;
	char restrictmask;
} BMOIter;

void BMO_op_init(BMesh *bm, BMOperator *op, const int flag, const char *opname);
void BMO_op_exec(BMesh *bm, BMOperator *op);
void BMO_op_finish(BMesh *bm, BMOperator *op);
int BMO_mesh_enabled_flag_count(BMesh *bm, const char htype, const short oflag);

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

void *BMO_iter_new(
        BMOIter *iter,
        BMOpSlot slot_args[], const char *slot_name,
        const char restrictmask);
void *BMO_iter_step(BMOIter *iter);

void **BMO_iter_map_value_p(BMOIter *iter);
void  *BMO_iter_map_value_ptr(BMOIter *iter);

float BMO_iter_map_value_float(BMOIter *iter);
int   BMO_iter_map_value_int(BMOIter *iter);
bool  BMO_iter_map_value_bool(BMOIter *iter);

void *BMO_slot_buffer_get_first(BMOpSlot slot_args[], const char *slot_name);

#define BMO_ITER(ele, iter, slot_args, slot_name, restrict_flag)   \
	for (BM_CHECK_TYPE_ELEM_ASSIGN(ele) = BMO_iter_new(iter, slot_args, slot_name, restrict_flag); \
	     ele; \
	     BM_CHECK_TYPE_ELEM_ASSIGN(ele) = BMO_iter_step(iter))

#define BMO_ITER_INDEX(ele, iter, slot_args, slot_name, restrict_flag, i_)   \
	for (BM_CHECK_TYPE_ELEM_ASSIGN(ele) = BMO_iter_new(iter, slot_args, slot_name, restrict_flag), i_ = 0; \
	     ele; \
	     BM_CHECK_TYPE_ELEM_ASSIGN(ele) = BMO_iter_step(iter), i_++)

#ifdef __cplusplus
}
#endif

#endif /* __BMESH_OPERATOR_API_H__ */