#include <gtest/gtest.h>
#include "../robot.h"

TEST(Robot_Test, add_robot)
{
    Robot test_rob;

    ASSERT_EQ(0, test_rob.get_x());
    ASSERT_EQ(0, test_rob.get_y());
    ASSERT_EQ(Direction::NORTH, test_rob.get_direction());
    ASSERT_EQ(false, test_rob.is_active());
}

TEST(Robot_Test, place_robot)
{
    Robot test_rob;
    ASSERT_EQ(0, test_rob.get_x());
    ASSERT_EQ(0, test_rob.get_y());
    ASSERT_EQ(Direction::NORTH, test_rob.get_direction());
    ASSERT_EQ(false, test_rob.is_active());

    test_rob.place(1,2);
    ASSERT_EQ(1, test_rob.get_x());
    ASSERT_EQ(2, test_rob.get_y());
    ASSERT_EQ(true, test_rob.is_active());
}

TEST(Robot_Test, move_north)
{
    Robot test_rob;
    ASSERT_EQ(0, test_rob.get_x());
    ASSERT_EQ(0, test_rob.get_y());
    ASSERT_EQ(Direction::NORTH, test_rob.get_direction());
    ASSERT_EQ(false, test_rob.is_active());

    test_rob.place(1,2);
    ASSERT_EQ(1, test_rob.get_x());
    ASSERT_EQ(2, test_rob.get_y());
    ASSERT_EQ(true, test_rob.is_active());

    test_rob.move();
    ASSERT_EQ(1, test_rob.get_x());
    ASSERT_EQ(3, test_rob.get_y());
    ASSERT_EQ(Direction::NORTH, test_rob.get_direction());
    ASSERT_EQ(true, test_rob.is_active());
}

TEST(Robot_Test, turn_left)
{
    Robot test_rob;
    ASSERT_EQ(0, test_rob.get_x());
    ASSERT_EQ(0, test_rob.get_y());
    ASSERT_EQ(Direction::NORTH, test_rob.get_direction());
    ASSERT_EQ(false, test_rob.is_active());

    test_rob.place(1,2);
    ASSERT_EQ(1, test_rob.get_x());
    ASSERT_EQ(2, test_rob.get_y());
    ASSERT_EQ(true, test_rob.is_active());


    test_rob.left();
    ASSERT_EQ(1, test_rob.get_x());
    ASSERT_EQ(2, test_rob.get_y());
    ASSERT_EQ(Direction::WEST, test_rob.get_direction());
    ASSERT_EQ(true, test_rob.is_active());
}

TEST(Robot_Test, turn_right)
{
    Robot test_rob;
    ASSERT_EQ(0, test_rob.get_x());
    ASSERT_EQ(0, test_rob.get_y());
    ASSERT_EQ(Direction::NORTH, test_rob.get_direction());
    ASSERT_EQ(false, test_rob.is_active());

    test_rob.place(1,2);
    ASSERT_EQ(1, test_rob.get_x());
    ASSERT_EQ(2, test_rob.get_y());
    ASSERT_EQ(true, test_rob.is_active());

    test_rob.right();
    ASSERT_EQ(1, test_rob.get_x());
    ASSERT_EQ(2, test_rob.get_y());
    ASSERT_EQ(Direction::EAST, test_rob.get_direction());
    ASSERT_EQ(true, test_rob.is_active());
}
