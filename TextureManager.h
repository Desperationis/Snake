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
#include "Game.h" //NEEDS RENDERER
class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* texture);
	static void DrawTexture(SDL_Texture* texture, SDL_Rect scr, SDL_Rect dest);
	static void DrawTexture(SDL_Texture* tex, SDL_Rect dest);
	static void DrawTexture(SDL_Texture* tex);
	static SDL_Texture* LoadText(const char* text, SDL_Color color,TTF_Font* font);
};



