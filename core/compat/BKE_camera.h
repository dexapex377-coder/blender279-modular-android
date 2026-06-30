#ifndef __BKE_CAMERA_H__
#define __BKE_CAMERA_H__

#ifdef __cplusplus
extern "C" {
#endif

struct Object;

void BKE_camera_params_compute_matrix(
    struct Object *camera, float winx, float winy, float scale, float r_winmat[4][4]);

#ifdef __cplusplus
}
#endif

#endif
