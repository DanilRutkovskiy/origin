cmake_minimum_required(VERSION 3.28)

set(PostgreSQL_ADDITIONAL_VERSIONS "16")

project(Task1)

add_subdirectory(ClientManager)

add_executable(Task1 main.cpp)

target_include_directories(Task1 PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/ClientManager")

target_compile_features(Task1 PRIVATE cxx_std_20)

target_link_libraries(Task1 ClientManagerLib)