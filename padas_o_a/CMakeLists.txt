cmake_minimum_required(VERSION 2.8)
project(algos)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

include_directories(tests)
add_subdirectory(prj.lab)
add_subdirectory(prj.codeforces)