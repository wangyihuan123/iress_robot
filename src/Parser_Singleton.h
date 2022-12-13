//
// Created by ben on 8/12/22.
//

#ifndef IRESS_PARSER_H
#define IRESS_PARSER_H

#include "Command.h"
#include <memory>
#include <functional>

namespace IressRobot
{
    class Parser_Singleton
    {
    protected:
        static Parser_Singleton* parser_singleton;
        Parser_Singleton() = default;

    public:
        Parser_Singleton(Parser_Singleton &other) = delete;
        void operator=(const Parser_Singleton &) = delete;
        ~Parser_Singleton() = default;

        static Parser_Singleton *get_instance();

        std::shared_ptr<Command> parse( const std::string& input );

    };

}

#endif //IRESS_PARSER_H
