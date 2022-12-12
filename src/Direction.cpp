//
// Created by ben on 6/12/22.
//

#include "Direction.h"

using namespace IressRobot;

Direction::Direction() : Direction(DirectionEnum::UNKNOWN)
{
}

Direction::Direction(const DirectionEnum direction) :
        m_direction(direction)
{

}

bool Direction::operator==(const Direction &direction) const
{
    return m_direction == direction.get();
}

DirectionEnum Direction::get() const
{
    return m_direction;
}

void Direction::set(const DirectionEnum dir)
{
    m_direction = dir;
}

bool Direction::is_valid() const
{
    return m_direction >= DirectionEnum::MinDirection && m_direction <= DirectionEnum::MaxDirection;
}

std::string Direction::to_string() const {
    switch (m_direction) {
        case DirectionEnum::NORTH :
            return "NORTH";
        case DirectionEnum::EAST :
            return "EAST";
        case DirectionEnum::SOUTH :
            return "SOUTH";
        case DirectionEnum::WEST :
            return "WEST";
        case DirectionEnum::UNKNOWN :
        default:
            return "UNKNOWN";
    }
}

bool is_valid_direction(const Direction& direction)  {
    return direction.get() >= DirectionEnum::MinDirection && direction.get() <= DirectionEnum::MaxDirection;
}

 std::string IressRobot::direction_to_string(Direction &direction) {
    switch (direction.get()) {
        case DirectionEnum::NORTH :
            return "NORTH";
        case DirectionEnum::EAST :
            return "EAST";
        case DirectionEnum::SOUTH :
            return "SOUTH";
        case DirectionEnum::WEST :
            return "WEST";
        case DirectionEnum::UNKNOWN :
        default:
            return "UNKNOWN";
    }
}

DirectionEnum IressRobot::string_to_direction(const std::string &str) {
    if (str == "NORTH")
        return DirectionEnum::NORTH;
    else if (str == "EAST")
        return DirectionEnum::EAST;
    else if (str == "SOUTH")
        return DirectionEnum::SOUTH;
    else if (str == "WEST")
        return DirectionEnum::WEST;
    else
        return DirectionEnum::UNKNOWN;

}