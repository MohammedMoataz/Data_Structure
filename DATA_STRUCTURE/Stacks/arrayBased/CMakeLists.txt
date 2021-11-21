cmake_minimum_required(VERSION 3.20)
project(arrayBased C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(arrayBased
        Array_Based.c
        arrb.h
        main.c)
