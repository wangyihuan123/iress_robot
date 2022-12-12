//
// Created by ben on 13/12/22.
//

#ifndef IRESS_RIGHT_COMMAND_H
#define IRESS_RIGHT_COMMAND_H

#include "Command.h"
#include "Position.h"
#include "Direction.h"
#include "Table.h"

namespace IressRobot {
//    class Table;

    class Right_Command : public Command {
    public:
        Right_Command() = default;

        virtual ~Right_Command() {};

        virtual bool execute(Position &position,
                             Direction &direction,
                             const std::shared_ptr<Table> &table);

    };
}


#endif //IRESS_RIGHT_COMMAND_H
