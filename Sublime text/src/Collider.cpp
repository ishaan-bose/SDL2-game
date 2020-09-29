//I am now implementing the AABB method

#include "Collider.hpp"
#include <iostream>

//declaring the all colliders set since it is static
std::vector<BoxCollider> BoxCollider::all_colliders;

BoxCollider::BoxCollider(float zero_x,float zero_y,float p_w,float p_h)
    :pos00(zero_x,zero_y), upLeft(pos00.x,pos00.y), upRight(pos00.x + p_w,pos00.y),
    downLeft(pos00.x, pos00.y + p_h), downRight(pos00.x + p_w, pos00.y + p_h),
    width(p_w), height(p_h)
{
    all_colliders.push_back(*this);
}

void BoxCollider::updateRelativePosition(float p_x, float p_y)
{
    pos00.change_pos(p_x, p_y);
    
    upLeft.change_pos(p_x, p_y);
    upRight.change_pos(p_x + width, p_y);
    downLeft.change_pos(p_x, p_y + height);
    downRight.change_pos(p_x + width, p_y + height);    
}

//getters
Position BoxCollider::getUpLeft() const
{
    return upLeft;
}

Position BoxCollider::getUpRight() const
{
    return upRight;
}

Position BoxCollider::getDownLeft() const
{
    return downLeft;
}

Position BoxCollider::getDownRight() const
{
    return downRight;
}

bool operator==(BoxCollider lhs, BoxCollider rhs)
{
    if(lhs.getUpLeft() == rhs.getUpLeft() && lhs.getDownLeft() == rhs.getDownLeft() &&
    lhs.getUpRight() == rhs.getUpRight() && lhs.getDownRight() == rhs.getDownRight())
    {
        return true;
    }
    return false;
}

bool BoxCollider::has_collided(BoxCollider other)
{
    //check collision on x axis
    if(upLeft.x < other.getUpRight().x && upRight.x > other.getUpLeft().x)
    {
        if(upLeft.y < other.getDownLeft().y && downLeft.y > other.getUpLeft().y)
        {
            return true;
        }
    }
    
    return false;
}

//checkers
bool BoxCollider::checkLeft()
{
    for(int i = 0; i < all_colliders.size(); i++)
    {
        if(*this == all_colliders[i])
            continue;
        else
        {
            if(has_collided(all_colliders[i]) && upLeft.x > all_colliders[i].getUpLeft().x)
            {
                return true;
            }
        }
    }
    return false;
}


bool BoxCollider::checkRight()
{
    for(int i = 0; i < all_colliders.size(); i++)
    {
        if(*this == all_colliders[i])
            continue;
        else
        {
            if(has_collided(all_colliders[i]) && upLeft.x < all_colliders[i].getUpLeft().x)
            {
                return true;
            }
        }
    }
    return false;
}

bool BoxCollider::checkUp()
{
    for(int i = 0; i < all_colliders.size(); i++)
    {
        if(*this == all_colliders[i])
            continue;
        else
        {
            if(has_collided(all_colliders[i]) && upLeft.y < all_colliders[i].getUpLeft().y)
            {
                return true;
            }
        }
    }
    return false;
}

bool BoxCollider::checkDown()
{
    for(int i = 0; i < all_colliders.size(); i++)
    {
        if(*this == all_colliders[i])
            continue;
        else
        {
            if(has_collided(all_colliders[i]) && upLeft.y > all_colliders[i].getUpLeft().y)
            {
                return true;
            }
        }
    }
    return false;
}