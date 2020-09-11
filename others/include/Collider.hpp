#pragma once

#include <vector>

#include "Position.hpp"

class BoxCollider
{
    //the relative zero, zero position. Relative to the entity
    Position pos00;
    
    Position downleft;
    Position downright;
    Position upleft;
    Position upright;
    
    static std::vector<BoxCollider> colliders;
    
public:
    
    BoxCollider(float zero_x,float zero_y,float p_w,float p_h);
    
    void updateRelativePosition(float p_x, float p_y);
    
    bool checkLeft() const;
    bool checkRight() const;
    bool checkUp() const;
    bool checkDown() const;
};