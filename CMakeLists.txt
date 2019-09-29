cmake_minimum_required(VERSION 3.12)
project(0002_USACO_Training)

set(CMAKE_CXX_STANDARD 11)

# I'm not renaming the test target for this :/
if(POLICY CMP0037)
    cmake_policy(SET CMP0037 OLD)
endif()

add_executable(test_harness test_harness.cc)
add_executable(test test.cc)
add_executable(ride ride.cc)
add_executable(gift1 gift1.cc)
add_executable(friday friday.cc)

enable_testing()

add_test(test_test test_harness test)