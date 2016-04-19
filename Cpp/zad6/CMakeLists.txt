cmake_minimum_required(VERSION 3.5)
project(zad6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp wyrazenie.h liczba.h wyrazenie.cpp liczba.cpp operator0arg.h operator0arg.cpp)
add_executable(zad6 ${SOURCE_FILES})