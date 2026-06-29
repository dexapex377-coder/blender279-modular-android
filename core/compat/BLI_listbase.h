#ifndef __BLI_LISTBASE_H__
#define __BLI_LISTBASE_H__

#include "DNA_listBase.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BLI_listbase_is_empty(list) ((list)->first == NULL)
#define BLI_listbase_count(list) _bli_listbase_count(list)

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

#ifdef __cplusplus
}
#endif

#endif
