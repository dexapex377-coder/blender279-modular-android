#ifndef __BKE_MAIN_H__
#define __BKE_MAIN_H__

#include "DNA_listBase.h"
#include "DNA_scene_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Main {
    struct Main *next, *prev;
    char name[1024];
    short versionfile, subversionfile;
    short minversionfile, minsubversionfile;
    int curlib;
    ListBase scene;
    ListBase library;
    ListBase object;
    ListBase mesh;
    ListBase curve;
    ListBase mball;
    ListBase mat;
    ListBase tex;
    ListBase image;
    ListBase latt;
    ListBase lamp;
    ListBase camera;
    ListBase ipo;
    ListBase key;
    ListBase world;
    ListBase screen;
    ListBase vfont;
    ListBase text;
    ListBase speaker;
    ListBase sound;
    ListBase group;
    ListBase armature;
    ListBase action;
    ListBase nodetree;
    ListBase brush;
    ListBase particle;
    ListBase palettes;
    ListBase paintcurves;
    ListBase wm;
    ListBase gpencil;
    ListBase movieclip;
    ListBase mask;
    ListBase linestyle;
    ListBase cachefiles;
} Main;

extern struct Global G;

#ifdef __cplusplus
}
#endif

#endif