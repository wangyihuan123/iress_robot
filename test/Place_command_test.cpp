//
// Created by ben on 12/12/22.
//

#include <gtest/gtest.h>
#include "../src/Place_Command.h"
#include "../src/Robot.h"

using namespace IressRobot;
using namespace std;

TEST(Place_Command_Test, invalid_constructions) {
    EXPECT_THROW({
                     try {
                         auto place = Place_Command(Position(),
                                                    Direction(IressRobot::DirectionEnum::NORTH));
                     }
                     catch (const std::invalid_argument &e) {
                         EXPECT_EQ(std::string("position"), e.what());
                         throw;
                     }
                 }, std::invalid_argument);

    EXPECT_THROW({
                     try {
                         auto place = Place_Command(Position(-1, 0), Direction());
                     }
                     catch (const std::invalid_argument &e) {
                         EXPECT_EQ(std::string("position"), e.what());
                         throw;
                     }
                 }, std::invalid_argument);

    EXPECT_THROW({
                     try {
                         auto place = Place_Command(Position(0, 0), Direction());
                     }
                     catch (const std::invalid_argument &e) {
                         EXPECT_EQ(std::string("direction"), e.what());
                         throw;
                     }
                 }, std::invalid_argument);

    EXPECT_THROW({
                     try {
                         auto place = Place_Command(Position(0, 0),
                                                    Direction(IressRobot::DirectionEnum::UNKNOWN));
                     }
                     catch (const std::invalid_argument &e) {
                         EXPECT_EQ(std::string("direction"), e.what());
                         throw;
                     }
                 }, std::invalid_argument);

}

TEST(Place_Command_Test, valid_constructions) {

    auto cmd = Place_Command(Position(0, 0), Direction(IressRobot::DirectionEnum::NORTH));
    EXPECT_EQ(cmd.get_position().x(), 0);
    EXPECT_EQ(cmd.get_position().y(), 0);

    cmd = Place_Command(Position(123456789, 987654321),
                        Direction(IressRobot::DirectionEnum::EAST));
    EXPECT_EQ(cmd.get_position().x(), 123456789);
    EXPECT_EQ(cmd.get_position().y(), 987654321);
}


//class Place_Command_Test : public testing::Test {
//protected:
//    void SetUp() override {
//        // todo:
//    }
//
//    // virtual void TearDown() {
//    // }
//
////    Table table;
//};


TEST(Place_Command_Test, fail_execute) {

    auto cmd = Place_Command(Position(0, 0), Direction(IressRobot::DirectionEnum::NORTH));
    EXPECT_EQ(cmd.get_position().x(), 0);
    EXPECT_EQ(cmd.get_position().y(), 0);

    cmd = Place_Command(Position(123456789, 987654321),
                        Direction(IressRobot::DirectionEnum::EAST));
    EXPECT_EQ(cmd.get_position().x(), 123456789);
    EXPECT_EQ(cmd.get_position().y(), 987654321);
}

TEST(Place_Command_Test, success_execute) {

    auto cmd = Place_Command(Position(0, 0),
                             Direction(IressRobot::DirectionEnum::NORTH));

    Position curr_pos(1, 1);
    Direction curr_dir(DirectionEnum::EAST);
    EXPECT_TRUE(cmd.execute(curr_pos, curr_dir, make_shared<Table>()));
    EXPECT_EQ(curr_pos.x(), 0);
    EXPECT_EQ(curr_pos.y(), 0);
    EXPECT_EQ(curr_dir.get(), DirectionEnum::NORTH);

}