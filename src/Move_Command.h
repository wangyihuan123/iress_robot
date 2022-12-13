//
// Created by ben on 12/12/22.
//

#ifndef IRESS_MOVE_COMMAND_H
#define IRESS_MOVE_COMMAND_H

#include "Command.h"

namespace IressRobot {
    class Table;
    class Position;
    class Direction;

    class Move_Command : public Command {
    public:
        Move_Command() = default;

        ~Move_Command() override =default;

        bool execute(Position &position,
                             Direction &direction,
                             const std::shared_ptr<Table> &table) override;

    };
}

#endif //IRESS_MOVE_COMMAND_H
