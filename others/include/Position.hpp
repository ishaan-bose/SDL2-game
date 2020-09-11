#pragma once

struct Position
{
    float x, y;
    Position(float p_x, float p_y)
        :x(p_x), y(p_y) {}
    Position() = default;
    
    Position operator==(Position& other) const;
    void change_(float p_x, float p_y);
};

Position::Position operator==(Position& other) const
{
    return((x==other.x) && (y==other.y));
}

void Position::change_pos(float p_x, float p_y)
{
    x += p_x;
    y += p_y;
}