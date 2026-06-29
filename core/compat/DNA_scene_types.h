#ifndef __DNA_SCENE_TYPES_H__
#define __DNA_SCENE_TYPES_H__

#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Scene {
    struct Scene *next, *prev;
    struct ID id;
    struct Object *camera;
    struct World *world;
    struct Base *base;
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
    struct ToolSettings *toolsettings;
    struct Editing *ed;
    struct Curve *curve;
    struct MBox *mbox;
} Scene;

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

#ifdef __cplusplus
}
#endif

#endif
