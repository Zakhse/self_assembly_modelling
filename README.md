# Example of filling square lattice with k-mers

This branch is created for testing perfomance of C++ for creating and filling lattices with k-mers.

**gcc**, **make** and **cmake** is required!

To compile run:

```bash
mkdir build
cmake CMakeLists.txt -B ./build/ -DCMAKE_BUILD_TYPE=Release
make -C ./build/
```

To execute test run:

```bash
./build/self_assembly_modelling
```

