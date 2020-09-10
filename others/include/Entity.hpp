#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Vector2.hpp"
#include "Position.hpp"

class Entity
{
public:
	Entity(float p_x, float p_y, float p_w, float p_h, float p_mw, float p_mh, SDL_Texture *p_tex);

	float getX();
	float getY();

	void setX(float p_x);
	void setY(float p_y);

	void setXY(float p_x, float p_y);
	void addVector(Vector2 v);

	float getMagh();
	float getMagw();

	virtual SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();

private:
	//position
	Position pos;
	//magnify width and height
	float magw, magh;
	//how much of the image should be used/cropped and what part
	SDL_Rect currentFrame;

protected:
	//texture
	SDL_Texture *main_tex;
};