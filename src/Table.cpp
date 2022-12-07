//
// Created by ben on 6/12/22.
//

#include "../include/Table.h"
#include <stdexcept>

using namespace IressRobot;

Table::Table() {
    m_width = _table_default_dim;
    m_height = _table_default_dim;
}

Table::Table(const int width, const int height)
        : m_width(width), m_height(height) {
    if (m_width <= 0)
        throw std::invalid_argument("width");
    if (m_height <= 0)
        throw std::invalid_argument("height");
}

bool Table::is_valid_location(int x, int y) const {
    return x >= 0 && y >= 0 &&
           x < m_width && y < m_height;
}
