//
// Created by ben on 12/12/22.
//

#include <gtest/gtest.h>
#include "../src/Place_Command.h"
#include "../src/Right_Command.h"
#include "../src/Robot.h"

using namespace IressRobot;
using namespace std;

class Right_Command_Test : public testing::Test {
protected:
    void SetUp() override {
        shared_ptr<Table> table(new Table());  // default  dim is 5x5
        m_robot.register_table(table);

    }

    // virtual void TearDown() {
    // }
    Robot m_robot;
    shared_ptr<Table> m_table;
};

// left or right turn should be always success
TEST_F(Right_Command_Test, success_execute) {
    Position pos(2, 2);
    Direction dir(IressRobot::DirectionEnum::NORTH);
    // place
    shared_ptr<Command> cmd = make_shared<Place_Command>( pos, dir);
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), pos);
    EXPECT_EQ(m_robot.get_direction(), dir);
    // left
    cmd  = make_shared<Right_Command>() ;
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), Position(2,2));
    EXPECT_EQ(m_robot.get_direction(), Direction(IressRobot::DirectionEnum::EAST));

    //-----------------
    pos.set(2, 2);
    dir.set(IressRobot::DirectionEnum::EAST);
    // place
    cmd = make_shared<Place_Command>( pos, dir);
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), pos);
    EXPECT_EQ(m_robot.get_direction(), dir);
    // move
    cmd  = make_shared<Right_Command>() ;
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), Position(2,2));
    EXPECT_EQ(m_robot.get_direction(), Direction(IressRobot::DirectionEnum::SOUTH));

    //-----------------
    pos.set(2, 2);
    dir.set(IressRobot::DirectionEnum::SOUTH);
    // place
    cmd = make_shared<Place_Command>( pos, dir);
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), pos);
    EXPECT_EQ(m_robot.get_direction(), dir);
    // move
    cmd  = make_shared<Right_Command>() ;
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), Position(2, 2));
    EXPECT_EQ(m_robot.get_direction(), Direction(IressRobot::DirectionEnum::WEST));

    //-----------------
    pos.set(2, 2);
    dir.set(IressRobot::DirectionEnum::WEST);
    // place
    cmd = make_shared<Place_Command>( pos, dir);
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), pos);
    EXPECT_EQ(m_robot.get_direction(), dir);
    // move
    cmd  = make_shared<Right_Command>() ;
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), Position(2,2));
    EXPECT_EQ(m_robot.get_direction(), Direction(IressRobot::DirectionEnum::NORTH));
}
