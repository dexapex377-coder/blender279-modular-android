#ifndef __DNA_OBJECT_FLUIDSIM_H__
#define __DNA_OBJECT_FLUIDSIM_H__

#include "DNA_ID.h"
#include "DNA_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

struct FluidsimModifierData;
struct Ipo;
struct PointCache;

typedef struct FluidsimSettings {
    struct FluidsimModifierData *fmd;
    int threads;
    int pad1;
    short type;
    short show_advancedoptions;
    short resolutionxyz;
    short previewresxyz;
    float realsize;
    short guiDisplayMode;
    short renderDisplayMode;
    float viscosityValue;
    short viscosityMode DNA_DEPRECATED;
    short viscosityExponent;
    float grav[3];
    float animStart, animEnd;
    int bakeStart, bakeEnd;
    int frameOffset;
    int pad2;
    float gstar;
    int maxRefine;
    float iniVelx, iniVely, iniVelz;
    char surfdataPath[1024];
    float bbStart[3], bbSize[3];
    struct Ipo *ipo;
    short typeFlags;
    char domainNovecgen, volumeInitType;
    float partSlipValue;
    int generateTracers;
    float generateParticles;
    float surfaceSmoothing;
    int surfaceSubdivs;
    int flag;
    int pad3[4];
} FluidsimSettings;

/* type */
enum {
    OB_FLUIDSIM_DOMAIN = 0,
    OB_FLUIDSIM_FLUID  = 1,
    OB_FLUIDSIM_OBSTACLE = 2,
    OB_FLUIDSIM_INFLOW = 3,
    OB_FLUIDSIM_OUTFLOW = 4,
    OB_FLUIDSIM_PARTICLE = 5,
    OB_FLUIDSIM_CONTROL = 6,
};

#ifdef __cplusplus
}
#endif

#endif
