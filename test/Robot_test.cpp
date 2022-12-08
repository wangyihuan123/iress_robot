//
// Created by ben on 8/12/22.
//
#include <gtest/gtest.h>
#include "../include/Table.h"
#include "../include/Robot.h"

using namespace IressRobot;

TEST(Robot_Test, valid_constructions) {
    std::shared_ptr<Table> table(new Table());
    Robot test_rob(table);

    ASSERT_EQ(-1, test_rob.get_position().x);
    ASSERT_EQ(-1, test_rob.get_position().y);
    ASSERT_EQ(Direction::UNKNOWN, test_rob.get_direction());
    EXPECT_FALSE(test_rob.is_active());

    // todo: test other constructors

}


TEST(Robot_Test, valid_places) {
    std::shared_ptr<Table> table(new Table());
    Robot test_rob(table);
    ASSERT_EQ(-1, test_rob.get_position().x);
    ASSERT_EQ(-1, test_rob.get_position().y);
    ASSERT_EQ(Direction::UNKNOWN, test_rob.get_direction());
    EXPECT_FALSE(test_rob.is_active());

    EXPECT_TRUE(test_rob.place(Position{1, 2}, Direction::EAST));
    EXPECT_TRUE(test_rob.is_active());
    ASSERT_EQ(1, test_rob.get_position().x);
    ASSERT_EQ(2, test_rob.get_position().y);

}

TEST(robot_test, place_invalid_directions) {
    std::shared_ptr<Table> test_table(new Table());
    Robot test_rob(test_table);

    EXPECT_FALSE(test_rob.place(Position{2, 2}, static_cast<Direction>(-1)));
    EXPECT_FALSE(test_rob.is_active());
}

TEST(robot_test, place_invalid_locations) {
    {
        std::shared_ptr<Table> test_table(new Table());
        Robot test_rob(test_table);

        EXPECT_FALSE(test_rob.place(Position{5, 5}, Direction::NORTH));
        EXPECT_FALSE(test_rob.is_active());
    }

    {
        std::shared_ptr<Table> test_table(new Table(3, 3));
        Robot test_rob(test_table);

        EXPECT_FALSE(test_rob.place(Position{3, 3}, Direction::NORTH));
        EXPECT_FALSE(test_rob.is_active());
        EXPECT_FALSE(test_rob.move());
    }
}


TEST(RobotTest, move_all_valid_directions) {
    std::shared_ptr<Table> test_table(new Table());
    Robot test_rob(test_table);

    {
        EXPECT_TRUE(test_rob.place(Position{2, 2}, Direction::NORTH));
        EXPECT_TRUE(test_rob.is_active());
        EXPECT_TRUE(test_rob.move());
        EXPECT_EQ(2, test_rob.get_position().x);
        EXPECT_EQ(3, test_rob.get_position().y);
        EXPECT_EQ(Direction::NORTH, test_rob.get_direction());

    }

    {
        EXPECT_TRUE(test_rob.place(Position{2, 2}, Direction::EAST));
        EXPECT_TRUE(test_rob.is_active());
        EXPECT_TRUE(test_rob.move());
        EXPECT_EQ(3, test_rob.get_position().x);
        EXPECT_EQ(2, test_rob.get_position().y);
        EXPECT_EQ(Direction::EAST, test_rob.get_direction());
    }

    {
        EXPECT_TRUE(test_rob.place(Position{2, 2}, Direction::SOUTH));
        EXPECT_TRUE(test_rob.is_active());
        EXPECT_TRUE(test_rob.move());
        EXPECT_EQ(2, test_rob.get_position().x);
        EXPECT_EQ(1, test_rob.get_position().y);
        EXPECT_EQ(Direction::SOUTH, test_rob.get_direction());
    }

    {
        EXPECT_TRUE(test_rob.place(Position{2, 2}, Direction::WEST));
        EXPECT_TRUE(test_rob.is_active());

        EXPECT_TRUE(test_rob.move());
        EXPECT_EQ(1, test_rob.get_position().x);
        EXPECT_EQ(2, test_rob.get_position().y);
        EXPECT_EQ(Direction::WEST, test_rob.get_direction());
    }
}


