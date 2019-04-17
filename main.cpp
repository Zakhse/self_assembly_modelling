#include <iostream>
#include <chrono>
#include "src/lattice.h"

using namespace std::chrono;

int main() {
    duration t1 = system_clock::now().time_since_epoch();
    std::cout << std::to_string(duration_cast<milliseconds>(t1).count()) << std::endl;

    for (int i = 0; i < 1000; i++) {
        Lattice l = Lattice(256, 8);
    }

    duration t2 = system_clock::now().time_since_epoch();
    std::cout << std::to_string(duration_cast<milliseconds>(t2).count()) << std::endl;


    std::cout << "Milliseconds passed: " + std::to_string(duration_cast<milliseconds>(t2 - t1).count());
}