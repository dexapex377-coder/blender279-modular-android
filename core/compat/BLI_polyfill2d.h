#ifndef __BLI_POLYFILL2D_H__
#define __BLI_POLYFILL2D_H__

#ifdef __cplusplus
extern "C" {
#endif

void BLI_polyfill_calc(const float (*coords)[2], const unsigned int coords_len, int (*tris)[3], unsigned int *r_tris_len);
void BLI_polyfill_calc_arena(const float (*coords)[2], unsigned int coords_len, int (*tris)[3], unsigned int *r_tris_len, struct MemArena *arena);
float BLI_polyfill_beautify_quad_rotate_calc(const float v1[2], const float v2[2], const float v3[2], const float v4[2]);

#ifdef __cplusplus
}
#endif

#endif
