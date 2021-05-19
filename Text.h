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
class Text
{
public:
	Text(const char* text, int x, int y , SDL_Color& Color);
	Text(const char* text, int x, int y, double scale, SDL_Color& Color);

	void render();
	void init(TTF_Font*& font);
	int width() { return dest.w; }
private:
	SDL_Texture * texture;
	const char* text;
	SDL_Color Color;
	SDL_Rect dest;
	double scale;
};

