//
// Created by ben on 6/12/22.
//

#ifndef IRESS_TABLE_H
#define IRESS_TABLE_H

#include <memory>

namespace  IressRobot {
    const int _table_default_dim = 5;
    // Table represents a two dimensional array of tabletop
    class Table
    {
    public:
        Table();
        // This constructor can throw an invalid_argument exception,
        // e.g.,  width and or height is negative integer
        Table(int width,  int height);

        Table(const Table & table) = delete;
        Table(const Table && table) = delete;  // todo:
        Table operator=(Table const & table) = delete; // todo:
        virtual ~Table() = default;

        [[nodiscard]] auto get_width() const { return m_width; }
        [[nodiscard]] auto get_height() const { return m_height; }
        [[nodiscard]] bool is_valid_location(int x, int y) const ;

    private:
        int m_width;
        int m_height;

        // todo: for multiple Robots
        // vector<> weak_ptr<Robot> m_robot;
    };
}


#endif //IRESS_TABLE_H
