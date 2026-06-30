#ifndef __BLI_UVPROJECT_H__
#define __BLI_UVPROJECT_H__

#ifdef __cplusplus
extern "C" {
#endif

void BLI_uvproject_from_camera(float target[2], float source[3], float mat[4][4]);

#ifdef __cplusplus
}
#endif

#endif
