//
// Created by ben on 9/12/22.
//

#ifndef IRESS_COMMAND_H
#define IRESS_COMMAND_H
#include <memory>
#include "Table.h"
#include "Direction.h"
#include "Position.h"

namespace IressRobot {
//    class Table;
//    struct Position;
//    enum class Direction;

//        struct Orientation{
//            Position position;
//            Direction direction;
//        };

    class Command {
    public:
        Command() = default;

        virtual ~Command() =default;

        virtual bool Execute( Position &position,
                              Direction &direction,
                              const std::shared_ptr<Table> &table) = 0;
    };
}

#endif //IRESS_COMMAND_H
