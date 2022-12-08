cmake_minimum_required(VERSION 3.23)
project(iress_test)

add_executable(${PROJECT_NAME}
        Table_test.cpp
        Robot_test.cpp)

target_link_libraries(${PROJECT_NAME}
        robot
        gtest
        gtest_main
        pthread)
