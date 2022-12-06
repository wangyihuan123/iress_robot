//
// Created by ben on 6/12/22.
//

#ifndef IRESS_ROBOT_H
#define IRESS_ROBOT_H

#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <memory>
#include <fstream>

using namespace std;

enum class Direction {
    NORTH = 0,
    EAST,
    SOUTH,
    WEST = 3,
    MinDirection = NORTH,
    MaxDirection = WEST,
};

const string directions[] = {"NORTH", "EAST", "SOUTH", "WEST"};

class Robot {
    bool m_active_flag = {false};
    int m_x = {0};
    int m_y = {0};
    Direction m_facing{Direction::NORTH};

public:
    auto get_x() const { return m_x;}
    auto get_y() const { return m_y;}
    auto get_direction() const {return m_facing;}

    void place(int x, int y) {
        if (x > 5 || x < 0)
            return;
        if (y > 5 || y < 0)
            return;
        m_y = y;
        m_x = x;
        m_active_flag = true;
    }

    auto is_active() const {return m_active_flag;}

    // todo: use hash table  instead of the switch later !!!
    void move() {
        if (!m_active_flag) return;

        switch (m_facing) {
            case Direction::NORTH:
                if (m_y + 1 <= 5) {
                    m_y++;
                }
                break;
            case Direction::SOUTH:
                if (m_y - 1 > 0) {
                    m_y--;
                }
                break;
            case Direction::EAST:
                if (m_x + 1 <= 5) {
                    m_x++;
                }
                break;
            case Direction::WEST:
                if (m_y - 1 <= 5) {
                    m_y--;
                }
                break;
            default:
                // throw
                cout << "Direction:" << static_cast<int>(m_facing) << endl;
                abort();

        }
    }


    void right () {
        //  check placed or not
        if (!m_active_flag) return;

        // If performance matters, I can  use m_facing = (m_facing + 1) % 4;
        // overload enum class may be needed.
        // But now, use switch statement for readable code
        switch (m_facing)
        {
            case Direction::NORTH:
                m_facing = Direction::EAST;
                break;
            case Direction::EAST:
                m_facing = Direction::SOUTH;
                break;
            case Direction::SOUTH:
                m_facing = Direction::WEST;
                break;
            case Direction::WEST:
                m_facing = Direction::NORTH;
                break;
            default:
                // throw
                cout << "Direction:" << static_cast<int>(m_facing) << endl;
                abort();
        }
    }


    void left( )
    {
        // check placed or not
        if (!m_active_flag) return;

        // If performance matters, I can  use m_facing = (m_facing + 3) % 4;
        // overload enum class may be needed.
        // But now, use switch statement for readable code
        switch (m_facing)
        {
            case Direction::NORTH:
                m_facing = Direction::WEST;
                break;
            case Direction::EAST:
                m_facing = Direction::NORTH;
                break;
            case Direction::SOUTH:
                m_facing = Direction::EAST;
                break;
            case Direction::WEST:
                m_facing = Direction::SOUTH;
                break;
            default:
                // throw
                cout << "Direction:" << static_cast<int>(m_facing) << endl;
                abort();
        }
    }

    void report() {
        assert(m_x <= 5 && m_x >= 0);
        assert(m_y <= 5 && m_y >= 0);
        assert(m_facing <= Direction::WEST && m_facing >= Direction::NORTH);

        cout << "OUTPUT: " << m_x << "," << m_y << "," << directions[static_cast<int>(m_facing)] << endl;
    }
};


#endif //IRESS_ROBOT_H
