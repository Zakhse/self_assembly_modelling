#ifndef SELF_ASSEMBLY_MODELLING_LATTICE_H
#define SELF_ASSEMBLY_MODELLING_LATTICE_H

#include <memory>
#include "particle.h"
#include "./utils/randomizer_with_sentinel_shift.h"
#include "./utils/utils.h"

typedef std::mt19937 MyRng;
typedef RandomizerWithSentinelShift<uint32_t, MyRng> MyBoolRng;

class Lattice {
public:
    Lattice(int size, int particle_length);

    ~Lattice();

    void print();

private:
    int size;

    int particle_length;

    std::shared_ptr<Particle> ***lattice = nullptr;

    void clear_lattice();

    MyRng rng;

    MyBoolRng bool_rng;

    static std::random_device rd;

    bool random_bool();

    void init_random();

    void generate_lattice();

    void fill_with_particles();
};

#endif //SELF_ASSEMBLY_MODELLING_LATTICE_H
