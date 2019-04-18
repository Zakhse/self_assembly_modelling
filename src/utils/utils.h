#ifndef SELF_ASSEMBLY_MODELLING_UTILS_H
#define SELF_ASSEMBLY_MODELLING_UTILS_H

#include <random>
#include <chrono>
#include <iostream>

static std::random_device rd; // NOLINT(cert-err58-cpp)
static std::mt19937 rng(rd()); // NOLINT(cert-err58-cpp)
static auto tp = std::chrono::high_resolution_clock::now();

void passed_nanoseconds();

template<typename ContainerType>
typename ContainerType::value_type random_from_unordered_set(ContainerType &set) {
    std::uniform_int_distribution<std::size_t> distr(0, set.size() - 1);
    std::size_t index = distr(rng);

    auto iterator = set.begin();

    while (index > 0) {
        --index;
        ++iterator;
    }

    return *iterator;
}

#endif //SELF_ASSEMBLY_MODELLING_UTILS_H
