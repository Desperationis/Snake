#pragma once
#include "TextureManager.h"
#include "Grid.h"
#include <cstdio>
#include <ctime>

class piece; //I think this is forward declaration used to avoid circular dependencies
class fruit
{
public:
	fruit(int TILESIZE) { 
		srand(static_cast<unsigned int>(time(0))); 
		this->TILESIZE = TILESIZE;
		y = 15 * TILESIZE;
		x = 27 * TILESIZE;
	};
	~fruit();

	void teleport(const std::vector<piece>& list);
	void render();
	void LoadImage();
	static void clean() { SDL_DestroyTexture(texture); texture = nullptr; };
	inline int random(int range);
	int TILESIZE;
	int x, y;
private:

	static SDL_Texture * texture;
	SDL_Rect dest;
};

