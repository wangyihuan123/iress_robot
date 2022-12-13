//
// Created by ben on 12/12/22.
//
#include "Position.h"

using namespace  IressRobot;

Position::Position():
        Position(-1, -1)
{
}

Position::Position(const int x, const int y) :
        m_x(x),
        m_y(y)
{
}

bool Position::operator==(const Position &position) const
{
    return m_x == position.x() && m_y == position.y();
}

int Position::x() const
{
    return m_x;
}

void Position::set_x(const int x)
{
    m_x = x;
}

int Position::y() const
{
    return m_y;
}

void Position::set_y(const int y)
{
    m_y = y;
}

void Position::set(const int x, const int y)
{
    m_x = x;
    m_y = y;
}

bool Position::is_valid() const
{
    return m_x >= 0 && m_y >= 0;
}

