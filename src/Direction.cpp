//
// Created by ben on 6/12/22.
//

#include "Direction.h"


//const std::vector<std::string> Direction::m_allDirection = {"NORTH", "EAST", "SOUTH", "WEST"};

bool IressRobot::is_valid_direction(Direction direction)
{
    return direction >= Direction::MinDirection && direction <= Direction::MaxDirection;
}