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
    std::shared_ptr<Table> table(new Table());
    auto robot = Robot(table);
    Parser parser = Parser();

    // read commands from an input file
    string filename = "/home/ben/CLionProjects/iress/test_input0.txt";
    std::cout << "Reading Commands from file " << filename << "." << std::endl;
    std::ifstream ifs; // input file stream
    ifs.open(filename, std::ios::in);

    if (ifs) {
        while (!ifs.eof()) {
            std::string line;
            std::getline(ifs, line);
                std::cout << line << std::endl;
            auto cmd = parser.ParseInput( line );
            if (cmd)
                robot.execute_command(cmd);
        }
        ifs.close();
    }

    return 0;
}
