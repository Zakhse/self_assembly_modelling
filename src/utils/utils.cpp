#include "utils.h"

void passed_nanoseconds() {
    auto new_now = std::chrono::high_resolution_clock::now();

    std::cout << "Milliseconds passed: " +
                 std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(new_now - tp).count())
              << std::endl;

    tp = new_now;
}
