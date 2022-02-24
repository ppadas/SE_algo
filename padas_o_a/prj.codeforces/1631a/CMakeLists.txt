cmake_minimum_required(VERSION 2.8)
project(codeforces)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SRC_LIST 1631a.cpp)
add_executable(1631a ${SRC_LIST})