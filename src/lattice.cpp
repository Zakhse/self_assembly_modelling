#include "lattice.h"

Lattice::Lattice(int size, int particle_length) {
    this->size = size;
    this->particle_length = particle_length;

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
//{
//    file = new std::ifstream;
//    file->open(path, std::ios_base::in);
//    buffer = "";
//    finished = false;
//}