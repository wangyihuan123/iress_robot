//
// Created by ben on 8/12/22.
//


#include "Parser_Singleton.h"
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include "Position.h"
#include "Direction.h"
#include "Place_Command.h"
#include "Report_Command.h"
#include "Move_Command.h"
#include "Left_Command.h"
#include "Right_Command.h"

using namespace IressRobot;
using namespace std;

Parser_Singleton *Parser_Singleton::parser_singleton = nullptr;

Parser_Singleton *Parser_Singleton::get_instance() {
    if (parser_singleton == nullptr) {
        parser_singleton = new Parser_Singleton();
    }
    return parser_singleton;
}

std::shared_ptr<Command> Parser_Singleton::parse(const string &input) {

    shared_ptr<Command> cmd;
    vector<string> commands;
    boost::split(commands, input, boost::is_any_of(" ,"), boost::algorithm::token_compress_on);

    if (true == commands.empty()) {
        return nullptr;
    }

    string command = boost::to_upper_copy(commands.front());

    // todo: can also using enum class command for switch()
    // PLACE command has 4 args which is different with other commands
    if (command == "PLACE" && commands.size() == 4) {

        auto d = IressRobot::string_to_direction(boost::to_upper_copy(commands.at(3)));
        if (d == DirectionEnum::UNKNOWN)
            return nullptr;

        Direction direction(d);
        Position position;
        try {
            position.set_x(boost::lexical_cast<int>(commands.at(1)));
            position.set_y(boost::lexical_cast<int>(commands.at(2)));
        } catch (boost::bad_lexical_cast &) {
            return nullptr;
        }

        try {
            cmd = make_shared<Place_Command>(position, direction);
        } catch (...) {
            return nullptr;
        }
    } else if (command == "MOVE" && commands.size() == 1) {
        cmd = make_shared<Move_Command>();
    } else if (command == "LEFT" && commands.size() == 1) {
        cmd = make_shared<Left_Command>();
    } else if (command == "RIGHT" && commands.size() == 1) {
        cmd = make_shared<Right_Command>();
    } else if (command == "REPORT" && commands.size() == 1) {
        try {
            cmd = make_shared<Report_Command>();
        } catch (...) {
            return nullptr;
        }
    } else {
        //anything else should be an invalid command
        return nullptr;
    }

    return cmd;
}