//
// Created by ben on 8/12/22.
//
#include <gtest/gtest.h>
#include "../include/Table.h"
#include "../include/Robot.h"

using namespace IressRobot;

TEST(Robot_Test, validConstruction) {
    std::shared_ptr<Table> table(new Table());
    Robot test_rob(table);

    ASSERT_EQ(0, test_rob.get_position().x);
    ASSERT_EQ(0, test_rob.get_position().y);
    ASSERT_EQ(Direction::NORTH, test_rob.get_direction());
    ASSERT_EQ(false, test_rob.is_active());

    // todo: test other constructors

}


TEST(Robot_Test, validPlace) {
    std::shared_ptr<Table> table(new Table());
    Robot test_rob(table);
    ASSERT_EQ(0, test_rob.get_position().x);
    ASSERT_EQ(0, test_rob.get_position().y);
    ASSERT_EQ(Direction::NORTH, test_rob.get_direction());
    ASSERT_EQ(false, test_rob.is_active());

    test_rob.place(Position{1, 2}, Direction::EAST);
    ASSERT_EQ(1, test_rob.get_position().x);
    ASSERT_EQ(2, test_rob.get_position().y);
    ASSERT_EQ(true, test_rob.is_active());

}

TEST(RobotTest, MoveAllDirections)
{
    std::shared_ptr<Table> test_table(new Table());
    Robot test_rob(test_table);
//    EXPECT_CALL(*test_table, is_valid_location(_, _))
//            .Times(4)
//            .WillRepeatedly(Return(true));

    // Using new robots for each test to avoid this test being dependent on place() or left()/right()
    {
        test_rob.place(Position{2, 2}, Direction::NORTH);
        EXPECT_TRUE(test_rob.move());
        EXPECT_EQ(2, test_rob.get_position().x);
        EXPECT_EQ(3, test_rob.get_position().y);
        EXPECT_EQ(Direction::NORTH, test_rob.get_direction());
    }

    {
        test_rob.place(Position{2, 2}, Direction::EAST);
        EXPECT_TRUE(test_rob.move());
        EXPECT_EQ(3, test_rob.get_position().x);
        EXPECT_EQ(2, test_rob.get_position().y);
        EXPECT_EQ(Direction::EAST, test_rob.get_direction());
    }

    {
        test_rob.place(Position{2, 2}, Direction::SOUTH);
        EXPECT_TRUE(test_rob.move());
        EXPECT_EQ(2, test_rob.get_position().x);
        EXPECT_EQ(1, test_rob.get_position().y);
        EXPECT_EQ(Direction::SOUTH, test_rob.get_direction());
    }

    {test_rob.place(Position{2, 2}, Direction::WEST);
        EXPECT_TRUE(test_rob.move());
        EXPECT_EQ(1, test_rob.get_position().x);
        EXPECT_EQ(2, test_rob.get_position().y);
        EXPECT_EQ(Direction::WEST, test_rob.get_direction());
    }
}