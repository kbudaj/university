cmake_minimum_required(VERSION 3.5)
project(zad6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp wyrazenie.h liczba.h wyrazenie.cpp liczba.cpp operator0arg.h operator0arg.cpp pi.h pi.cpp e.h e.cpp gamma.h gamma.cpp operator1arg.h operator1arg.cpp przeciwna.h bezwzgledna.h przeciwna.cpp bezwzgledna.cpp odwrotna.cpp odwrotna.h sin.h sin.cpp exp.h exp.cpp cos.h cos.cpp ln.cpp ln.h operator2arg.h operator2arg.cpp dodaj.h dodaj.cpp log.h log.cpp odejmij.h odejmij.cpp modulo.h modulo.cpp mnoz.cpp mnoz.h potega.h potega.cpp dziel.h dziel.cpp zmienna.cpp zmienna.h)
add_executable(zad6 ${SOURCE_FILES})