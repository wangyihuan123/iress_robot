//
// Created by ben on 7/12/22.
//
#include "src/Robot.h"
#include "src/Table.h"
#include "src/Parser.h"
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
    shared_ptr<Table> table(new Table());
    auto robot = Robot(table);
    Parser parser = Parser();

    // read commands from an input file
    if (argc < 2) {
        cout << "Wait for the commands:" << endl;

    } else {
        string filename = argv[1];
        cout << "Reading Commands from file " << filename << "." << endl;
        ifstream ifs; // input file stream
        ifs.open(filename, ios::in);

        if (!ifs) {
            cout << "Can't open file: " << filename << endl;
            return 0;
        }

        while (!ifs.eof()) {
            string line;
            getline(ifs, line);
            cout << line << endl;
            auto cmd = parser.ParseInput(line);
            if (cmd) {
                auto result = robot.execute_command(cmd);
                if (result)
                    cout << "success." << endl;
                else
                    cout << "failed." << endl;

            }else {
                // debug
//                cout << " parsing failed.";
                cout << endl;
            }
        }
        ifs.close();

        return 0;
    }


    return 0;
}
