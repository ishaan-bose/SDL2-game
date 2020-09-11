#pragma once

#include <vector>
#include <iterator>

#include "Position.hpp"

class BoxCollider
{
    //the relative zero, zero position. Relative to the entity
    Position pos00;
    
    std::vector<Position> upDetectors;
    std::vector<Position> downDetectors;
    std::vector<Position> leftDetectors;
    std::vector<Position> rightDetectors;
    
    static std::vector<BoxCollider> all_colliders;
    
public:
    
    BoxCollider(float zero_x,float zero_y,float p_w,float p_h);
    
    void updateRelativePosition(float p_x, float p_y);
    
    //getters
    Position getUpLeft();
    Position getDownLeft();
    Position getUpRight();
    Position getDownRight();
    
    //checkers
    bool checkLeft() const;
    bool checkRight() const;
    bool checkUp() const;
    bool checkDown() const;
};