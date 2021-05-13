#pragma once
#include "Game.h"
#include "Wall.h"
class Grid
{
public:
	Grid();

	void render();
	void update();
	void init();
	void clean();
	void Restart();
	void UpdateScore();
	int Score();

private:
	std::vector<Wall> walls;
	SDL_Rect dest;
	SDL_Rect dest_bold;
	int TILESIZE = 25;
	TTF_Font * font;
	SDL_Texture* score;
	SDL_Color Color = { 170,170,170 };
	int light = 110;
	int temp;
	SDL_Rect FontDest;
};

