#include "Entity.hpp"

Entity::Entity(float p_x, float p_y, float p_w, float p_h, float p_mw, float p_mh, SDL_Texture *p_tex)
	:pos(p_x, p_y), magw(p_mw), magh(p_mh), main_tex(p_tex)
{
	//for debugging only
	//std::cout << "collider position x is: " << getCollider().getUpLeft().x << "\n";
	//std::cout << "collider position y is: " << getCollider().getUpLeft().y << "\n\n";
	
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = p_w;
	currentFrame.h = p_h;
}

float Entity::getX()
{
	return pos.x;
}

float Entity::getY()
{
	return pos.y;
}


void Entity::setX(float p_x)
{
	pos.x = p_x;
}


void Entity::setY(float p_y)
{
	pos.y = p_y;
}

void Entity::setXY(float p_x, float p_y)
{
	pos.x = p_x;
	pos.y = p_y;
}

SDL_Texture* Entity::getTex()
{
	return main_tex;
}


SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}


float Entity::getMagw()
{
	return magw;
}

float Entity::getMagh()
{
	return magh;
}

void Entity::addVector(Vector2 v)
{
 
	pos.x += v.getX();
	pos.y += v.getY();
	
	collider.updateRelativePosition(pos.x, pos.y);
	
}