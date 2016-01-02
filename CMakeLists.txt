cmake_minimum_required(VERSION 3.3)
project(Planning_hugger)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Task.cpp Task.h Planning.cpp Planning.h)
add_executable(Planning_hugger ${SOURCE_FILES})