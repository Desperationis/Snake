#pragma once
#include "TextureManager.h"
class Wall
{
public:
	Wall(int x, int y, int TILESIZE) {
		this->x = x; this->y = y; dest.w = dest.h = TILESIZE; dest.x = x;
		dest.y = y;
	};
	int x, y;
private:
	SDL_Rect dest;
};

