#ifndef __BKE_PAINT_H__
#define __BKE_PAINT_H__

#ifdef __cplusplus
extern "C" {
#endif

struct Object;

void BKE_paint_brush_init(struct Object *ob);
void BKE_paint_brush_set(struct Object *ob, int brush_index);
int BKE_paint_brush_get(struct Object *ob);
void BKE_paint_brush_delete(struct Object *ob);

#ifdef __cplusplus
}
#endif

#endif
