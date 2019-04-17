#ifndef SELF_ASSEMBLY_MODELLING_LATTICE_H
#define SELF_ASSEMBLY_MODELLING_LATTICE_H


#include "particle.h"

class Lattice {
public:
    Lattice(int size, int particle_length);

    ~Lattice();

private:
    int size;

    int particle_length;

    Particle ***lattice;

    void generate_lattice();

    void fill_with_particles();
};

#endif //SELF_ASSEMBLY_MODELLING_LATTICE_H
