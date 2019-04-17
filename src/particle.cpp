#include "particle.h"

Particle::Particle(int id, int length, Orientation orientation) {
    this->id = id;
    this->length = length;
    this->orientation = orientation;
}

int Particle::get_id() {
    return id;
}

int Particle::get_length() {
    return length;
}

Orientation Particle::get_orientation() {
    return orientation;
}
