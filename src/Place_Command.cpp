#include "Table.h"
#include "Place_Command.h"

namespace IressRobot {

    Place_Command::Place_Command(const Position &position, const Direction &direction) : Command() {

        if (position.x < 0)
            throw std::invalid_argument("position.x");

        if (position.y < 0)
            throw std::invalid_argument("position.y");

        if (false == is_valid_direction(direction))
            throw std::invalid_argument("direction");

        m_position.x = position.x;
        m_position.y = position.y;
    }

    bool Place_Command::execute(Position &position,
                                Direction &direction,
                                const std::shared_ptr<Table> &table) {

        if (false == table->is_valid_location(m_position.x, m_position.y))
            return false;

        position.x = m_position.x;
        position.y = m_position.y;

        direction = m_direction;

        return true;
    }

}

