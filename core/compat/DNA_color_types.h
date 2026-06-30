#ifndef __DNA_COLOR_TYPES_H__
#define __DNA_COLOR_TYPES_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CurveMapPoint {
    float x, y;
    short flag, shorty;
} CurveMapPoint;

enum {
    CUMA_SELECT = 1,
    CUMA_HANDLE_VECTOR = 2,
    CUMA_HANDLE_AUTO_ANIM = 4,
};

typedef struct CurveMap {
    short totpoint, flag;
    float range;
    float mintable, maxtable;
    float ext_in[2], ext_out[2];
    CurveMapPoint *curve;
    CurveMapPoint *table;
    CurveMapPoint *premultable;
    float premul_ext_in[2];
} CurveMap;

typedef struct rctf {
    float xmin, xmax;
    float ymin, ymax;
} rctf;

typedef struct CurveMapping {
    int flag, cur;
    int preset;
    int changed_timestamp;
    struct rctf curr, clipr;
    CurveMap cm[4];
    float black[3], white[3];
    float bwmul[3];
    float sample[3];
} CurveMapping;

enum {
    CUMA_DO_CLIP = 1,
};

#ifdef __cplusplus
}
#endif

#endif
