cmake_minimum_required(VERSION 2.8)
project(rational)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SRC_LIST test.cpp)

include_directories(./)

add_library(rational rational.cpp rational.h)
add_executable(rational_test ${SRC_LIST})

target_link_libraries(rational_test rational)

add_custom_target(new_target
    ${CMAKE_COMMAND} -E copy in_test.txt ../../bin/in_test.txt
  )