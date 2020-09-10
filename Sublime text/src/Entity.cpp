#include "Entity.hpp"

Entity::Entity(float p_x, float p_y, float p_w, float p_h, float p_mw, float p_mh, SDL_Texture *p_tex)
	:x(p_x), y(p_y), magw(p_mw), magh(p_mh), main_tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = p_w;
	currentFrame.h = p_h;
}

float Entity::getX()
{
	return x;
}

float Entity::getY()
{
	return y;
}


void Entity::setX(float p_x)
{
	x = p_x;
}


void Entity::setY(float p_y)
{
	y = p_y;
}

void Entity::setXY(float p_x, float p_y)
{
	x = p_x;
	y = p_y;
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
	x += v.getX();
	y += v.getY();
}