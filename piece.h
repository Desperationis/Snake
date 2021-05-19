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
class piece
{
private:
	int TILESIZE;
	enum DIRECTION { UP, RIGHT, DOWN, LEFT };
	enum PIECE{HEAD,STRAIGHT,CURVED,CURVED_,TAIL};
	int id;
	double angle = 0;
	static SDL_Texture* Head;
	static SDL_Texture* Curved;
	static SDL_Texture* Curved2;
	static SDL_Texture* Straight;
	static SDL_Texture* Tail;
	SDL_Rect dest;
public:
	piece(int x, int y, int Tile, int id);
	~piece();
	static void init();
	void moveTo(int x, int y);
	void render();
	void SetId(int id) { this->id = id; };
	void SetOrientation(char id);
	static void clean() {
		SDL_DestroyTexture(Head);
		SDL_DestroyTexture(Curved);
		SDL_DestroyTexture(Curved2);
		SDL_DestroyTexture(Straight);
		SDL_DestroyTexture(Tail);
		Head = nullptr;
		Curved = nullptr;
		Curved2 = nullptr;
		Straight = nullptr;
		Tail = nullptr;
	}
	int x, y;
};

