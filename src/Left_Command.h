//
// Created by ben on 13/12/22.
//

#ifndef IRESS_LEFT_COMMAND_H
#define IRESS_LEFT_COMMAND_H


#include "Command.h"
#include "Position.h"
#include "Direction.h"
#include "Table.h"

namespace IressRobot {
//    class Table;

    class Left_Command : public Command {
    public:
        Left_Command() = default;

        virtual ~Left_Command() {};

        virtual bool execute(Position &position,
                             Direction &direction,
                             const std::shared_ptr<Table> &table);

    };
}


#endif //IRESS_LEFT_COMMAND_H
