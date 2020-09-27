#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Vector2.hpp"
#include "AnimatedEntity.hpp"

int main(int argc, char *args[])
{
	//error checking
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		std::cout << "SDL has failed..., SDL ERROR: " << SDL_GetError() << std::endl;
	}

	if (!IMG_Init(IMG_INIT_PNG))
	{
		std::cout << "IMG_Init has failed!!!, Error: " << SDL_GetError() << "\n";
	}

	RenderWindow window("Game v1.0", 1180, 590);

	bool gameRunning = true;
	SDL_Event event;



	//texture
	SDL_Texture *grassTexture = window.loadTexture("res/grass_block.png");
	SDL_Texture *skyTexture = window.loadTexture("res/sky.png");
	SDL_Texture *marioTexture = window.loadTexture("res/its_a_me_mario.png");


	//Entities
	
	std::vector<Entity> entities;

	entities.push_back(Entity( (14 * 4 * 7) , (14 * 4) * 8.5, 14, 14, 4, 4, grassTexture) );

	AnimatedEntity *mario = new AnimatedEntity(0,(14 * 4) * 8.5 - 8,12,16,4,4,marioTexture);
	Vector2 mario_vel(5,0);

	//setting the grass blocks in a vector
	for(int i = 0; i < 21; i++)
	{
		entities.push_back(Entity( (14 * 4 * i) , (14 * 4) * 9.5, 14, 14, 4, 4, grassTexture) );
	}

	//Game Loop!!
	while(gameRunning)
	{
		//get input and events
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				gameRunning = false;
			}
			else if(event.type == SDL_KEYDOWN)
			{
				//if a keypress is detected, see which keypress and do approproate action
				switch(event.key.keysym.sym)
				{
					//move right
					case SDLK_RIGHT:
						mario->addVector(Vector2(5,0));
						break;
					//move left
					case SDLK_LEFT:
						mario->addVector(Vector2(-5,0));
						break;
					//move up
					case SDLK_UP:
						mario->addVector(Vector2(0,-5));
					break;
					//move down
					case SDLK_DOWN:
						mario->addVector(Vector2(0,5));
						break;
				}
			}
		}

		window.clear();

		window.render(skyTexture);

		for(Entity& entity : entities)
		{
			window.render(entity);
		}
		window.render(*mario);
		window.display();
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}
