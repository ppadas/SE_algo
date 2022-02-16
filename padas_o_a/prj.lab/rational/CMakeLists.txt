cmake_minimum_required(VERSION 2.8)
project(rational)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SRC_LIST rational.h rational.cpp doctest.h test.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})