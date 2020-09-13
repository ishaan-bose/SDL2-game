//I am using the collision detection method AABB that stands
//for Axis Aligned Bounding Box.hpp"
//This method is used as long as the colliders are squares/rectangles
//and they dont rotate.Also the sides of the squares/rectangles should
//be parallel to the x and y axis

#pragma once

#include <vector>
#include <iterator>

#include "Position.hpp"

class BoxCollider
{
    //the relative zero, zero position. Relative to the entity
    Position pos00;
    
    Position upLeft;
    Position upRight;
    Position downLeft;
    Position downRight;
    
    short width, height;
    
    static std::vector<BoxCollider> all_colliders;
    
public:
    
    BoxCollider(float zero_x,float zero_y,float p_w,float p_h);
    
    void updateRelativePosition(float p_x, float p_y);
    
    //temporarily commented off this portion
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