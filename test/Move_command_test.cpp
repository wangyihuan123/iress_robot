//
// Created by ben on 12/12/22.
//


#include <gtest/gtest.h>
#include "../src/Place_Command.h"
#include "../src/Move_Command.h"
#include "../src/Robot.h"

using namespace IressRobot;
using namespace std;

class Move_Command_Test : public testing::Test {
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


// move fail, pos and dir should be no change
TEST_F(Move_Command_Test, fail_execute) {
    Position pos(4, 4);
    Direction dir(IressRobot::DirectionEnum::NORTH);
    // place
    shared_ptr<Command> cmd = make_shared<Place_Command>( pos, dir);
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), pos);
    EXPECT_EQ(m_robot.get_direction(), dir);
    // move
    cmd  = make_shared<Move_Command>() ;
    EXPECT_FALSE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), pos);
    EXPECT_EQ(m_robot.get_direction(), dir);

    //-----------------
    dir.set(IressRobot::DirectionEnum::EAST);
    // place
    cmd = make_shared<Place_Command>( pos, dir);
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), pos);
    EXPECT_EQ(m_robot.get_direction(), dir);
    // move
    cmd  = make_shared<Move_Command>() ;
    EXPECT_FALSE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), pos);
    EXPECT_EQ(m_robot.get_direction(), dir);


    //-----------------
    pos.set(0, 0);
    dir.set(IressRobot::DirectionEnum::SOUTH);
    // place
    cmd = make_shared<Place_Command>( pos, dir);
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), pos);
    EXPECT_EQ(m_robot.get_direction(), dir);
    // move
    cmd  = make_shared<Move_Command>() ;
    EXPECT_FALSE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), pos);
    EXPECT_EQ(m_robot.get_direction(), dir);

    //-----------------
    dir.set(IressRobot::DirectionEnum::WEST);
    // place
    cmd = make_shared<Place_Command>( pos, dir);
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), pos);
    EXPECT_EQ(m_robot.get_direction(), dir);
    // move
    cmd  = make_shared<Move_Command>() ;
    EXPECT_FALSE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), pos);
    EXPECT_EQ(m_robot.get_direction(), dir);
}

TEST_F(Move_Command_Test, success_execute) {
    Position pos(2, 2);
    Direction dir(IressRobot::DirectionEnum::NORTH);
    // place
    shared_ptr<Command> cmd = make_shared<Place_Command>( pos, dir);
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), pos);
    EXPECT_EQ(m_robot.get_direction(), dir);
    // move
    cmd  = make_shared<Move_Command>() ;
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), Position(2,3));
    EXPECT_EQ(m_robot.get_direction(), dir);

    //-----------------
    pos.set(2, 2);
    dir.set(IressRobot::DirectionEnum::EAST);
    // place
    cmd = make_shared<Place_Command>( pos, dir);
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), pos);
    EXPECT_EQ(m_robot.get_direction(), dir);
    // move
    cmd  = make_shared<Move_Command>() ;
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), Position(3,2));
    EXPECT_EQ(m_robot.get_direction(), dir);

    //-----------------
    pos.set(2, 2);
    dir.set(IressRobot::DirectionEnum::SOUTH);
    // place
    cmd = make_shared<Place_Command>( pos, dir);
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), pos);
    EXPECT_EQ(m_robot.get_direction(), dir);
    // move
    cmd  = make_shared<Move_Command>() ;
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), Position(2, 1));
    EXPECT_EQ(m_robot.get_direction(), dir);

    //-----------------
    pos.set(2, 2);
    dir.set(IressRobot::DirectionEnum::WEST);
    // place
    cmd = make_shared<Place_Command>( pos, dir);
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), pos);
    EXPECT_EQ(m_robot.get_direction(), dir);
    // move
    cmd  = make_shared<Move_Command>() ;
    EXPECT_TRUE(m_robot.execute_command(cmd));
    EXPECT_EQ(m_robot.get_position(), Position(1,2));
    EXPECT_EQ(m_robot.get_direction(), dir);
}