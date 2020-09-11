#pragma once

struct Position
{
    float x, y;
    Position(float p_x, float p_y)
        :x(p_x), y(p_y) {}
    Position() = default;
    
    Position operator==(Position& other) const;
};

Position::Position operator==(Position& other) const
{
    return((x==other.x) && (y==other.y));
}