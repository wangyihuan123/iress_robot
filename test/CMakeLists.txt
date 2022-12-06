cmake_minimum_required(VERSION 3.23)
project(iress_test)

add_executable(${PROJECT_NAME} unit_tests.cpp)
target_include_directories(${PROJECT_NAME}
    PUBLIC 
        robot.h
)
target_link_libraries(${PROJECT_NAME}
        gtest
        gtest_main
        pthread)


#gtest_discover_tests(${PROJECT_NAME})