#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <memory>
#include <fstream>


using namespace std;
namespace toy_robot {
    // todo:
}

enum class Direction {
    NORTH = 0,
    EAST,
    SOUTH,
    WEST = 3,
    MinDirection = NORTH,
    MaxDirection = WEST,
};

const string directions[] = {"NORTH", "EAST", "SOUTH", "WEST"};

class Robot {
    int m_x = {0};
    int m_y = {0};
    Direction m_facing{Direction::NORTH};

public:


    void place(int x, int y) {
        if (x > 5 || x < 0)
            return;
        if (y > 5 || y < 0)
            return;
        m_y = y;
        m_x = x;
    }

    // todo: use hash table  instead of the switch later !!!
    void move() {
        switch (m_facing) {
            case Direction::NORTH:
                if (m_y + 1 <= 5) {
                    m_y++;
                }
                break;
            case Direction::SOUTH:
                if (m_y - 1 > 0) {
                    m_y--;
                }
                break;
            case Direction::EAST:
                if (m_x + 1 <= 5) {
                    m_x++;
                }
                break;
            case Direction::WEST:
                if (m_y - 1 <= 5) {
                    m_y--;
                }
                break;
            default:
                // throw
                cout << "Direction:" << static_cast<int>(m_facing) << endl;
                abort();

        }
    }


    void right () {
        // todo: check placed or not

        // If performance matters, I can  use m_facing = (m_facing + 1) % 4;
        // overload enum class may be needed.
        // But now, use switch statement for readable code
        switch (m_facing)
        {
            case Direction::NORTH:
                m_facing = Direction::EAST;
                break;
            case Direction::EAST:
                m_facing = Direction::SOUTH;
                break;
            case Direction::SOUTH:
                m_facing = Direction::WEST;
                break;
            case Direction::WEST:
                m_facing = Direction::NORTH;
                break;
            default:
                // throw
                cout << "Direction:" << static_cast<int>(m_facing) << endl;
                abort();
        }
    }


    void left( )
    {
        // todo: check placed or not

        // If performance matters, I can  use m_facing = (m_facing + 3) % 4;
        // overload enum class may be needed.
        // But now, use switch statement for readable code
        switch (m_facing)
        {
            case Direction::NORTH:
                m_facing = Direction::WEST;
                break;
            case Direction::EAST:
                m_facing = Direction::NORTH;
                break;
            case Direction::SOUTH:
                m_facing = Direction::EAST;
                break;
            case Direction::WEST:
                m_facing = Direction::SOUTH;
                break;
            default:
                // throw
                cout << "Direction:" << static_cast<int>(m_facing) << endl;
                abort();
        }
    }

    void report() {
        assert(m_x <= 5 && m_x >= 0);
        assert(m_y <= 5 && m_y >= 0);
        assert(m_facing <= Direction::WEST && m_facing >= Direction::NORTH);

        cout << "OUTPUT: " << m_x << "," << m_y << "," << directions[static_cast<int>(m_facing)] << endl;
    }
};


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
