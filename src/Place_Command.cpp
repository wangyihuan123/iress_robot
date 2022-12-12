#include "Table.h"
#include "Place_Command.h"

namespace IressRobot {

    Place_Command::Place_Command(const Position &position, const Direction &direction) : Command() {

        if (false == position.is_valid())
            throw std::invalid_argument("position");


        if (false == direction.is_valid())
            throw std::invalid_argument("direction");

        m_position.set_x(position.x());
        m_position.set_y(position.y());

        m_direction.set(direction.get());
    }

    bool Place_Command::execute(Position &position,
                                Direction &direction,
                                const std::shared_ptr<Table> &table) {

        if (false == table->is_valid_location(m_position.x(), m_position.y()))
            return false;

        position.set_x(m_position.x());
        position.set_y(m_position.y());

        direction = m_direction;

        return true;
    }

}

