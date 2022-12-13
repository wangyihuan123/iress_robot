//
// Created by ben on 13/12/22.
//

#ifndef IRESS_RIGHT_COMMAND_H
#define IRESS_RIGHT_COMMAND_H

#include "Command.h"

namespace IressRobot {
    class Table;
    class Position;
    class Direction;

    class Right_Command : public Command {
    public:
        Right_Command() = default;

        ~Right_Command() override = default;

        bool execute([[maybe_unused]]Position &position,
                             Direction &direction,
                             [[maybe_unused]]const std::shared_ptr<Table> &table) override;

    };
}


#endif //IRESS_RIGHT_COMMAND_H
