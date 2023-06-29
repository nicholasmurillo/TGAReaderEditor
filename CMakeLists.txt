cmake_minimum_required(VERSION 3.25)
project(Project2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project2 main.cpp "cmake-build-debug/ImageProcessing Summer 2023/src/Picture.h" "cmake-build-debug/ImageProcessing Summer 2023/src/Pixel.h")
