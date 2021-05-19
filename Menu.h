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
#include "Input.h"
#include "Button.h"
#include "TextureManager.h"
#include "Text.h"
#include <vector>
class Menu
{
public:
	Menu();
	void render();
	void update(int &scene);
	void init();
	void clean();
	void copyDest(SDL_Rect& dest, SDL_Rect& copy,int offset);
	Uint8 alpha = 190;
	SDL_Texture* background;
private:
	Input input;
	int light = 110;
	std::vector<Button> buttons;
	TTF_Font* font;
	SDL_Color Title_Color = { 190,190,190 };
	SDL_Color Start_Color = {0,0,0};
};

