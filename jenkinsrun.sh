#!/bin/sh
mkdir -p shellbuild 
cd shellbuild
pip3 install conan
sudo conan install ..
cmake ..
cmake --build .
./FibonacciDesTest
