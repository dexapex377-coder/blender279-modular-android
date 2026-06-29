#ifndef __BLI_POLYFILL2D_BEAUTIFY_H__
#define __BLI_POLYFILL2D_BEAUTIFY_H__

#ifdef __cplusplus
extern "C" {
#endif

struct Heap;
struct MemArena;

void BLI_polyfill_beautify(const float (*coords)[2], unsigned int coords_len, int (*tris)[3], struct MemArena *arena, struct Heap *heap);

#ifdef __cplusplus
}
#endif

#endif
