#ifndef __BKE_CAMERA_H__
#define __BKE_CAMERA_H__

#include "DNA_camera_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Object;

void BKE_camera_params_compute_matrix(struct CameraParams *params);
void BKE_camera_params_compute_viewplane(
    struct CameraParams *params, int winx, int winy, float aspx, float aspy);
void BKE_camera_params_init(struct CameraParams *params);
void BKE_camera_params_from_object(struct CameraParams *params, struct Object *camera);

#ifdef __cplusplus
}
#endif

#endif
