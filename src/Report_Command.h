#ifndef IRESSROBOT_REPORT_COMMAND_H
#define IRESSROBOT_REPORT_COMMAND_H

#include "Command.h"

namespace IressRobot {
    class Table;
    class Position;
    class Direction;

    class Report_Command : public Command {
    public:
        Report_Command( ) = default;
        ~Report_Command() override = default;

        bool execute( Position &position,
                              Direction &direction,
                              const std::shared_ptr<Table> &table) override;

    };
}
#endif

