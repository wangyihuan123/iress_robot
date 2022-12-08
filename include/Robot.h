//
// Created by ben on 6/12/22.
//

#ifndef IRESS_ROBOT_H
#define IRESS_ROBOT_H

#include <unordered_map>
#include <string>
#include <functional>
#include <memory>
#include "Direction.h"
#include "Position.h"
#include "Table.h"
// todo:
//class Position;
//class Direction;

using namespace  std;

namespace IressRobot {

    class Robot {

    private:
        Position m_position {-1, -1};
        Direction m_direction{Direction::UNKNOWN};
        bool m_active_flag {false};
        std::shared_ptr<Table> m_table{nullptr};

    public:
        Robot() = delete; // todo: later
        explicit Robot(std::shared_ptr<Table> table);
        Robot(Robot & robot) = delete;  // todo:
        Robot(Robot && robot) = delete;  // todo:
        ~Robot() = default;

        [[nodiscard]] bool is_active() const;
        bool place(const Position& position, const Direction& direction);
        bool move();
        bool right();
        bool left();
        Position get_position() const;
        Direction get_direction() const;
//        void report() ;
    };

}

#endif //IRESS_ROBOT_H
