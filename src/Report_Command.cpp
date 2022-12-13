#include "Table.h"
#include "Position.h"
#include "Report_Command.h"

#include <iostream>

namespace IressRobot
{

    bool Report_Command::execute( Position &position,
                  Direction &direction,
                  const std::shared_ptr<Table> &table)
{
    if (nullptr == table) {
        std::cout << " The table hasn't been set yet" << std::endl;
        return false;
    }

    std::cout << position.x() << "," << position.y() << ","
            << IressRobot::direction_to_string(direction)<< std::endl;

    return true;
}

}

