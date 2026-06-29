#ifndef __BLI_MATH_MATRIX_H__
#define __BLI_MATH_MATRIX_H__

#include <string.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SpaceTransform {
    float local2target[4][4];
    float target2local[4][4];
} SpaceTransform;

void BLI_space_transform_from_matrices(struct SpaceTransform *data, float local[4][4], float target[4][4]);
void BLI_space_transform_apply(const struct SpaceTransform *data, float co[3]);
void BLI_space_transform_invert(const struct SpaceTransform *data, float co[3]);
void BLI_space_transform_apply_normal(const struct SpaceTransform *data, float no[3]);
void BLI_space_transform_invert_normal(const struct SpaceTransform *data, float no[3]);

#define BLI_SPACE_TRANSFORM_SETUP(data, local, target) \
    BLI_space_transform_from_matrices((data), (local)->obmat, (target)->obmat)

#ifdef __cplusplus
}
#endif

#endif
