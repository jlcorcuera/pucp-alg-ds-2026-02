cmake_minimum_required(VERSION 4.2)
project(20201987_EX2_P1)

set(CMAKE_CXX_STANDARD 20)

add_executable(20201987_EX2_P1 main.cpp
        BibliotecaCola/Cola.h
        BibliotecaCola/ElementoCola.h
        BibliotecaCola/funcionesCola.cpp
        BibliotecaCola/funcionesCola.h
        BibliotecaCola/NodoCola.h)
