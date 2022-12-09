//
// Created by ben on 6/12/22.
//

#ifndef IRESS_POSITION_H
#define IRESS_POSITION_H

namespace IressRobot {

// May need class implementation in the future, eg, operator== or private.
// But now just use struct for simplicity.

// todo: later combine position with direction
// todo:  Position(coordinates, direction)
    struct Position {
        int x;
        int y;
    };
}

#endif //IRESS_POSITION_H
