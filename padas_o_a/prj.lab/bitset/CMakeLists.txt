cmake_minimum_required(VERSION 3.12)
project(bitset)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SRC_LIST test.cpp)

include_directories(./)

add_library(bitset bitset.cpp bitset.h)
add_executable(bitset_test ${SRC_LIST})

target_link_libraries(bitset_test bitset)