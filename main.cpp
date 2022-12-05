#include <iostream>
#include <string>
#include <assert.h>

#include <stdlib.h>
#include <memory>
#include <fstream>


using namespace std;
namespace toy_robot{
    // todo:
}

enum class FaceDirection {
    NORTH = 0,
    SOUTH,
    EAST,
    WEST = 3
};
const string  directions[] = {"NORTH", "SOUTH", "EAST", "WEST"};

class Robot{
    int m_x = {0};
    int m_y = {0};
    FaceDirection m_face{FaceDirection::NORTH};

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
        switch (m_face) {
            case FaceDirection::NORTH:
                if (m_y + 1 <= 5) {
                    m_y ++;
                }
                break;
            case FaceDirection::SOUTH:
                if (m_y - 1 > 0) {
                    m_y --;
                }
                break;
            case FaceDirection::EAST:
                if (m_x + 1 <= 5) {
                    m_x ++;
                }
                break;
            case FaceDirection::WEST:
                if (m_y - 1 <= 5) {
                    m_y --;
                }
                break;
            default:
                // throw
                cout << "FaceDirection:" << static_cast<int>(m_face) << endl;
                abort();

        }
    }

    void report(void) {
        assert(m_x<=5 && m_x >=0);
        assert(m_y<=5 && m_y >=0);
        assert(m_face<=FaceDirection::WEST && m_face >=FaceDirection::NORTH);

        cout << "OUTPUT: " << m_x << "," << m_y << "," << directions[static_cast<int>(m_face)] << endl;
    }
};


void parseLineInput(unique_ptr<Robot> & robot, string strLine)
{

}

int main(int argc, char** argv) {
    auto robot = make_unique<Robot>();

    string strLine;
    ifstream inFile;
    inFile.open(argv[1]);
    if(inFile.is_open())
    {
        while(getline(inFile, strLine)) {
            cout<<strLine<<endl;
//            parseLineInput(robot, strLine);
        }
        inFile.close();
        return 0;
    }
    else
    {
        cout<<"Cannot open file: "<<argv[1]<<endl;
    }

    return 0;
}
