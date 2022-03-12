#!/bin/sh
mkdir shellbuild && cd shellbuild
conan install ..
cmake ..
cmake --build .
./FibonacciDesTest
