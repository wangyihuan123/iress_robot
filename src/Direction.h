//
// Created by ben on 6/12/22.
//

#ifndef IRESS_DIRECTION_H
#define IRESS_DIRECTION_H


#include <string>
#include <vector>


namespace IressRobot {
    enum class DirectionEnum {
        NORTH = 0,
        EAST,
        SOUTH,
        WEST = 3,
        MinDirection = NORTH,
        MaxDirection = WEST,
        UNKNOWN = 4
    };


    class Direction {

    public:

        Direction();
        explicit Direction(const DirectionEnum direction);
        ~Direction() =default;

        bool operator==(const Direction& direction) const;

        [[nodiscard]] DirectionEnum get() const;
        void set(const DirectionEnum direction);

        [[nodiscard]] std::string to_string() const;
        [[nodiscard]] bool is_valid() const;

    private:
        DirectionEnum m_direction;
    };


    std::string direction_to_string(Direction &direction);  // todo: delete later
    DirectionEnum string_to_direction(const std::string &str);
    bool is_valid_direction(Direction direction);
}



#endif //IRESS_DIRECTION_H
