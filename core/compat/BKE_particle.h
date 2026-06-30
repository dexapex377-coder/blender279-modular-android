#ifndef __BKE_PARTICLE_H__
#define __BKE_PARTICLE_H__

struct ParticleSystemModifierData;
struct ParticleSystem;
struct ParticleData;
struct ParticleKey;
struct ParticleSimulationData;
struct LatticeDeformData;
struct Scene;
struct Object;
struct DerivedMesh;

typedef struct ParticleSimulationData {
    struct Scene *scene;
    struct Object *ob;
    struct ParticleSystem *psys;
    struct ParticleSystemModifierData *psmd;
    struct ListBase *colliders;
    float courant_num;
} ParticleSimulationData;

#define PARTICLE_PSMD ParticleSystemModifierData *psmd = sim->psmd ? sim->psmd : psys_get_modifier(sim->ob, sim->psys)
#define LOOP_EXISTING_PARTICLES for (p = 0, pa = psys->particles; p < psys->totpart; p++, pa++) if (!(pa->flag & PARS_UNEXIST))
#define LOOP_SHOWN_PARTICLES for (p = 0, pa = psys->particles; p < psys->totpart; p++, pa++) if (!(pa->flag & (PARS_UNEXIST | PARS_NO_DISP)))

struct ParticleSystemModifierData *psys_get_modifier(struct Object *ob, struct ParticleSystem *psys);
void psys_particle_on_emitter(
        struct ParticleSystemModifierData *psmd, int distr, int index, int index_dmcache,
        float fuv[4], float foffset, float vec[3], float nor[3],
        float utan[3], float vtan[3], float orco[3], float ornor[3]);
struct LatticeDeformData *psys_create_lattice_deform_data(struct ParticleSimulationData *sim);
void psys_get_birth_coords(struct ParticleSimulationData *sim, struct ParticleData *pa, struct ParticleKey *state, float dtime, float cfra);
int psys_get_particle_state(struct ParticleSimulationData *sim, int p, struct ParticleKey *state, int always);

void psys_free_particles(struct ParticleSystem *psys);

#endif
