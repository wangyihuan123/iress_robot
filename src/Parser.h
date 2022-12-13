//
// Created by ben on 8/12/22.
//

#ifndef IRESS_PARSER_H
#define IRESS_PARSER_H

#include "Command.h"

#include <functional>
#include <memory>

namespace IressRobot
{
    class Parser
    {
    public:
        Parser() = default;
        ~Parser() = default;

        std::shared_ptr<Command> ParseInput( const std::string& input );

    };
}

#endif //IRESS_PARSER_H
