# cmake_minimum_required(VERSION <specify CMake version here>)
project(code C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(code
        book_management.h
        main.c
        Login.c
        Login.h
        Register.c
        Register.h)
