#pragma once

//library i am going to inherit from
#include "Entity.hpp"

//other libraries
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

//not necessary but there to tell that i am using vectors
#include "Vector2.hpp"



class AnimatedEntity : public Entity
{
	SDL_Texture *current_tex;

	std::vector<SDL_Texture*> textures;

public:

	AnimatedEntity(float p_x, float p_y, float p_w, float p_h, float p_mw, float p_mh, SDL_Texture *p_tex);

	void pushTexture(SDL_Texture* p_tex);
	void setCurrentTexture(int textureIndex);

	SDL_Texture* getTex();
};