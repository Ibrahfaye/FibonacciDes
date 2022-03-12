#!/bin/sh
mkdir shellbuild 
cd shellbuild
pip install conan
conan install ..
cmake ..
cmake --build .
./FibonacciDesTest
