add_library(CyclicList STATIC cyclicList.c)
target_include_directories(CyclicList PUBLIC .)

add_executable(6_counting main.c)
target_link_libraries(6_counting PRIVATE CyclicList)