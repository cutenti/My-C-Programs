cmake_minimum_required(VERSION 3.25)
project(programsC C)

add_compile_options(-Wall -Wextra -pedantic)

enable_language(ASM)

add_subdirectory(src)