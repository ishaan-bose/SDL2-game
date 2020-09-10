#pragma once

#include <vector>

#include "Position.hpp"

class BoxCollider
{
    Position downleft;
    Position downright;
    Position upleft;
    Position upright;
    
public:
    
    BoxCollider(p_w,p_h);
    
    bool checkLeft() const;
    bool checkRight() const;
    bool checkUp() const;
    bool checkDown() const;
};