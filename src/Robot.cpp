//
// Created by ben on 6/12/22.
//

#include "../include/Robot.h"
#include "../include/Direction.h"

using namespace IressRobot;
using namespace std;


Robot::Robot(std::shared_ptr<Table> table) {
    if (nullptr == table) {
        throw;
    }
    m_table = table; // use count ++
}


bool Robot::is_active() const {
    return m_active_flag;
}


bool Robot::place(const Position &position, const Direction &direction) {
    if (!m_table) {
        // todo: throw

    }

    if (!m_table->is_valid_location(position.x, position.y)) {
        return false;
    }

    if (!is_valid_direction(direction)) {
        return false;
    }

    m_position.x = position.x;
    m_position.y = position.y;
    m_direction = direction;
    m_active_flag = true;

    return true;
}

// todo: use hash table  instead of the switch later !!!
bool Robot::move() {
    if (!m_active_flag)
        return false;


    int x = m_position.x;
    int y = m_position.y;

    switch (m_direction) {
        case Direction::NORTH:
                y++;
            break;
        case Direction::SOUTH:
                y--;
            break;
        case Direction::EAST:
                x++;
            break;
        case Direction::WEST:
                x--;
            break;
        default:
            // throw
//            cout << "Direction:" << static_cast<int>(m_direction) << endl;  // debug
            abort();

    }


    if (!m_table->is_valid_location(x, y))
        return false;

    m_position.x = x;
    m_position.y = y;

    return true;
}




void Robot::right () {
    //  check placed or not
    if (!m_active_flag) return;

    // If performance matters, I can  use m_direction = (m_direction + 1) % 4;
    // overload enum class may be needed.
    // But now, use switch statement for readable code
    switch (m_direction)
    {
        case Direction::NORTH:
            m_direction = Direction::EAST;
            break;
        case Direction::EAST:
            m_direction = Direction::SOUTH;
            break;
        case Direction::SOUTH:
            m_direction = Direction::WEST;
            break;
        case Direction::WEST:
            m_direction = Direction::NORTH;
            break;
        default:
            // throw
//            cout << "Direction:" << static_cast<int>(m_direction) << endl;
            abort();
    }
}


void Robot::left( )
{
    // check placed or not
    if (!m_active_flag) return;

    // If performance matters, I can  use m_direction = (m_direction + 3) % 4;
    // overload enum class may be needed.
    // But now, use switch statement for readable code
    switch (m_direction)
    {
        case Direction::NORTH:
            m_direction = Direction::WEST;
            break;
        case Direction::EAST:
            m_direction = Direction::NORTH;
            break;
        case Direction::SOUTH:
            m_direction = Direction::EAST;
            break;
        case Direction::WEST:
            m_direction = Direction::SOUTH;
            break;
        default:
            // throw
//            cout << "Direction:" << static_cast<int>(m_direction) << endl;
            abort();
    }
}

Position Robot::get_position() const {
    return m_position;
}

Direction Robot::get_direction() const {
    return m_direction;
}


//
//void report() {
//    assert(m_x <= 5 && m_x >= 0);
//    assert(m_y <= 5 && m_y >= 0);
//    assert(m_direction <= Direction::WEST && m_direction >= Direction::NORTH);
//
//    cout << "OUTPUT: " << m_x << "," << m_y << "," << directions[static_cast<int>(m_direction)] << endl;
//}
//
//
//bool ToyRobot::rotate(const Direction::TurnDirection turnDirection) {
//    if (!isPlaced()) {
//        return false;
//    }
//
//    m_direction.turn(turnDirection);
//    return true;
//}
//

