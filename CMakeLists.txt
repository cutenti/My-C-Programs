cmake_minimum_required(VERSION 3.25)
project(programsC C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -pedantic)

enable_language(ASM)

add_subdirectory(src)