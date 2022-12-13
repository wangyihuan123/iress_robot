#ifndef IRESSROBOT_PLACE_COMMAND_H
#define IRESSROBOT_PLACE_COMMAND_H

#include "Command.h"
#include "Position.h"
#include "Direction.h"
#include "Table.h"

namespace IressRobot {
//    class Table;

    class Place_Command : public Command {
    public:
        explicit Place_Command(const Position& position, const Direction& direction );

        ~Place_Command() override = default;

        bool execute( Position &position,
                              Direction &direction,
                              const std::shared_ptr<Table> &table) override;

        Position get_position(){return m_position;}
        Direction get_direction() {return m_direction;}

    private:
        Position m_position;
        Direction m_direction;
    };
}
#endif

