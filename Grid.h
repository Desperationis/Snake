// Snake - A simple game of snake in C++ and SDL.
// Copyright (C) 2021   Diego Contreras
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.


#pragma once
#include "Game.h"
#include "Wall.h"
#include <vector>

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

