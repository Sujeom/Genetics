cmake_minimum_required(VERSION 3.3)
project(Genetics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wno-unused-variable")

set(SOURCE_FILES
    genetics.c)

add_executable(Genetics ${SOURCE_FILES})