cmake_minimum_required(VERSION 3.12)
project(labs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

add_subdirectory(rational)
add_subdirectory(m3i)
add_subdirectory(bitset)