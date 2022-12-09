#ifndef TOYROBOT_PLACE_COMMAND_H
#define TOYROBOT_PLACE_COMMAND_H

#include "Command.h"
#include "Position.h"
#include "Direction.h"
#include "Table.h"

namespace IressRobot {
//    class Table;

    class Place_Command : public Command {
    public:
        Place_Command(const Position& position, const Direction& direction );

        virtual ~Place_Command() {};

        virtual bool Execute( Position &position,
                              Direction &direction,
                              const std::shared_ptr<Table> &table);

    private:
        Position m_position;
        Direction m_direction;
    };
}
#endif

