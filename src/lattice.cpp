#include <iostream>
#include <unordered_set>
#include "lattice.h"
#include <memory>

struct IntPairHash {
    size_t operator()(const std::pair<int, int> &p) const {
        size_t k = (((uint32_t) p.first) << 16u) | ((uint32_t) p.second);
        return k;
    }
};

typedef std::pair<int, int> PointType;
typedef std::unordered_set<PointType, IntPairHash> HashSetForPoints;

std::random_device Lattice::rd; // NOLINT(cert-err58-cpp)

Lattice::Lattice(int size, int particle_length) {
    this->size = size;
    this->particle_length = particle_length;

    init_random();
    generate_lattice();
    fill_with_particles();

}

void Lattice::generate_lattice() {
    this->clear_lattice();
    lattice = new std::shared_ptr<Particle> **[size];
    for (int i = 0; i < size; ++i) {
        lattice[i] = new std::shared_ptr<Particle> *[size];
        for (int j = 0; j < size; ++j)
            lattice[i][j] = nullptr;
    }
}

void Lattice::fill_with_particles() {
    HashSetForPoints point_for_vertical({});
    HashSetForPoints point_for_horizontal({});

    for (int i = 0; i <= size - particle_length; i++) {
        for (int j = 0; j < size; j++)
            point_for_horizontal.emplace(PointType(i, j));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= size - particle_length; j++)
            point_for_vertical.emplace(PointType(i, j));
    }

    int number_of_placed_particles = 0;
    Orientation chosen_orientation;
    int X, Y;
    PointType chosen_point;
//    Particle *particle_to_place;
    while (!(point_for_horizontal.empty() && point_for_vertical.empty())) {
        if (point_for_horizontal.empty() || (!point_for_vertical.empty() && random_bool())) {
            chosen_orientation = ORIENTATION_VERTICAL;
            chosen_point = random_from_unordered_set(point_for_vertical);
        } else {
            chosen_orientation = ORIENTATION_HORIZONTAL;
            chosen_point = random_from_unordered_set(point_for_horizontal);
        }

        X = chosen_point.first;
        Y = chosen_point.second;
        std::shared_ptr<Particle> ptr = std::make_shared<Particle>(
                number_of_placed_particles + 1, particle_length, chosen_orientation
        );

        // Placing particle
        if (chosen_orientation == ORIENTATION_HORIZONTAL) {
            for (int i = X; i < X + particle_length; i++)
                lattice[i][Y] = new std::shared_ptr<Particle>(ptr);
        } else {
            for (int j = Y; j < Y + particle_length; j++)
                lattice[X][j] = new std::shared_ptr<Particle>(ptr);
        }

        // Remove points that can't have a head of any particle now
        if (chosen_orientation == ORIENTATION_HORIZONTAL) {
            for (int i = std::max(0, X - particle_length + 1); i <= X + particle_length - 1; i++)
                point_for_horizontal.erase(PointType(i, Y));

            for (int i = X; i <= X + particle_length - 1; i++) {
                for (int j = std::max(0, Y - particle_length + 1); j <= Y; j++)
                    point_for_vertical.erase(PointType(i, j));
            }
        } else {
            for (int i = std::max(0, Y - particle_length + 1); i <= Y + particle_length - 1; i++)
                point_for_vertical.erase(PointType(X, i));

            for (int j = Y; j < Y + particle_length; j++) {
                for (int i = std::max(0, X - particle_length + 1); i <= X; i++)
                    point_for_horizontal.erase(PointType(i, j));
            }
        }

        ++number_of_placed_particles;
    }
}

void Lattice::clear_lattice() {
    if (lattice == nullptr)
        return;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (lattice[i][j]) {
                delete lattice[i][j];
            }
        }
        delete[] lattice[i];
    }
    delete[] lattice;
    lattice = nullptr;
}

Lattice::~Lattice() {
    this->clear_lattice();
}

void Lattice::init_random() {
    rng = MyRng(rd());
}

bool Lattice::random_bool() {
    return bool_rng(rng);
}



void Lattice::print() {
    std::cout << std::endl;
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            char c;
            std::shared_ptr<Particle> *ptr = lattice[i][j];
            if (ptr == nullptr) {
                c = ' ';
            } else if (ptr->get()->get_orientation() == ORIENTATION_HORIZONTAL) {
                c = '-';
            } else {
                c = '|';
            }

            std::cout << c << ' ';
        }
        std::cout << std::endl;
    }
}
