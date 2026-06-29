#ifndef __BLI_MATH_BITS_H__
#define __BLI_MATH_BITS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int bitscan_forward(int a);
int bitscan_reverse(int a);
int bitscan_forward_i(int a);
int bitscan_reverse_i(int a);
int bitscan_forward_u(unsigned int a);
int bitscan_reverse_u(unsigned int a);
int bitscan_forward_ull(unsigned long long a);
int bitscan_reverse_ull(unsigned long long a);
int bitscan_forward_u64(uint64_t a);
int bitscan_reverse_u64(uint64_t a);

#ifdef __cplusplus
}
#endif

#endif
