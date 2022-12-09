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
    typedef std::function< void( std::shared_ptr< Command >& ) > CommandFunctor;

    class Parser
    {
    public:
        Parser(  CommandFunctor& functor );

        bool ParseInput( const std::string& input );

    private:
        CommandFunctor m_commandFunctor;
    };
}

#endif //IRESS_PARSER_H
