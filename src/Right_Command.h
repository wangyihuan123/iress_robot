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

        virtual ~Right_Command() {};

        virtual bool execute([[maybe_unused]]Position &position,
                             Direction &direction,
                             [[maybe_unused]]const std::shared_ptr<Table> &table);

    };
}


#endif //IRESS_RIGHT_COMMAND_H
