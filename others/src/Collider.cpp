#include "Collider.hpp"

Collider::Collider(float zero_x,float zero_y,float p_w,float p_h)
    :pos00(zero_x,zero_y), downleft(pos00.x, pos00.y + p_h), 
    downright(pos00.x + p_w, pos00.y + p_h), upleft(pos00.x, pos00.y),
    upright(pos00.x + p_w, pos00.y)
{}