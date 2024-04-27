cmake_minimum_required(VERSION 3.28)

add_library(ClientManagerLib ClientManager.hpp ClientManager.cpp)

add_subdirectory("D:/cpp_libs/libpqxx_7.9.0" libpqxx_build)

target_compile_features(ClientManagerLib PRIVATE cxx_std_20)

target_link_libraries(ClientManagerLib pqxx)