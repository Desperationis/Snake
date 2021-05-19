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
#include "piece.h"
#include "Input.h"
#include "fruit.h"
#include "Wall.h"
#include <vector>
#include <deque>

class Snek
{
public:
	Snek(const int tile);
	void init() { piece::init(); };
	void update(fruit& Fruit , std::vector<Wall>& walls);
	void render();
	void clean() { piece::clean(); }
	inline int length() { return current_pieces - 1; }
	inline bool isDead() { return Dead; };
	enum DIRECTION { UP, RIGHT, DOWN, LEFT };
	enum PIECE { HEAD, STRAIGHT, CURVED, CURVED_, TAIL };
private:
	Input input;
	std::vector<piece> Pieces;
	std::deque<PIECE> Textures;
	std::deque<DIRECTION> Angles;
	Uint32 now = 0, then = 0;
	unsigned int current_pieces;
	int velocity[2] = { 0,0 };
	int TILESIZE;
	bool Dead = false;
	int Delay = 70;
private:
	void add_piece(int x, int y,int id);
	void HandleInput();
	bool delay(int milliseconds);
};

