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
    class Position
    {
    public:
        Position();
        Position(const int x, const int y);
        ~Position() = default;

        bool operator==(const Position& position) const;

        [[nodiscard]] int x() const;
        void set_x(const int x);

        [[nodiscard]] int y() const;
        void set_y(const int y);

        void set(const int x, const int y);

        [[nodiscard]] bool is_valid() const;

    private:
        int m_x;
        int m_y;
    };
}

#endif //IRESS_POSITION_H
