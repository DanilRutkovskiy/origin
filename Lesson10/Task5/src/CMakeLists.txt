cmake_minimum_required(VERSION 3.22.0)
project(ShapesClient)
add_library(ShapesDynLib SHARED Shape.hpp Shape.cpp Triangle.hpp Triangle.cpp Tetragon.hpp Tetragon.cpp Square.hpp Square.cpp RightTriangle.hpp RightTriangle.cpp Rhombus.hpp Rhombus.cpp Rectangle.hpp Rectangle.cpp Parallelogram.hpp Parallelogram.cpp EquilateralTriangle.hpp EquilateralTriangle.cpp)
add_executable(ShapesClientExe main.cpp)
target_link_libraries(ShapesClientExe ShapesDynLib)