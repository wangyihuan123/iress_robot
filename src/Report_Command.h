#ifndef IRESSROBOT_REPORT_COMMAND_H
#define IRESSROBOT_REPORT_COMMAND_H

#include "Command.h"
#include "Position.h"
#include "Direction.h"
#include "Table.h"

namespace IressRobot {
//    class Table;

    class Report_Command : public Command {
    public:
        Report_Command( );

        virtual ~Report_Command() {};

        virtual bool Execute( Position &position,
                              Direction &direction,
                              const std::shared_ptr<Table> &table);

    };
}
#endif

