#ifndef __DNA_MESHDATA_TYPES_H__
#define __DNA_MESHDATA_TYPES_H__

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

typedef struct MDisps {
    float *disps;
    int totdisp;
    int level;
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

/* MPoly flags */
#define ME_SMOOTH 1
#define ME_FACE_SEL 2

#ifdef __cplusplus
}
#endif

#endif
