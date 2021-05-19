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

