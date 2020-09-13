#include "Position.hpp"

bool Position::operator==(Position& other) const
{
    return ((x==other.x) && (y==other.y));
}

void Position::change_pos(float p_x, float p_y)
{
    x = p_x;
    y = p_y;
}