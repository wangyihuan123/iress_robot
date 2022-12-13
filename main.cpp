//
// Created by ben on 7/12/22.
//
#include "src/Robot.h"
#include "src/Table.h"
#include "src/Parser_Singleton.h"
#include <functional>
#include <fstream>
#include <iostream>

#include "Command.h"
#include "Place_Command.h"
#include "Position.h"
#include "Direction.h"
#include "Robot.h"

using namespace IressRobot;
using namespace std;

int main(int argc, char **argv) {

    try {
        // todo: main function need to  refactoring later
        // todo: eg.  table and parser can be singleton instance for simple scenario
        shared_ptr<Table> table(new Table());
        auto robot = Robot(table);
        Parser_Singleton * parser = Parser_Singleton::get_instance();

        string line;

        if (argc < 2) {
            // read commands from console or other simulator process
            cout << "Please use following commands to operate a robot on 5x5 table, and use newline(Enter) to end." << endl;
            cout << "PLACE x(0-4),y(0-4),direction(north/east/south/west)" << endl;
            cout << "MOVE" << endl;
            cout << "LEFT" << endl;
            cout << "RIGHT" << endl;
            cout << "REPORT" << endl;
            cout << "Wait for the commands..." << endl;

            while (true) {
                getline(cin, line);

                auto cmd = parser->parse(line);
                if (!cmd) {
                    break;
                }

                auto result = robot.execute_command(cmd);
                if (result) { ;  // succeed can be muted, otherwise too much string for console control
                } else
                    cout << "<fail>" << endl;
            }

        } else {

            // read commands from an input file
            string filename = argv[1];  // todo: test more than one file at once
            cout << "Reading Commands from file [" << filename << "]." << endl;
            ifstream ifs; // input file stream
            ifs.open(filename, ios::in);

            if (!ifs) {
                cout << "Can't open file: " << filename << endl;
                return 1;
            }

            // read file line by line and process the command
            while (!ifs.eof()) {
                getline(ifs, line);
                cout << line << endl;

                auto cmd = parser->parse(line);
                if (cmd) {
                    auto result = robot.execute_command(cmd);
                    if (result)
                        cout << "<success>" << endl;
                    else
                        cout << "<fail>" << endl;

                } else {
                    // debug parsing failed.
                    cout << endl;
                }
            }
            ifs.close();
        }
    }
    catch (...) {
        std::cerr << "unknown error" << std::endl;
        return 1;
    }

    return 0;
}
