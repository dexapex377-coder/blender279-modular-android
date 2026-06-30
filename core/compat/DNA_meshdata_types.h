#ifndef __DNA_MESHDATA_TYPES_H__
#define __DNA_MESHDATA_TYPES_H__

#include "DNA_object_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct MVert {
    float co[3];
    short no[3];
    char flag, bweight;
} MVert;

typedef struct MEdge {
    unsigned int v1, v2;
    char flag, bweight, crease;
} MEdge;

typedef struct MLoop {
    unsigned int v;
    unsigned int e;
} MLoop;

typedef struct MLoopUV {
    float uv[2];
    int flag;
} MLoopUV;

typedef struct MPoly {
    int loopstart;
    int totloop;
    short mat_nr;
    char flag, pad;
} MPoly;

typedef struct MFace {
    unsigned int v1, v2, v3, v4;
    short mat_nr;
    char flag, edcode;
} MFace;

typedef struct MSelect {
    int index;
    int type;
} MSelect;

typedef struct MLoopTri {
    unsigned int tri[3];
    unsigned int poly;
} MLoopTri;

typedef struct MVertTri {
    unsigned int verts[3];
} MVertTri;

typedef struct MVertSkin {
    float radius[3];
    int flag;
} MVertSkin;

enum {
    MVERT_SKIN_ROOT = 1,
    MVERT_SKIN_LOOSE = 2,
};

typedef struct MDisps {
    int totdisp;
    int level;
    float (*disps)[3];
    unsigned int *hidden;
    int side;
    int flags;
} MDisps;

/* MVert flags */
#define SELECT 1
#define MV_HIDE 2

/* MEdge flags */
#define ME_EDGEDRAW     1
#define ME_SEAM         2
#define ME_HIDE         4
#define ME_LOOSEEDGE    8
#define ME_EDGERENDER   16
#define ME_SHARP        1   /* same as ME_EDGEDRAW in 2.79 */

/* MVert flags */
#define ME_VERT_SEL   (1<<1)  /* vertex select flag */
#define ME_VERT_TMP_TAG (1 << 2)
#define ME_VERT_MERGED (1 << 6)
#define ME_VERT_PBVH_UPDATE (1 << 7)

/* MEdge flags */
#define ME_EDGE_SEL   (1<<1)  /* edge select flag */

/* MPoly flags */
#define ME_SMOOTH 1
#define ME_FACE_SEL 2
#define ME_FACE_FLAG_SEL   (1<<1)  /* face select flag */

/* mselect->type */
enum {
    ME_VSEL = 0,
    ME_ESEL = 1,
    ME_FSEL = 2,
};

#define ME_CDFLAG_VERT_BWEIGHT (1<<2)
#define ME_CDFLAG_EDGE_BWEIGHT (1<<4)
#define ME_CDFLAG_EDGE_CREASE  (1<<5)

/* tessellation uv face data */
typedef struct MTFace {
    float uv[4][2];
    struct Image *tpage;
    char flag, transp;
    short mode, tile, unwrap;
} MTFace;

enum {
    TF_SEL1   = (1 << 2),
    TF_SEL2   = (1 << 3),
    TF_SEL3   = (1 << 4),
    TF_SEL4   = (1 << 5),
};

enum {
    TF_DYNAMIC    = (1 << 0),
    TF_ALPHASORT  = (1 << 1),
    TF_TEX        = (1 << 2),
    TF_SHAREDVERT = (1 << 3),
    TF_LIGHT      = (1 << 4),
    TF_CONVERTED  = (1 << 5),
    TF_SHAREDCOL  = (1 << 6),
    TF_BILLBOARD  = (1 << 8),
    TF_TWOSIDE    = (1 << 9),
    TF_INVISIBLE  = (1 << 10),
    TF_OBCOL      = (1 << 11),
    TF_BILLBOARD2 = (1 << 12),
    TF_SHADOW     = (1 << 13),
    TF_BMFONT     = (1 << 14),
};

enum {
    TF_SOLID = 0,
    TF_ADD   = (1 << 0),
    TF_ALPHA = (1 << 1),
    TF_CLIP  = (1 << 2),
    TF_SUB   = 3,
};

#ifdef __cplusplus
}
#endif

#endif
