add_library(LinkSortList STATIC linkedSortedList.c)
target_include_directories(LinkSortList PUBLIC .)

add_executable(6_sorted_list sortedList.c)

target_link_libraries(6_sorted_list PRIVATE LinkSortList)
