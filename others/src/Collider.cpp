#include "Collider.hpp"

BoxCollider::BoxCollider(float zero_x,float zero_y,float p_w,float p_h)
    :pos00(zero_x, zero_y)
{
    //making the detectors for upward detection
    for(int i = 0; i < p_w; i++)
    {
        upDetectors.push_back(Position(pos00.x + i, pos00.y));
    }
    
    //making the detectors for downward detection
    for(int i = 0; i < p_w; i++)
    {
        upDetectors.push_back(Position(pos00.x + i, pos00.y + p_h));
    }
    
    //making the detectors for left side detection
    for(int i = 0; i < p_h; i++)
    {
        upDetectors.push_back(Position(pos00.x, pos00.y + i));
    }
    
    //making the detectors for right side detection
    for(int i = 0; i < p_h; i++)
    {
        upDetectors.push_back(Position(pos00.x + p_w, pos00.y + i));
    }
    
    all_colliders.push_back(*this);
}

//getters
void BoxCollider::updateRelativePosition(float p_x, float p_y)
{
    pos00.x = p_x;
    pos00.y = p_y;
    
    for (auto &pos : upDetectors)
    {
        pos.x += p_x;
        pos.y += p_y;
    }
    
    for (auto &pos : leftDetectors)
    {
        pos.x += p_x;
        pos.y += p_y;
    }
    
    for (auto &pos : downDetectors)
    {
        pos.x += p_x;
        pos.y += p_y;
    }
    
    for (auto &pos : rightDetectors)
    {
        pos.x += p_x;
        pos.y += p_y;
    }
}

Position BoxCollider::getUpLeft()
{
    return pos00;
}

Position BoxCollider::getUpRight()
{
    return Position(pos00.x + upDetectors.size() - 1, pos00.y);
}

Position BoxCollider::getDownLeft()
{
    return Position(pos00.x, pos00.y + leftDetectors.size() - 1);
}

Position BoxCollider::getDownRight()
{
    return Position(pos00.x + downDetectors.size() - 1, pos00.y + rightDetectors.size() - 1);
}

//checkers
bool BoxCollider::checkLeft() const
{
    for(auto detector : leftDetectors)
    {
        for(auto col : all_colliders)
        {
            //position left of detector
            Position tempCheckerPos(detector.x - 1, detector.y);
            //  {            check if it is between the y axis of UpRight and DownRight          }    {       check if x axis matches       }
            if( (tempCheckerPos.y > col.getDownRight().y) && (tempCheckerPos.y < col.getUpRight().y) && tempCheckerPos.x == col.getUpRight().x)
                return true;
        }
    }
    
    return false;
}

bool BoxCollider::checkRight() const
{
    for(auto detector : rightDetectors)
    {
        for(auto col : all_colliders)
        {
            //position left of detector
            Position tempCheckerPos(detector.x + 1, detector.y);
            //  {            check if it is between the y axis of UpRight and DownRight          }    {       check if x axis matches       }
            if( (tempCheckerPos.y > col.getDownLeft().y) && (tempCheckerPos.y < col.getUpLeft().y) && tempCheckerPos.x == col.getUpLeft().x)
                return true;
        }
    }
    
    return false;
}

bool BoxCollider::checkUp() const
{
    for(auto detector : upDetectors)
    {
        for(auto col : all_colliders)
        {
            //position left of detector
            Position tempCheckerPos(detector.x, detector.y - 1);
            //  {            check if it is between the y axis of UpRight and DownRight          }    {       check if x axis matches       }
            if( (tempCheckerPos.x > col.getDownLeft().x) && (tempCheckerPos.x < col.getDownRight().x) && tempCheckerPos.y == col.getDownRight().y)
                return true;
        }
    }
    
    return false;
}

//i will add check down function later on