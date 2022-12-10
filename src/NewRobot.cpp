//
// Created by ben on 9/12/22.
//

#include "NewRobot.h"

//
// Created by ben on 6/12/22.
//

#include "Robot.h"
#include "Direction.h"

using namespace IressRobot;
using namespace std;


Robot::Robot(std::shared_ptr<Table> table) {
    if (nullptr == table) {
        throw;
    }
    m_table = table;   // use count ++

    CommandFunctor command_function = [&](shared_ptr< Command >& command )mutable {
        this->execute_command(command);
    };
    m_commandFunctor = command_function;
}


bool Robot::is_active() const {
    if (
            m_position.x > m_table->get_width() ||
            m_position.x < 0 ||
            m_position.y > m_table->get_height() ||
            m_position.y < 0 ||

            m_direction >  Direction::MaxDirection ||
            m_direction < Direction::MinDirection
    )
        return false;
    else
        return true;
}

Position Robot::get_position() const {
// do not check active at the moment
    return m_position;
}

Direction Robot::get_direction() const {
// do not check active at the moment
    return m_direction;
}

void Robot::execute_command(std::shared_ptr<Command> &command)
{
    command->Execute( m_position,  m_direction, m_table );

    return;
}