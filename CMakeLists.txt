cmake_minimum_required(VERSION 3.10)
project(FibonacciDes)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 11)

add_executable(FibonacciDes main.cpp )

set(srcfiles  Fibonaccisrc/Interfaces/IFibonacciClient.h
        Fibonaccisrc/Implements/FibonnaciClient.cpp
        Fibonaccisrc/Implements/FibonnaciClient.h
        Fibonaccisrc/Interfaces/IFibonacciServer.h Tests/FibonacciServerTest.cpp Fibonaccisrc/Implements/FibonacciServer.cpp Fibonaccisrc/Implements/FibonacciServer.h)

add_executable(FibonacciDesTest maintest.cpp Tests/FibonacciClientTest.cpp ${srcfiles})
target_link_libraries(
        FibonacciDesTest
        gtest_main
        gmock_main
)
include(GoogleTest)
gtest_discover_tests(FibonacciDesTest)
