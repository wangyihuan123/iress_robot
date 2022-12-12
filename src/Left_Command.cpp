//
// Created by ben on 13/12/22.
//

#include "Left_Command.h"
#include "Table.h"

using namespace IressRobot;

bool Left_Command::execute(Position &position,
                           Direction &direction,
                           const std::shared_ptr<Table> &table) {
    switch (direction.get()) {
        case DirectionEnum::NORTH:
            direction.set(DirectionEnum::WEST);
            break;
        case DirectionEnum::EAST:
            direction.set(DirectionEnum::NORTH);
            break;
        case DirectionEnum::SOUTH:
            direction.set(DirectionEnum::EAST);
            break;
        case DirectionEnum::WEST:
            direction.set(DirectionEnum::SOUTH);
            break;
        case DirectionEnum::UNKNOWN:
        default:
            return false;
    }

    return true;
}

