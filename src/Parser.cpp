//
// Created by ben on 8/12/22.
//


#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <string>
#include <vector>
#include "Parser.h"
#include "Position.h"
#include "Direction.h"
#include "Place_Command.h"
#include "Report_Command.h"

using namespace IressRobot;
using namespace std;

//Parser::Parser( CommandFunctor &functor) :
//        m_commandFunctor(functor) {
//}

std::shared_ptr<Command> Parser::ParseInput(const string &input) {
//    if (nullptr == m_commandFunctor) {
//        return nullptr;
//        // todo: throw?
//    }

    vector<string> commands;
    boost::split(commands, input, boost::is_any_of(" ,"), boost::algorithm::token_compress_on);

    if (true == commands.empty()) {
        return nullptr;
    }

    string command = boost::to_upper_copy(commands.front());

    shared_ptr<Command> cmd;

    // todo: using enum class command for switch()
    // using "if/else if/else" for now
    if (command == "PLACE" && commands.size() == 4) {

        Direction direction = IressRobot::string_to_direction(boost::to_upper_copy(commands.at(3)));
        if (direction == Direction::UNKNOWN)
            return nullptr;

        Position position;
        try {
            position.x = boost::lexical_cast<int>(commands.at(1));
            position.y = boost::lexical_cast<int>(commands.at(2));
        } catch (boost::bad_lexical_cast & /*e*/ ) {
            return nullptr;
        }

        try {
            cmd  = make_shared<Place_Command>( position, direction ) ;
        } catch (...) {
            return nullptr;
        }
    } else if (command == "MOVE" && commands.size() == 1) {

    } else if (command == "LEFT") {

    } else if (command == "RIGHT") {

    } else if (command == "REPORT") {
        try {
            cmd  = make_shared<Report_Command>();
        } catch (...) {
            return nullptr;
        }
    } else {
        //anything else should be an invalid command
        return nullptr;
    }

    return cmd;

//    m_commandFunctor(cmd);

}