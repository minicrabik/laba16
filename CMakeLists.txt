cmake_minimum_required(VERSION 3.26)
project(laba16 C)

set(CMAKE_C_STANDARD 11)

add_executable(laba16 main.c
        libs/algorithms/algorithms.h
        libs/algorithms/algorithms.c
        libs/data_structures/matrix/matrix.c
        libs/data_structures/matrix/matrix.h
        libs/algorithms/algorithms.c)
