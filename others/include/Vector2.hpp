#pragma once
#include <math.h>


class Vector2
{
	float x, y;

	friend Vector2 operator+(Vector2& a, Vector2& b);	

public:
	Vector2() = default;
	Vector2(float p_x, float p_y);

	float getMagnitude();
	float getX();
	float getY();
	void setX(float p_x);
	void setY(float p_y);
	void setXY(float p_x, float p_y);

	void operator=(Vector2& v);
};