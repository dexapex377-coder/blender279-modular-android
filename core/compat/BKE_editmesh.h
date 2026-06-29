#ifndef __BKE_EDITMESH_H__
#define __BKE_EDITMESH_H__

#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

struct BMesh;
struct BMEditMesh;

typedef struct BMEditMesh {
    struct BMesh *bm;
    int mesh_kind;
    ListBase selected;
    int selectmode;
    int shapenr;
    struct DerivedMesh *derived_cage;
    struct DerivedMesh *derived_final;
    struct DerivedMesh *derived_deform;
    void *py_handle;
} BMEditMesh;

struct BMEditMesh *BKE_editmesh_create(struct BMesh *bm);
void BKE_editmesh_free(struct BMEditMesh *em);
struct BMEditMesh *BKE_editmesh_from_object(struct Object *ob);
void BKE_editmesh_update_linked_editable(struct BMEditMesh *em);

#define BKE_editmesh_ensure(ob, bm) ((void)(ob), (void)(bm))

#ifdef __cplusplus
}
#endif

#endif
