cmake_minimum_required(VERSION 3.28)

set(PostgreSQL_ADDITIONAL_VERSIONS "16")

add_subdirectory("D:/cpp_libs/wt" wt)

project(Task1)

add_executable(Task1 main.cpp)