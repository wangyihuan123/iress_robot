//
// Created by ben on 8/12/22.
//
#include <gtest/gtest.h>
#include "../src/Table.h"
#include "../src/Robot.h"

using namespace IressRobot;

TEST(Robot_Test, valid_constructions) {
    std::shared_ptr<Table> table(new Table());
    Robot test_rob(table);

    ASSERT_EQ(-1, test_rob.get_position().x());
    ASSERT_EQ(-1, test_rob.get_position().y());
    ASSERT_EQ(DirectionEnum::UNKNOWN, test_rob.get_direction().get());
    EXPECT_FALSE(test_rob.is_active());

    // todo: test other constructors

}

