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
class Button
{
public:
	Button(int x, int y, int w, int h, const char* texture);
	Button(int x, int y, const char* texture);

	void update(int x, int y,bool pressed , int SCENE, int & scene);
	void render();
	void renderHitbox();
	void init();
	void clean() { SDL_DestroyTexture(texture); texture = nullptr; };
	SDL_Rect dest;
private:
	const char* textureLocation = NULL;
	SDL_Texture* texture;
	bool textureLoaded = false;
};

