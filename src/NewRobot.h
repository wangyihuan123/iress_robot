//
// Created by ben on 9/12/22.
//


#ifndef IRESS_ROBOT_H
#define IRESS_ROBOT_H

#include <string>
#include <functional>
#include <memory>
#include "Direction.h"
#include "Position.h"
#include "Table.h"
#include "Command.h"

// todo: check all the declaration later
//class Position;
//class Direction;

using namespace  std;

namespace IressRobot {

    typedef std::function< void( std::shared_ptr< Command >& ) > CommandFunctor;
    class Robot {

    private:
        Position m_position {-1, -1};
        Direction m_direction{Direction::UNKNOWN};
//        bool m_active_flag {false};  // can be detected by checking position and direction;
        shared_ptr<Table> m_table{nullptr};

        CommandFunctor m_commandFunctor;
    public:
        Robot() = delete; // todo: later register this robot to a table
        explicit Robot(shared_ptr<Table> table);
        Robot(Robot & robot) = delete;  // todo:
        Robot(Robot && robot) = delete;  // todo:
        ~Robot() = default;

        [[nodiscard]] bool is_active() const;
        Position get_position() const;
        Direction get_direction() const;

        void get_command_functor();  // todo:

        void execute_command( shared_ptr< Command >& command );

        // move all the actions to seperated command classes
        // then all the actions will run by execute_command()
//        bool place(const Position& position, const Direction& direction);
//        bool move();
//        bool right();
//        bool left();
//        void report() ;
    };

}

#endif //IRESS_ROBOT_H
