cmake_minimum_required(VERSION 3.23)
project(iress_test)

add_executable(${PROJECT_NAME}
        Table_test.cpp
        Robot_test.cpp
        Parser_test.cpp
        Place_command_test.cpp
        Report_command_test.cpp
        Move_command_test.cpp
        Left_command_test.cpp
        Right_command_test.cpp
        )

target_link_libraries(${PROJECT_NAME}
        librobot
#        gmock
        gtest
        gtest_main
        pthread)
