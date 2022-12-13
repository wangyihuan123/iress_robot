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

using namespace  std;

namespace IressRobot {

    class Robot {

    private:
        Position m_position {-1, -1};
        Direction m_direction{DirectionEnum::UNKNOWN};
        shared_ptr<Table> m_table{nullptr};  // this should not be null after place

    public:
        Robot() = default; // todo: later register this robot to a table
        explicit Robot(shared_ptr<Table> table);
        Robot(Robot & robot) = delete;  // todo:
        Robot(Robot && robot) = delete;  // todo:
        ~Robot() = default;

        bool register_table(shared_ptr<Table>);
        [[nodiscard]] bool is_active() const;  // not very useful at the moment
        [[nodiscard]] Position get_position() const;
        [[nodiscard]] Direction get_direction() const;

        bool execute_command( shared_ptr< Command >& command );

    };

}

#endif //IRESS_ROBOT_H
