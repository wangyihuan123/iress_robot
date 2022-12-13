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

        ~Left_Command() override = default;

        bool execute([[maybe_unused]]Position &position,
                             Direction &direction,
                             [[maybe_unused]]const std::shared_ptr<Table> &table) override;

    };
}


#endif //IRESS_LEFT_COMMAND_H
