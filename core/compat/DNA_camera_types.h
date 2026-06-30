#ifndef __DNA_CAMERA_TYPES_H__
#define __DNA_CAMERA_TYPES_H__

#include "DNA_ID.h"
#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Camera {
    ID id;
    struct AnimData *adt;
    float drawsize;
    float ortho_scale;
    float clipsta, clipend;
    float lens;
    float shiftx, shifty;
    float sensor_x, sensor_y;
    float pixsize;
    float yco_scale;
    float unitmat[4][4];
    float passepartalpha;
    float interocular_distance;
    float convergence_distance;
    short type;
    short flag;
    short dtx;
    short dtx_lower;
    short stereo_flag;
    short sensor_fit;
    float winmat[4][4];
    float viewplane[4];
} Camera;

typedef struct CameraParams {
    struct Camera *camera;
    struct Object *ob;
    int type;
    float clipsta, clipend;
    float lens;
    float sensor_x, sensor_y;
    float shiftx, shifty;
    float ofs[2];
    float winmat[4][4];
    float yco_scale;
    int is_ortho;
    float zoom;
    float xasp, yasp;
    float pixsize;
} CameraParams;

#define CAM_PANO 1

#ifdef __cplusplus
}
#endif

#endif
