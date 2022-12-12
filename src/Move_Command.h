//
// Created by ben on 12/12/22.
//

#ifndef IRESS_MOVE_COMMAND_H
#define IRESS_MOVE_COMMAND_H

#include "Command.h"
#include "Position.h"
#include "Direction.h"
#include "Table.h"

namespace IressRobot {
//    class Table;

    class Move_Command : public Command {
    public:
        Move_Command() = default;

        virtual ~Move_Command() {};

        virtual bool execute( Position &position,
                              Direction &direction,
                              const std::shared_ptr<Table> &table);

    };
}

#endif //IRESS_MOVE_COMMAND_H
