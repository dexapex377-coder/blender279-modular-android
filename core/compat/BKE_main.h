#ifndef __BKE_MAIN_H__
#define __BKE_MAIN_H__

#include "DNA_listBase.h"
#include "DNA_scene_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Main {
    struct Main *next, *prev;
    ListBase scene;
    ListBase object;
    ListBase mesh;
    ListBase material;
    ListBase texture;
    ListBase image;
    ListBase world;
    ListBase lamp;
    ListBase camera;
    ListBase curve;
    ListBase lattice;
    ListBase mball;
    ListBase font;
    ListBase screen;
    ListBase wm;
    ListBase action;
    ListBase node;
    ListBase movieclip;
    ListBase bpointcache;
    ListBase gpencil;
    ListBase palette;
    ListBase cachefiledir;
    ListBase pc;
    char name[1024];
    int curlib;
    int versionfile, subversionfile;
    int minversionfile, minsubversionfile;
    int flag;
    struct GHash *relations;
} Main;

extern Main *G.main;

#ifdef __cplusplus
}
#endif

#endif
