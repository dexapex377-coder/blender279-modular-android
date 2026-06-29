#ifndef __DNA_LISTBASE_H__
#define __DNA_LISTBASE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Link {
    struct Link *next, *prev;
} Link;

typedef struct ListBase {
    void *first, *last;
} ListBase;

#ifdef __cplusplus
}
#endif

#endif
