//I am now implementing the AABB method

#include "Collider.hpp"

//declariong the all colliders vector since it is static
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

Position BoxCollider::getUpLeft()
{
    return upLeft;
}

//i will add check down function later on