#ifndef __BKE_PARTICLE_H__
#define __BKE_PARTICLE_H__

struct ParticleSystem;
struct Object;

void psys_free(struct Object *ob, struct ParticleSystem *psys);

#endif
