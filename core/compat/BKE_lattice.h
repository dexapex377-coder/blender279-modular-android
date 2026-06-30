#ifndef __BKE_LATTICE_H__
#define __BKE_LATTICE_H__

#include "DNA_lattice_types.h"

#ifdef __cplusplus
extern "C" {
#endif

void BKE_lattice_free(Lattice *lt);
void end_latt_deform(struct LatticeDeformData *lattice_deform_data);
void BKE_lattice_deform_data_destroy(struct LatticeDeformData *lattice_deform_data);

#ifdef __cplusplus
}
#endif

#endif