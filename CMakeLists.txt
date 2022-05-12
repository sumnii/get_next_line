cmake_minimum_required(VERSION 3.22)
project(get_next_line C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -g")
include_directories(.)

include_directories(.)

add_executable(get_next_line
        get_next_line.c
        get_next_line.h
#        get_next_line_utils.c
        main.c)
