# cmake_minimum_required(VERSION <specify CMake version here>)
project(code C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(code
        book_management.c
        main.c
        Login.c
        Register.c
        Librarian.c
        user.c
        )
