#ifndef __IMB_COLORMANAGEMENT_H__
#define __IMB_COLORMANAGEMENT_H__

#ifdef __cplusplus
extern "C" {
#endif

void IMB_colormanagement_init(void);
void IMB_colormanagement_exit(void);
int IMB_colormanagement_support(void);
void IMB_colormanagement_transform(float *buffer, int width, int height, int channels, const char *from, const char *to, int predivide);

#ifdef __cplusplus
}
#endif

#endif
