#!/bin/sh
mkdir -p shellbuild 
cd shellbuild
pip install conan
#sudo conan install ..
cmake ..
cmake --build .
./FibonacciDesTest
