#include "AnimatedEntity.hpp"

AnimatedEntity::AnimatedEntity(float p_x, float p_y, float p_w, float p_h, float p_mw, float p_mh, SDL_Texture *p_tex)
:Entity(p_x, p_y, p_w, p_h,p_mw,p_mh,p_tex)
{
	textures.push_back(main_tex);
	current_tex = main_tex;
}

void AnimatedEntity::pushTexture(SDL_Texture* p_tex)
{
	textures.push_back(p_tex);
}

void AnimatedEntity::setCurrentTexture(int textureIndex)
{
	if(textureIndex > textures.size()-1)
		return;
	else
	{
		current_tex = textures.at(textureIndex);
	}
}

SDL_Texture* AnimatedEntity::getTex()
{
	return current_tex;
}