//
// Created by ben on 13/12/22.
//

#include "Left_Command.h"

using namespace IressRobot;

bool Left_Command::execute([[maybe_unused]]Position &position,
                           Direction &direction,
                           [[maybe_unused]]const std::shared_ptr<Table> &table) {

    // can also use int_direction = (int_direction + 3) % 4;
    // but switch is more readable and easier
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

