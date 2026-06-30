#ifndef __DNA_SCENE_TYPES_H__
#define __DNA_SCENE_TYPES_H__

#include "DNA_listBase.h"
#include "DNA_ID.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Scene {
    struct Scene *next, *prev;
    struct ID id;
    struct Object *camera;
    struct World *world;
    struct Base *basact;
    ListBase base;
    ListBase object;
    ListBase editmesh;
    int lay;
    int lay_act;
    int lay_prev;
    short rmode;
    short mode;
    short rtype;
    short subframe;
    float subframes;
    int flag;
    int frame_step;
    int pad;
    struct SceneRenderLayer *r;
    int r_frs_sec;
    int r_mode;
    int r_size;
    int r_xsch, r_ysch;
    int r_xasp, r_yasp;
    float r_blur_alpha;
    int r_mblur_samples;
    int r_mblur_shutter;
    int r_scemode;
    float r_framapto;
    short r_imagesz;
    short r_views_format;
    struct Object *obedit;
    struct ToolSettings *toolsettings;
    struct Editing *ed;
    struct Curve *curve;
    struct MBox *mbox;
} Scene;

#define FPS (24.0)

/* Scene flags */
#define SCE_SELECT 1

typedef struct ToolSettings {
    short vgroup_weight;
    short vgroup_subset;
    int flag;
    int selectmode;
    int selectmode_vert;
    int selectmode_edge;
    int selectmode_face;
    int proportional;
    int proportional_size;
    int proportional_falloff;
    int proportional_connected;
} ToolSettings;

/* Select modes */
#define SCE_SELECT_VERTEX 1
#define SCE_SELECT_EDGE 2
#define SCE_SELECT_FACE 4

typedef struct Base {
    struct Base *next, *prev;
    unsigned int lay, selcol;
    int flag;
    short sx, sy;
    struct Object *object;
} Base;

#ifdef __cplusplus
}
#endif

#endif
