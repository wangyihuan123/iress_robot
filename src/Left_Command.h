//
// Created by ben on 13/12/22.
//

#ifndef IRESS_LEFT_COMMAND_H
#define IRESS_LEFT_COMMAND_H


#include "Command.h"

namespace IressRobot {
    class Position;
    class Direction;
    class Table;

    class Left_Command : public Command {
    public:
        Left_Command() = default;

        virtual ~Left_Command() {};

        virtual bool execute([[maybe_unused]]Position &position,
                             Direction &direction,
                             [[maybe_unused]]const std::shared_ptr<Table> &table);

    };
}


#endif //IRESS_LEFT_COMMAND_H
