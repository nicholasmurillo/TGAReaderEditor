cmake_minimum_required(VERSION 3.25)
project(Project2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project2 src/main.cpp "src/Picture.h" "src/Pixel.h")
