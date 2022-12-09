//
// Created by ben on 6/12/22.
//

#ifndef IRESS_DIRECTION_H
#define IRESS_DIRECTION_H


#include <string>
#include <vector>


namespace IressRobot {
    enum class Direction {
        NORTH = 0,
        EAST,
        SOUTH,
        WEST = 3,
        MinDirection = NORTH,
        MaxDirection = WEST,
        UNKNOWN = 4
    };


// todo:  class Direction later

    std::string direction_to_string(Direction &direction);
    Direction string_to_direction(const std::string &str);
    bool is_valid_direction(Direction direction);

enum class Turn{
    LEFT,
    RIGHT
};

}



#endif //IRESS_DIRECTION_H
