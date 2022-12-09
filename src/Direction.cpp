//
// Created by ben on 6/12/22.
//

#include "Direction.h"

using namespace IressRobot;
//const std::vector<std::string> Direction::m_allDirection = {"NORTH", "EAST", "SOUTH", "WEST"};

bool IressRobot::is_valid_direction(Direction direction) {
    return direction >= Direction::MinDirection && direction <= Direction::MaxDirection;
}

 std::string IressRobot::direction_to_string(Direction &direction) {
    switch (direction) {
        case Direction::NORTH :
            return "NORTH";
        case Direction::EAST :
            return "EAST";
        case Direction::SOUTH :
            return "SOUTH";
        case Direction::WEST :
            return "WEST";
        case Direction::UNKNOWN :
        default:
            return "UNKNOWN";
    }
}

Direction IressRobot::string_to_direction(const std::string &str) {
    if (str == "NORTH")
        return Direction::NORTH;
    else if (str == "EAST")
        return Direction::EAST;
    else if (str == "SOUTH")
        return Direction::SOUTH;
    else if (str == "WEST")
        return Direction::WEST;
    else
        return Direction::UNKNOWN;

}