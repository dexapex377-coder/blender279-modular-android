#ifndef __DNA_OBJECT_TYPES_H__
#define __DNA_OBJECT_TYPES_H__

#include "DNA_listBase.h"
#include "DNA_softbody_types.h"
#include "DNA_ID.h"
#include "DNA_scene_types.h"
#include "DNA_modifier_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct PartDeflect;

typedef struct Object {
    struct Object *next, *prev;
    struct ID id;
    int type;
    int flag;
    int mode;
    unsigned int lay;
    int restrictflag;
    float loc[3];
    float rot[3];
    float scale[3];
    float dscale[3];
    float drot[3];
    float dloc[3];
    struct Object *parent;
    struct Object *track;
    ListBase constraints;
    ListBase particlesystem;
    ListBase modifiers;
    short partype;
    short transflag;
    short trackflag2;
    short upflag2;
    int par1, par2, par3;
    struct Mesh *data;
    struct PartDeflect *pd;
    struct SoftBody *soft;
    struct Material **mat;
    ListBase defbase;
    int totcol;
    int actcol;
    int colbits;
    short *matbits;
    float imat[4][4];
    float obmat[4][4];
    float parentinv[4][4];
    float constinv[4][4];
    float size[3];
    short trackflag, upflag;
    char shapeflag;
    struct BoundBox *bb;
    struct CurveCache *curve_cache;
    struct bPose *pose;
    struct DerivedMesh *derivedFinal;
    struct DerivedMesh *derivedDeform;
    unsigned long long lastDataMask;
} Object;

/* Parent types */
enum {
    PAROBJECT1 = 0,
    PAROBJECT  = 0,
    PARCURVE   = 1,
    PARKEY     = 2,
    PARVERT1   = 3,
    PARVERT3   = 5,
    PARBONE    = 7,
};

/* Object types */
enum {
    OB_EMPTY = 0,
    OB_MESH = 1,
    OB_CURVE = 2,
    OB_SURF = 3,
    OB_FONT = 4,
    OB_MBALL = 5,
    OB_LAMP = 10,
    OB_CAMERA = 11,
    OB_WAVE = 21,
    OB_LATTICE = 22,
};

/* Object transflag values */
#define OB_NO_PSYS_UPDATE (1 << 14)

/* Object shapeflag values */
#define OB_SHAPE_LOCK (1 << 0)

#ifdef __cplusplus
}
#endif

#endif
