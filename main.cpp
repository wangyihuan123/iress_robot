#include  "robot.h"


using namespace std;
namespace toy_robot {
    // todo:
}


void test() {
    Robot robot;
    robot.report();
    robot.move();
    robot.report();
    robot.place(1,1);
    robot.report();
    robot.right();
    robot.report();
    robot.move();
    robot.report();
    robot.move();
    robot.report();
    robot.move();
    robot.report();
    robot.move();
    robot.move();
    robot.move();
    robot.report();
    robot.left();
    robot.report();

}

void test_file(const string & filename) {
    auto robot = make_unique<Robot>();

    string strLine;
    ifstream inFile;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile, strLine)) {
            cout<<strLine<<endl;
//            parseLineInput(robot, strLine);
        }
        inFile.close();
    }
    else
    {
        cout<<"Cannot open file: "<< filename<<endl;
    }
}


int main(int argc, char **argv) {
    test();

//    test_file(argv[1]);

    return 0;
}
