#pragma once

struct Position
{
    float x, y;
    Position(float p_x, float p_y)
        :x(p_x), y(p_y) {}
    Position() = default;
    
    bool operator==(Position& other) const;
    void change_pos(float p_x, float p_y);
};
