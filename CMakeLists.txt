# cmake_minimum_required(VERSION <specify CMake version here>)
project(self_assembly_modelling)

set(CMAKE_CXX_STANDARD 17)

add_executable(self_assembly_modelling main.cpp src/lattice.cpp src/lattice.h src/particle.cpp src/particle.h src/orientation.h src/utils/randomizer_with_sentinel_shift.h src/utils/utils.cpp src/utils/utils.h)
