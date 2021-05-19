// Snake - A simple game of snake in C++ and SDL.
// Copyright (C) 2021	Diego Contreras
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


#include "Button.h"

Button::Button(int x, int y, int w, int h, const char* texture)
{
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
	this->textureLocation = texture;
	textureLoaded = true;
}
Button::Button(int x, int y, const char* texture)
{
	dest.x = x;
	dest.y = y;
	this->textureLocation = texture;
}

void Button::init()
{
	texture = TextureManager::LoadTexture(textureLocation);
	if (!textureLoaded)
	{
		SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	}
}
void Button::render()
{
	SDL_RenderFillRect(Game::renderer, &dest);
}
void Button::renderHitbox()
{
	SDL_RenderDrawRect(Game::renderer, &dest);
}

void Button::update(int x, int y, bool pressed , int SCENE , int & scene)
{
	if (x > dest.x && x < dest.w + dest.w && y>dest.y && y < dest.y + dest.h && pressed)
	{
		scene = SCENE;
	}
}


