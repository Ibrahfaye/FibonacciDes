cmake_minimum_required(VERSION 3.10)
project(FibonacciDes)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
#[[
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)
]]

# Execution conan
option(BUILD_EXEC_CONAN_INSTALL "execute conan install step" OFF)
if(${BUILD_EXEC_CONAN_INSTALL})
    execute_process(COMMAND conan install ${CMAKE_SOURCE_DIR}) # Execution conan install
    include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
endif()

find_package(GTest REQUIRED)
include_directories(${GTest_INCLUDE_DIRS} )
#find_package(GMock REQUIRED)
#set(GTEST_TARGET GTest::GTest GTest::Main)
#set(GMOCK_TARGET GMock::GMock GMock::Main)

set(CMAKE_CXX_STANDARD 11)

add_executable(FibonacciDes main.cpp )

set(srcfiles  Fibonaccisrc/Interfaces/IFibonacciClient.h
        Fibonaccisrc/Implements/FibonnaciClient.cpp
        Fibonaccisrc/Implements/FibonnaciClient.h
        Fibonaccisrc/Interfaces/IFibonacciServer.h Tests/FibonacciServerTest.cpp Fibonaccisrc/Implements/FibonacciServer.cpp Fibonaccisrc/Implements/FibonacciServer.h)

add_executable(FibonacciDesTest maintest.cpp Tests/FibonacciClientTest.cpp ${srcfiles})
target_link_libraries(
        FibonacciDesTest
		gmock
		gtest
		GTest::gtest GTest::gtest_main
)

#include(GoogleTest)
#gtest_discover_tests(FibonacciDesTest)
