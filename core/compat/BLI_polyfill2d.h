#ifndef __BLI_POLYFILL2D_H__
#define __BLI_POLYFILL2D_H__

#ifdef __cplusplus
extern "C" {
#endif

void BLI_polyfill_calc(const float (*coords)[2], const unsigned int coords_len, int (*tris)[3], unsigned int *r_tris_len);

#ifdef __cplusplus
}
#endif

#endif
