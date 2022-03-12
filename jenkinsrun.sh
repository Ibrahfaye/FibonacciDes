#!/bin/sh
mkdir shellbuild && cd shellbuild
cmake ..
cmake --build .
./FibonacciDesTest
