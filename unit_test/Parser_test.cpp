//
// Created by ben on 7/12/22.
//
#include <gtest/gtest.h>

#include <functional>
#include "../src/Parser_Singleton.h"
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
    shared_ptr<Parser_Singleton> parser  = Parser_Singleton::get_instance();
};


//  todo: Parser_Singleton would be a singleton instance later, so no need for constructor test
TEST_F(Parser_test, invalid_place_command) {

    EXPECT_EQ(nullptr, parser->parse("invalid command"));
    EXPECT_EQ(nullptr, parser->parse("PLACE"));
    EXPECT_EQ(nullptr, parser->parse("PLACE x,y,f"));
    EXPECT_EQ(nullptr, parser->parse("PLACE -1,-1,NORTH"));
    EXPECT_EQ(nullptr, parser->parse("PLACE .1,.2,NORTH"));
    EXPECT_EQ(nullptr, parser->parse("PLACE 1,2,NORTHH"));
    EXPECT_EQ(nullptr, parser->parse("PLACE 1,2,3,NORTH"));
    EXPECT_EQ(nullptr, parser->parse("PLACE 1,2,NORTH,WEST"));
    EXPECT_EQ(nullptr, parser->parse("PLACE 1,NORTH"));
    EXPECT_EQ(nullptr, parser->parse("PLACE 1,2"));
}

TEST_F(Parser_test, valid_place_command) {
    auto p = Position(1, 2);
    auto d = Direction(DirectionEnum::NORTH);
    auto answer_cmd = Place_Command(p, d );
    shared_ptr<Command> cmd = parser->parse("PLACE 1,2,NORTH");

    Place_Command * result_cmd = dynamic_cast<Place_Command *>(cmd.get());
    EXPECT_NE(result_cmd, nullptr);
    if (result_cmd) {
        EXPECT_EQ(result_cmd->get_direction(), d);
        EXPECT_EQ(result_cmd->get_position(),  p);
    }

    EXPECT_EQ( result_cmd->get_direction(), answer_cmd.get_direction());
}

