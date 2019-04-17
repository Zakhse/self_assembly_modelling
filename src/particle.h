#ifndef SELF_ASSEMBLY_MODELLING_PARTICLE_H
#define SELF_ASSEMBLY_MODELLING_PARTICLE_H

#include "orientation.h"

class Particle {
public:
    Particle(int id, int length, Orientation orientation);

    int get_id();

    int get_length();

    Orientation get_orientation();

private:
    int id;
    int length;
    Orientation orientation;
};

#endif //SELF_ASSEMBLY_MODELLING_PARTICLE_H
