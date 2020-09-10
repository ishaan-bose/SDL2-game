#include "Vector2.hpp"

Vector2::Vector2(float p_x = 0, float p_y = 0)
	:x(p_x),y(p_y)
{}

float Vector2::getMagnitude()
{
	return sqrt((x * x) + (y * y));
}

float Vector2::getX()
{return x;}

float Vector2::getY()
{return y;}


void Vector2::setXY(float p_x, float p_y)
{
	x = p_x;
	y = p_y;
}

void Vector2::setX(float p_x)
{x = p_x;}

void Vector2::setY(float p_y)
{y = p_y;}

void Vector2::operator=(Vector2& v)
{
	x = v.getX();
	y = v.getY();
}

Vector2 operator+(Vector2& a, Vector2& b)
{
	Vector2 v(0,0);
	v.setX(a.getX() + b.getX());
	v.setY(a.getY() + b.getY());
	return v;
}