#ifndef __DNA_SCENE_TYPES_H__
#define __DNA_SCENE_TYPES_H__

#include "DNA_listBase.h"
#include "DNA_ID.h"
#include "DNA_sculpt_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct RenderData {
    int frs_sec;
    int mode;
    int size;
    int cfra;
    int xsch, ysch;
    int xasp, yasp;
    float blur_alpha;
    int mblur_samples;
    int mblur_shutter;
    int scemode;
    float framapto;
    short imagesz;
    short views_format;
} RenderData;

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
    RenderData r;
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
    int multipaint;
    short weightuser;
    short auto_normalize;
    short statvis;
    short pad2;
    struct Sculpt *sculpt;
} ToolSettings;

typedef struct ColorBand {
    int flag;
    int tot;
    float curval;
    struct ColorBandElement *els;
} ColorBand;

typedef struct ColorBandElement {
    float pos;
    float r, g, b, a;
} ColorBandElement;

#define SCULPT_ONLY_DEFORM (1 << 0)

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
