//
// Created by ben on 12/12/22.
//


#include "Move_Command.h"
#include "Table.h"

using namespace IressRobot;

bool Move_Command::execute(Position &position,
                           Direction &direction,
                           const std::shared_ptr<Table> &table) {
    Position p(0, 0);
    switch (direction.get()) {
        case DirectionEnum::NORTH:
            p.set_y(position.y() + 1);
            break;
        case DirectionEnum::EAST:
            p.set_x(position.x() + 1);
            break;
        case DirectionEnum::SOUTH:
            p.set_y(position.y() - 1);
            break;
        case DirectionEnum::WEST:
            p.set_x(position.x() - 1);
            break;
        case DirectionEnum::UNKNOWN:
        default:
            return false;
    }

    if (table->is_valid_location(p.x(), p.y()))
        position = p;

    return true;
}



