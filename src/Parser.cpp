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

using namespace IressRobot;
using namespace std;

Parser::Parser( CommandFunctor &functor) :
        m_commandFunctor(functor) {
}

bool Parser::ParseInput(const string &input) {
    if (nullptr == m_commandFunctor) {
        return false;
        // throw?
    }

    vector<string> commands;
    boost::split(commands, input, boost::is_any_of(" ,"), boost::algorithm::token_compress_on);

    if (true == commands.empty()) {
        return false;
    }

    string command = boost::to_upper_copy(commands.front());

    shared_ptr<Command> cmd;

    // todo: using enum class command for switch()
    // using "if/else if/else" for now
    if (command == "PLACE" && commands.size() == 4) {

        Direction direction = IressRobot::string_to_direction(boost::to_upper_copy(commands.at(3)));
        if (direction == Direction::UNKNOWN)
            return false;

        Position position;
        try {
            position.x = boost::lexical_cast<int>(commands.at(1));
            position.y = boost::lexical_cast<int>(commands.at(2));
        } catch (boost::bad_lexical_cast & /*e*/ ) {
            return false;
        }

        try {
            std::shared_ptr< Command > cmd{ new Place_Command( position, direction ) };
        } catch (...) {
            return false;
        }
    } else if (command == "MOVE" && commands.size() == 1) {

    } else if (command == "LEFT") {

    } else if (command == "RIGHT") {

    } else if (command == "REPORT") {

    } else {
        //could log invalid command
        return false;
    }

    m_commandFunctor(cmd);

    return true;
}