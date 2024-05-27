cmake_minimum_required(VERSION 3.28)

project(CW7)

add_subdirectory(Libs)

add_executable(CW7 main.cpp)

target_include_directories(CW7 PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/Libs")

target_link_libraries(CW7 SafeQueueLib ThreadPoolLib)