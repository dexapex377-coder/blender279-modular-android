#ifndef __DNA_ID_H__
#define __DNA_ID_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ID {
    void *next, *prev;
    int us, flag;
    int icon_id;
    int recalc;
    char name[70];
    short session_uuid;
} ID;

#ifdef __cplusplus
}
#endif

#endif