TEST(RobotTest, move_invalid_locations) {
    std::shared_ptr<Table> test_table(new Table());
    Robot test_rob(test_table);

    {
        EXPECT_TRUE(test_rob.place(Position{0, 4}, Direction::NORTH));
        EXPECT_TRUE(test_rob.is_active());
        EXPECT_FALSE(test_rob.move());
        EXPECT_EQ(0, test_rob.get_position().x);
        EXPECT_EQ(4, test_rob.get_position().y);
        EXPECT_EQ(Direction::NORTH, test_rob.get_direction());

    }

    {
        EXPECT_TRUE(test_rob.place(Position{4, 0}, Direction::EAST));
        EXPECT_TRUE(test_rob.is_active());
        EXPECT_FALSE(test_rob.move());
        EXPECT_EQ(4, test_rob.get_position().x);
        EXPECT_EQ(0, test_rob.get_position().y);
        EXPECT_EQ(Direction::EAST, test_rob.get_direction());

    }

    {
        EXPECT_TRUE(test_rob.place(Position{2, 0}, Direction::SOUTH));
        EXPECT_TRUE(test_rob.is_active());
        EXPECT_FALSE(test_rob.move());
        EXPECT_EQ(2, test_rob.get_position().x);
        EXPECT_EQ(0, test_rob.get_position().y);
        EXPECT_EQ(Direction::SOUTH, test_rob.get_direction());

    }

    {
        EXPECT_TRUE(test_rob.place(Position{0, 2}, Direction::WEST));
        EXPECT_TRUE(test_rob.is_active());
        EXPECT_FALSE(test_rob.move());
        EXPECT_EQ(0, test_rob.get_position().x);
        EXPECT_EQ(2, test_rob.get_position().y);
        EXPECT_EQ(Direction::WEST, test_rob.get_direction());
    }
}


TEST(RobotTest, turn_left) {
    std::shared_ptr<Table> test_table(new Table());
    Robot test_rob(test_table);

    {
        // not placed yet
        EXPECT_FALSE(test_rob.is_active());
        EXPECT_FALSE(test_rob.left());
        EXPECT_EQ(-1, test_rob.get_position().x);
        EXPECT_EQ(-1, test_rob.get_position().y);
        EXPECT_EQ(Direction::UNKNOWN, test_rob.get_direction());
    }

    {
        EXPECT_TRUE(test_rob.place(Position{2, 2}, Direction::NORTH));
        EXPECT_TRUE(test_rob.is_active());
        EXPECT_TRUE(test_rob.left());
        EXPECT_EQ(2, test_rob.get_position().x);
        EXPECT_EQ(2, test_rob.get_position().y);
        EXPECT_EQ(Direction::WEST, test_rob.get_direction());

    }
}



TEST(RobotTest, turn_right) {
    std::shared_ptr<Table> test_table(new Table());
    Robot test_rob(test_table);

    {
        // not placed yet
        EXPECT_FALSE(test_rob.is_active());
        EXPECT_FALSE(test_rob.right());
        EXPECT_EQ(-1, test_rob.get_position().x);
        EXPECT_EQ(-1, test_rob.get_position().y);
        EXPECT_EQ(Direction::UNKNOWN, test_rob.get_direction());
    }

    {
        EXPECT_TRUE(test_rob.place(Position{2, 2}, Direction::NORTH));
        EXPECT_TRUE(test_rob.is_active());
        EXPECT_TRUE(test_rob.right());
        EXPECT_EQ(2, test_rob.get_position().x);
        EXPECT_EQ(2, test_rob.get_position().y);
        EXPECT_EQ(Direction::EAST, test_rob.get_direction());

    }
}