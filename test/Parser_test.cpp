//
// Created by ben on 7/12/22.
//
#include <gtest/gtest.h>
#include <functional>
#include "../src/Parser.h"
#include "../src/Table.h"
#include "../src/NewRobot.h"

using namespace IressRobot;
using namespace std;


//  todo: Parser would be a singleton instance, so no need for constructor test
TEST(parser_test, invalid_command) {
    // generate a global robot for parser testing
    std::shared_ptr<Table> table(new Table());
//    Robot robot (table);
    auto robot = Robot(table);

//function pointer for parser
//    std::function< void( std::shared_ptr< Command >& ) > command_function(
//            std::bind( &Robot::execute_command, robot, std::placeholders::_1, std::placeholders::_2 ) );


//    auto command_function = [&](shared_ptr< Command >& command )mutable {
//        robot.execute_command(command);
//    };
    CommandFunctor command_function = [&robot](shared_ptr< Command >& command )mutable {
        robot.execute_command(command);
    };
    Parser parser = Parser( command_function );

//    EXPECT_FALSE(parser.ParseInput("invalid command"));
//    EXPECT_FALSE(parser.ParseInput("PLACE"));
//    EXPECT_FALSE(parser.ParseInput("PLACE x,y,f"));
//    EXPECT_FALSE(parser.ParseInput("PLACE -1,-1,NORTH"));
//    EXPECT_FALSE(parser.ParseInput("PLACE .1,.2,NORTH"));
    EXPECT_FALSE(parser.ParseInput("PLACE 1,2,NORTHH"));
}
