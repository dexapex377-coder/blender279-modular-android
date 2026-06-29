#ifndef __BKE_NODE_H__
#define __BKE_NODE_H__

#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct bNode {
    struct bNode *next, *prev;
    void *data;
    int type;
    int flag;
    int tmp;
    short len;
    short id;
    char name[64];
    ListBase inputs;
    ListBase outputs;
    float locx, locy;
    float width, height;
    float miniwidth;
    float color[3];
    int pad;
} bNode;

typedef struct bNodeLink {
    struct bNodeLink *next, *prev;
    struct bNode *fromnode;
    struct bNode *tonode;
    struct bNodeSocket *fromsock;
    struct bNodeSocket *tosock;
    int flag;
    int pad;
} bNodeLink;

typedef struct bNodeSocket {
    struct bNodeSocket *next, *prev;
    void *data;
    int type;
    int flag;
    int limit;
    char name[64];
    char identifier[64];
    struct bNode *owner;
} bNodeSocket;

typedef struct bNodeTree {
    struct bNodeTree *next, *prev;
    struct ID id;
    int type;
    int flag;
    ListBase nodes;
    ListBase links;
    void *data;
} bNodeTree;

typedef struct bNodeTreeType {
    int type;
    char name[64];
} bNodeTreeType;

void nodeRegisterType(struct bNodeTreeType *type);
void nodeUnregisterType(struct bNodeTreeType *type);
struct bNodeTree *ntreeAddTree(int type, const char *name);

#ifdef __cplusplus
}
#endif

#endif
