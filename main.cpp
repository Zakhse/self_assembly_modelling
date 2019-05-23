#include <iostream>
#include <chrono>
#include "src/lattice.h"
#include "src/utils/utils.h"

using namespace std::chrono;

int main() {
    passed_nanoseconds();

    for (int i = 0; i < 40; i++) {
        Lattice l = Lattice(256, 8);
    }

    passed_nanoseconds();
}
