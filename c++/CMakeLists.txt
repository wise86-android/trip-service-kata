cmake_minimum_required(VERSION 3.7)
project(tripService)

set(CMAKE_CXX_STANDARD 11)

include_directories(packages)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)