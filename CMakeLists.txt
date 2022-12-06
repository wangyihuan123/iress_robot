cmake_minimum_required(VERSION 3.23)
project(iress)

set(CMAKE_CXX_STANDARD 20)

include(GoogleTest)
enable_testing()
add_subdirectory(test)

add_executable(${PROJECT_NAME} main.cpp)
