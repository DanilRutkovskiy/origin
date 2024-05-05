cmake_minimum_required(VERSION 3.28)

set(PostgreSQL_ADDITIONAL_VERSIONS "16")

project(Task1)

SET (WT_CONNECTOR "wtfcgi" CACHE STRING "Connector used wtfcgi")

add_executable(Task1 main.cpp)

target_link_directories(${PROJECT_NAME} PUBLIC /external/wt/lib)
target_include_directories(${PROJECT_NAME} PUBLIC external/wt/include)

#target_link_libraries(${PROJECT_NAME} wt)