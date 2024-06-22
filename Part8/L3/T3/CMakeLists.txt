cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)

project(Task1)

add_executable(Task1 main.cpp)

add_subdirectory(LogCommand)

target_include_directories(Task1 PUBLIC "{PROJECT_SOURCE_DIR}/LogCommand")

target_link_libraries(Task1 LogCommand Observer Logger LogMessage)