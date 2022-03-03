cmake_minimum_required(VERSION 2.8)
project(m3i)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SRC_LIST test.cpp)

include_directories(./)

add_library(m3i m3i.cpp m3i.h)
add_executable(m3i_test ${SRC_LIST})

target_link_libraries(m3i_test m3i)