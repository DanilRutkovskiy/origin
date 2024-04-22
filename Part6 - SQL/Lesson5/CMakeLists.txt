cmake_minimum_required(VERSION 3.20)

set(PostgreSQL_ADDITIONAL_VERSIONS "16")

project(Task1)

add_subdirectory("D:/cpp_libs/libpqxx_7.9.0" libpqxx_build)

add_executable(Task1 main.cpp)

target_compile_features(Task1 PRIVATE cxx_std_20)

target_link_libraries(Task1 pqxx)