cmake_minimum_required(VERSION 3.23)
project(iress)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include(GoogleTest)
include(CTest)
enable_testing()
add_subdirectory(unit_test)

add_library(librobot STATIC
        src/Table.cpp
        src/Parser_Singleton.cpp
        src/Direction.cpp
        src/Robot.cpp
        src/Place_Command.cpp
        src/Report_Command.cpp
        src/Position.cpp
        src/Move_Command.cpp
        src/Left_Command.cpp
        src/Right_Command.cpp
        )

include_directories(${PROJECT_SOURCE_DIR}/src)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
        librobot
        pthread)
