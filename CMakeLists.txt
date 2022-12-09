cmake_minimum_required(VERSION 3.23)
project(iress)

set(CMAKE_CXX_STANDARD 20)

include(GoogleTest)
enable_testing()
add_subdirectory(test)

add_library(robot STATIC
        src/Table.cpp
#        src/Robot.cpp
        src/Parser.cpp
        src/Direction.cpp
        src/NewRobot.cpp
        src/Place_Command.cpp)

include_directories(${PROJECT_SOURCE_DIR}/src)
add_executable(${PROJECT_NAME} main.cpp )

#target_link_libraries(MainProject LibProject)