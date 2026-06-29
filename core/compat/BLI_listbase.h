#ifndef __BLI_LISTBASE_H__
#define __BLI_LISTBASE_H__

#include "DNA_listBase.h"
#include "BLI_compiler_attrs.h"
#include "MEM_guardedalloc.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BLI_listbase_is_empty(list) ((list)->first == NULL)
#define BLI_listbase_count(list) _bli_listbase_count(list)

/* Standard linked list node types */
typedef struct LinkNode {
    struct LinkNode *next;
    void *link;
} LinkNode;

typedef struct LinkData {
    struct LinkData *next, *prev;
    void *data;
} LinkData;

int _bli_listbase_count(const ListBase *list);

void BLI_addhead(ListBase *listbase, void *vlink);
void BLI_addtail(ListBase *listbase, void *vlink);
void BLI_remlink(ListBase *listbase, void *vlink);
void BLI_insertlinkafter(ListBase *listbase, void *vprevlink, void *vnewlink);
void BLI_insertlinkbefore(ListBase *listbase, void *vnextlink, void *vnewlink);
void BLI_freelistN(ListBase *listbase);
void *BLI_findlink(const ListBase *listbase, int number);
int BLI_findindex(const ListBase *listbase, const void *vlink);
void BLI_movelisttolist(ListBase *dst, ListBase *src);
void *BLI_findptr(const ListBase *list, const void *ptr, int offset);
void BLI_freelinkN(ListBase *list, void *vlink);
void BLI_duplicatelist(ListBase *dest, const ListBase *src);
void *BLI_pophead(ListBase *list);
void *BLI_genericNodeN(const void *data);
void BLI_listbase_reverse(ListBase *lb);
void BLI_listbase_sort(ListBase *lb, int (*cmp)(const void *, const void *));

#ifdef __cplusplus
}
#endif

/* Inline stubs for implementations */
BLI_INLINE void *BLI_findptr(const ListBase *list, const void *ptr, int offset) { (void)list; (void)ptr; (void)offset; return NULL; }
BLI_INLINE void BLI_freelinkN(ListBase *list, void *vlink) { BLI_remlink(list, vlink); MEM_freeN(vlink); }
BLI_INLINE void BLI_duplicatelist(ListBase *dest, const ListBase *src) { (void)dest; (void)src; }
BLI_INLINE void *BLI_pophead(ListBase *list) { void *f = list->first; if (f) BLI_remlink(list, f); return f; }
BLI_INLINE void *BLI_genericNodeN(const void *data) { (void)data; return NULL; }
BLI_INLINE void BLI_listbase_reverse(ListBase *lb) { (void)lb; }
BLI_INLINE void BLI_listbase_sort(ListBase *lb, int (*cmp)(const void *, const void *)) { (void)lb; (void)cmp; }

#endif
