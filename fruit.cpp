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


#include "fruit.h"
#include "Snek.h"
#include <math.h>

SDL_Texture* fruit::texture;
fruit::~fruit()
{
}
double angle;
void fruit::render()
{
	angle += 5;
	angle = fmod(angle, 360);
	dest.x = x;
	dest.y = y;
	dest.w = TILESIZE;
	dest.h = TILESIZE;
	//TextureManager::DrawTexture(texture, dest);
	SDL_RenderCopyEx(Game::renderer, texture, NULL, &dest, angle, NULL, SDL_FLIP_NONE);
}
inline int fruit::random(int range)
{
	return rand() % range;
}
void fruit::teleport(const std::vector<piece>& list)
{
	x = ((random(29)+1) * TILESIZE) + TILESIZE;
	y = ((random(29) + 1) * TILESIZE) + TILESIZE;
}

void fruit::LoadImage()
{
	texture = TextureManager::LoadTexture("assests/Fruits/Fruit_3.png");
}
