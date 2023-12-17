cmake_minimum_required(VERSION 3.16)
project(my_second_cmake_project VERSION 0.1)
set(SOURCE_EXE main.cpp EquilateralTriangle.cpp Parallelogram.cpp Rectangle.cpp Rhombus.cpp
RightTriangle.cpp Shape.cpp Square.cpp Tetragon.cpp Triangle.cpp)
add_executable(my_second_cmake_program ${SOURCE_EXE})