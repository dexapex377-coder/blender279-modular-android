#ifndef __PIL_TIME_H__
#define __PIL_TIME_H__

#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

double PIL_check_seconds_timer(void);
int PIL_check_seconds_timer_i(void);
void PIL_sleep_ms(int ms);

#ifdef __cplusplus
}
#endif

#endif
