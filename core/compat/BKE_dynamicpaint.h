#ifndef __BKE_DYNAMICPAINT_H__
#define __BKE_DYNAMICPAINT_H__

struct DynamicPaintModifierData;
struct Scene;
struct Object;
struct DerivedMesh;

struct DerivedMesh *dynamicPaint_Modifier_do(struct DynamicPaintModifierData *pmd, struct Scene *scene, struct Object *ob, struct DerivedMesh *dm);
void dynamicPaint_Modifier_free(struct DynamicPaintModifierData *pmd);
void dynamicPaint_Modifier_copy(struct DynamicPaintModifierData *pmd, struct DynamicPaintModifierData *tsmd);

#endif
