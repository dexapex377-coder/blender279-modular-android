#ifndef __BKE_OCEAN_H__
#define __BKE_OCEAN_H__

struct OceanModifierData;
struct DerivedMesh;

void oceanModifier_do(struct OceanModifierData *omd, struct DerivedMesh *dm);

#endif
