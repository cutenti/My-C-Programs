add_library(Stack STATIC Stack.c)

target_include_directories(Stack PUBLIC .)

add_executable(5_bracket advancedBracketBalance.c)
add_executable(5_station theSortingStation.c)

target_link_libraries(5_bracket PRIVATE Stack)
target_link_libraries(5_station PRIVATE Stack)