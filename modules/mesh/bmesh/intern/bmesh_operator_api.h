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
	BMO_SLOT_INT,
	BMO_SLOT_FLOAT,
	BMO_SLOT_BOOL,
	BMO_SLOT_VECTOR,
	BMO_SLOT_MATRIX,
	BMO_SLOT_BUFFER,
	BMO_SLOT_GHASH,
	BMO_SLOT_PTR,
} eBMOpSlotType;

typedef enum eBMOpSlotSubType_Union {
	BMO_SLOT_SUB_NONE = 0,
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
	BMO_OPTYPE_FLAG_USE_MESH_SELECT = (1 << 0),
	BMO_OPTYPE_FLAG_NORMALS_CALC    = (1 << 1),
	BMO_OPTYPE_FLAG_SELECT_FLUSH    = (1 << 2),
	BMO_OPTYPE_FLAG_SELECT_VALIDATE = (1 << 3),
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

typedef enum BMO_Delimit {
    BMO_DELIM_NORMAL = 1 << 0,
    BMO_DELIM_MATERIAL = 1 << 1,
    BMO_DELIM_SEAM = 1 << 2,
    BMO_DELIM_SHARP = 1 << 3,
    BMO_DELIM_UV = 1 << 4,
} BMO_Delimit;

enum {
	BMO_FLAG_RESPECT_HIDE = 1,
};

/* del "context" slot values, used for operator too */
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

/* Iterator */
typedef struct BMOIter {
    BMOpSlot *slot;
    int cur;
    GHashIterator giter;
    void **val;
    char restrictmask;
} BMOIter;

void *BMO_slot_buffer_get_first(BMOpSlot slot_args[BMO_OP_MAX_SLOTS], const char *slot_name);

void *BMO_iter_new(
        BMOIter *iter,
        BMOpSlot slot_args[BMO_OP_MAX_SLOTS], const char *slot_name,
        const char restrictmask);
void *BMO_iter_step(BMOIter *iter);

void **BMO_iter_map_value_p(BMOIter *iter);
void  *BMO_iter_map_value_ptr(BMOIter *iter);

float BMO_iter_map_value_float(BMOIter *iter);
int   BMO_iter_map_value_int(BMOIter *iter);
bool  BMO_iter_map_value_bool(BMOIter *iter);

#ifdef __cplusplus
}
#endif

#endif /* __BMESH_OPERATOR_API_H__ */