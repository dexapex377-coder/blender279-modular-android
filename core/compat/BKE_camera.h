#ifndef __BKE_CAMERA_H__
#define __BKE_CAMERA_H__

#include "DNA_camera_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Object;

void BKE_camera_params_compute_matrix(
    struct CameraParams *params, float winx, float winy, float scale, float r_winmat[4][4]);
void BKE_camera_params_init(struct CameraParams *params);
void BKE_camera_params_from_object(struct CameraParams *params, struct Object *camera);

#ifdef __cplusplus
}
#endif

#endif
