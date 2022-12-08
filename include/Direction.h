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
    };

    const std::string directions[] = {"NORTH", "EAST", "SOUTH", "WEST"};

// todo:  class Direction



//    std::string to_string(Direction direction);  // todo:
//    Direction from_string(const std::string &input);  // todo:
    bool is_valid_direction(Direction direction);

enum class Turn{
    LEFT,
    RIGHT
};
}



#endif //IRESS_DIRECTION_H
