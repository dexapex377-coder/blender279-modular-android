#ifndef __BLI_SYSTEM_H__
#define __BLI_SYSTEM_H__

#ifdef __cplusplus
extern "C" {
#endif

int BLI_cpu_support_sse2(void);
int BLI_cpu_support_sse3(void);
int BLI_cpu_support_sse41(void);
int BLI_cpu_support_avx(void);
int BLI_cpu_support_avx2(void);

int BLI_system_memory_max_in_megabytes(void);
void BLI_system_backtrace(FILE *fp);

#ifdef __cplusplus
}
#endif

#endif
