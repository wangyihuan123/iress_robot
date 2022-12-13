//
// Created by ben on 9/12/22.
//

#include "Robot.h"

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
}

bool Robot::register_table(shared_ptr<IressRobot::Table> table) {
    if (nullptr == table)
        return false;

    m_table = table;
    return true;
}

bool Robot::is_active() const {
    if (m_position.is_valid() == false ||
            m_direction.is_valid() == false ||
            m_position.x() > m_table->get_width() ||
            m_position.y() > m_table->get_height()
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

bool Robot::execute_command(std::shared_ptr<Command> &p_cmd)
{
    if (nullptr == p_cmd)  // todo: should be check before
        return false;

    if (false == p_cmd->execute( m_position,  m_direction, m_table )) {
        // todo: log the failure?
        return false;
    }

    return true;
}
