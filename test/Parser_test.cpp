//
// Created by ben on 7/12/22.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>


#include <functional>
#include "../src/Parser.h"
#include "../src/Table.h"
#include "../src/Robot.h"
#include "../src/Position.h"
#include "../src/Direction.h"
#include "../src/Place_Command.h"
#include "../src/Report_Command.h"

using namespace IressRobot;
using namespace std;



class Parser_test : public testing::Test {
protected:
    void SetUp() override {
    // todo:
    }

    // virtual void TearDown() {
    // }
    Parser parser = Parser(  );
};


//  todo: Parser would be a singleton instance later, so no need for constructor test
TEST_F(Parser_test, invalid_place_command) {

    EXPECT_EQ(nullptr, parser.ParseInput("invalid command"));
    EXPECT_EQ(nullptr, parser.ParseInput("PLACE"));
    EXPECT_EQ(nullptr, parser.ParseInput("PLACE x,y,f"));
    EXPECT_EQ(nullptr, parser.ParseInput("PLACE -1,-1,NORTH"));
    EXPECT_EQ(nullptr, parser.ParseInput("PLACE .1,.2,NORTH"));
    EXPECT_EQ(nullptr, parser.ParseInput("PLACE 1,2,NORTHH"));
}



TEST_F(Parser_test, valid_place_command) {
//    auto x = 1;
//    auto y = 2;
    auto p = Position(1, 2);
    auto d = Direction::NORTH;
    auto answer_cmd = Place_Command(p, d );
    shared_ptr<Command> cmd = parser.ParseInput("PLACE 1,2,NORTH");

    Place_Command * result_cmd = dynamic_cast<Place_Command *>(cmd.get());
    EXPECT_NE(result_cmd, nullptr);
    if (result_cmd) {
        EXPECT_EQ(result_cmd->get_direction(), Direction::NORTH);
        EXPECT_EQ(result_cmd->get_position(),  p);
    }

    EXPECT_EQ( result_cmd->get_direction(), answer_cmd.get_direction());
}


//TEST(parser_test, valid_place_command) {
//    Parser parser = Parser(  );
//
//    auto cmd = Place_Command(Position{1,2}, Direction::NORTH);
//    EXPECT_THAT(cmd , parser.ParseInput("PLACE 1,2,NORTHH"));
//}
