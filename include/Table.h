//
// Created by ben on 6/12/22.
//

#ifndef IRESS_TABLE_H
#define IRESS_TABLE_H

namespace  IressRobot {
    // Table represents a two dimensional array of tabletop
    class Table
    {
    public:
        // This constructor can throw an invalid_argument exception,
        // e.g.,  width and or height is negative integer
        Table(const int width, const int height);
        virtual ~Table() = default;

        [[nodiscard]] auto getWidth() const { return m_width; }
        [[nodiscard]] auto getHeight() const { return m_height; }

        [[nodiscard]] bool is_valid_location(int x, int y) const ;

    private:
        int m_width;
        int m_height;
    };
}


#endif //IRESS_TABLE_H
