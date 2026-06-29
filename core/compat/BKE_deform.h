#ifndef __BKE_DEFORM_H__
#define __BKE_DEFORM_H__

#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct bDeformGroup {
    struct bDeformGroup *next, *prev;
    char name[64];
    int flag;
    int index;
    float pad;
} bDeformGroup;

typedef struct MDeformVert {
    struct MDeformWeight *dw;
    int totweight;
    int flag;
} MDeformVert;

typedef struct MDeformWeight {
    int index;
    float weight;
} MDeformWeight;

int defgroup_name_index(struct Object *ob, const char *name);
void defgroup_add_to_group(struct Object *ob, struct MDeformVert *dv, int group, float weight);
void defgroup_remove_group(struct Object *ob, struct bDeformGroup *group, struct MDeformVert *dvlist, int totvert, int *r_totremoved);
void defgroup_clear(struct Object *ob, struct MDeformVert *dvlist, int totvert, int group);
void defgroup_normalize(struct MDeformVert *dv);
void defgroup_normalize_all(struct MDeformVert *dv, int totvert, int only_active);
int defgroup_find_name(struct Object *ob, const char *name);
struct bDeformGroup *defgroup_add(struct Object *ob);
struct bDeformGroup *defgroup_duplicate(struct Object *ob);
int defgroup_unique_name(struct bDeformGroup *dg, struct Object *ob);

#ifdef __cplusplus
}
#endif

#endif
