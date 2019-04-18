#include <iostream>
#include "lattice.h"

std::random_device Lattice::rd; // NOLINT(cert-err58-cpp)

Lattice::Lattice(int size, int particle_length) {
    this->size = size;
    this->particle_length = particle_length;
    this->lattice = nullptr;

    init_random();
    generate_lattice();
    fill_with_particles();
}

void Lattice::generate_lattice() {
    lattice = new Particle **[size];
    for (int i = 0; i < size; ++i) {
        lattice[i] = new Particle *[size];
        for (int j = 0; j < size; ++j)
            lattice[i][j] = nullptr;
    }
}

void Lattice::fill_with_particles() {

}

Lattice::~Lattice() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            delete lattice[i][j];
        }
        delete[] lattice[i];
    }
    delete[] lattice;
}

void Lattice::init_random() {
    rng = MyRng(rd());
}

bool Lattice::random_bool() {
    return bool_rng(rng);
}
