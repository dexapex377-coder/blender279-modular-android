#ifndef __BLI_LINKLIST_H__
#define __BLI_LINKLIST_H__

#include "DNA_listBase.h"
#include "BLI_listbase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LinkNode {
    struct LinkNode *next;
    void *link;
} LinkNode;

void BLI_linklist_prepend(LinkNode **list, void *link);
void BLI_linklist_prepend_n(LinkNode **list, void *link, LinkNode *node);
void BLI_linklist_append(LinkNode **list, void *link);
void BLI_linklist_append_n(LinkNode **list, void *link, LinkNode *node);
void BLI_linklist_free(LinkNode *list, void (*freefunc)(void *));
void BLI_linklist_freeN(LinkNode *list);
int BLI_linklist_count(LinkNode *list);
void *BLI_linklist_find(LinkNode *list, void *ptr);
int BLI_linklist_index(LinkNode *list, void *ptr);
void BLI_linklist_reverse(LinkNode **list);
void BLI_linklist_move_item(LinkNode **list, int from, int to);

#ifdef __cplusplus
}
#endif

#endif
