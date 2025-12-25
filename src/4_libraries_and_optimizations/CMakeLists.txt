add_library(sort STATIC sort.s)

target_include_directories(sort PUBLIC .)

add_executable(4_sort main.c)

target_link_libraries(4_sort PRIVATE sort)