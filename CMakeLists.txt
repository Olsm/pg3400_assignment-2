cmake_minimum_required(VERSION 3.6)
project(pg3400_assignment_2)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")

set(SOURCE_FILES main.c functions.c)
add_executable(pg3400_assignment_2 ${SOURCE_FILES})