cmake_minimum_required(VERSION 3.20)

project(Task1)

add_executable(Task1 main.cpp)

add_subdirectory(Proxy)

target_include_directories(Task1 PUBLIC "{PROJECT_SOURCE_DIR}/Proxy")

target_link_libraries(Task1 Proxy)