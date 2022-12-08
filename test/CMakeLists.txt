cmake_minimum_required(VERSION 3.23)
project(iress_test)

add_executable(${PROJECT_NAME}
        Table_test.cpp
        Robot_test.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include/Table.h
        ${PROJECT_SOURCE_DIR}/include/Position.h
        ${PROJECT_SOURCE_DIR}/include/Direction.h
        ${PROJECT_SOURCE_DIR}/include/Robot.h
)
target_link_libraries(${PROJECT_NAME}
        robot
        gtest
        gtest_main
        pthread)


#gtest_discover_tests(${PROJECT_NAME})