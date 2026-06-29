#ifndef __DNA_ARMATURE_TYPES_H__
#define __DNA_ARMATURE_TYPES_H__

#include "DNA_listBase.h"
#include "DNA_ID.h"

typedef struct Armature {
	ID id;
	ListBase bonebase;
	ListBase posechanbase;
	struct Bone *edbo;
	int active_bone_index;
	short flag;
	short editflag;
	short drawflag;
	short pad;
	short ghost_type;
	short posemode;
	short offset;
	short ghost_size;
	short ghost_step;
	short subdivide_type;
	short subdivide_num;
	short pose_position;
} Armature;

typedef struct Bone {
	struct Bone *next, *prev;
	void *prop;
	short flag;
	short poinflag;
	short flag_internal;
	short pad;
	float head[3];
	float tail[3];
	float roll;
	short subdivide_type;
	short subdivide_num;
	float envelop_dist;
	float envelop_weight;
	int rad1, rad2;
	struct Bone *parent;
	void *customdata;
	short bbone_x;
	short bbone_z;
	short bbone_easein;
	short bbone_easeout;
	float bbone_custom_handle_start[3];
	float bbone_custom_handle_end[3];
	struct AnimData *adt;
} Bone;

typedef struct PoseChannel {
	void *next, *prev;
	char name[64];
	struct Bone *bone;
	short flag;
	short poinflag;
	short flag_internal;
	short pad;
	float mat[4][4];
	float pose_mat[4][4];
	float pose_head[3];
	float pose_tail[3];
	float roll;
	struct Constraint *constraints;
	struct AnimData *adt;
	void *customdata;
} PoseChannel;

typedef struct ArmatureModifierData {
	void *modifier;
	struct Armature *object;
	short flag;
	short mode;
	int limit;
	short use_deform_preserve_volume;
	short pad;
	float mult;
} ArmatureModifierData;

#endif /* __DNA_ARMATURE_TYPES_H__ */