#ifndef __BLI_QUADRIC_H__
#define __BLI_QUADRIC_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    double a2, ab, ac, ad, b2, bc, bd, c2, cd, d2;
} Quadric;

void BLI_quadric_from_plane(Quadric *q, const double v[4]);
void BLI_quadric_to_plane(const Quadric *q, double v[4]);
void BLI_quadric_add_qu_qu(Quadric *a, const Quadric *b);
void BLI_quadric_add_qu_ququ(Quadric *r, const Quadric *a, const Quadric *b);
double BLI_quadric_evaluate(const Quadric *q, const double v[3]);
int BLI_quadric_optimize(const Quadric *q, double v[3], double epsilon);

#ifdef __cplusplus
}
#endif

#endif
