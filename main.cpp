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

    try {
        shared_ptr<Table> table(new Table());
        auto robot = Robot(table);
        Parser parser = Parser();

        if (argc < 2) {
            // read commands from console or simulator
            cout<<"Please use following commands to operate a robot on 5x5 table, and use enter to end."<<endl;
            cout<<"PLACE x(0-4),y(0-4),direction(north/east/south/west)"<<endl;
            cout<<"MOVE"<<endl;
            cout<<"LEFT"<<endl;
            cout<<"RIGHT"<<endl;
            cout<<"REPORT"<<endl;
            cout << "Wait for the commands..." << endl;

            string line;
            bool run_flag = true;
            while(run_flag)
            {
                getline(cin,line);
                auto cmd = parser.ParseInput(line);
                if (cmd) {
                    auto result = robot.execute_command(cmd);
                    if (result){
                        ;
                    }
                    else
                        cout << "<fail>" << endl;

                } else {
                    run_flag = false;
                }
            }

        } else {
            // read commands from an input file
            string filename = argv[1];
            cout << "Reading Commands from file [" << filename << "]." << endl;
            ifstream ifs; // input file stream
            ifs.open(filename, ios::in);

            if (!ifs) {
                cout << "Can't open file: " << filename << endl;
                return 1;
            }

            while (!ifs.eof()) {
                string line;
                getline(ifs, line);
                cout << line << endl;
                auto cmd = parser.ParseInput(line);
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
        std::cerr << "Caught unknown exception" << std::endl;
        return 1;
    }

    return 0;
}
