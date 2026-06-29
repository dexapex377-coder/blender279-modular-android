#ifndef __BLI_RAND_H__
#define __BLI_RAND_H__

#include <stdint.h>

struct RNG;

struct RNG *BLI_rng_new(unsigned int seed);
struct RNG *BLI_rng_new_srandom(unsigned int seed);
void BLI_rng_free(struct RNG *rng);
void BLI_rng_seed(struct RNG *rng, unsigned int seed);
void BLI_rng_srandom(struct RNG *rng, unsigned int seed);
void BLI_rng_get_char_n(struct RNG *rng, char *bytes, size_t bytes_len);
int BLI_rng_get_int(struct RNG *rng);
unsigned int BLI_rng_get_uint(struct RNG *rng);
double BLI_rng_get_double(struct RNG *rng);
float BLI_rng_get_float(struct RNG *rng);
void BLI_rng_get_float_unit_v2(struct RNG *rng, float v[2]);
void BLI_rng_get_float_unit_v3(struct RNG *rng, float v[3]);
void BLI_rng_get_tri_sample_float_v2(struct RNG *rng, const float v1[2], const float v2[2], const float v3[2], float r_pt[2]);
void BLI_rng_shuffle_array(struct RNG *rng, void *data, unsigned int elem_size_i, unsigned int elem_tot);
void BLI_rng_skip(struct RNG *rng, int n);

void BLI_srandom(unsigned int seed);
int BLI_rand(void);
float BLI_frand(void);
void BLI_frand_unit_v3(float v[3]);
float BLI_hash_frand(unsigned int seed);

#endif /* __BLI_RAND_H__ */