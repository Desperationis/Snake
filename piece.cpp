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


#include "piece.h"

SDL_Texture* piece::Head;
SDL_Texture* piece::Straight;
SDL_Texture* piece::Curved;
SDL_Texture* piece::Curved2;
SDL_Texture* piece::Tail;
piece::piece(int x, int y,int Tile,int id)
{
	moveTo(x, y);
	TILESIZE = Tile;
	this->id = id;
	dest.w = TILESIZE;
	dest.h = TILESIZE;
}


piece::~piece()
{
}

void piece::moveTo(int x, int y)
{
	this->x = x;
	this->y = y;
}

void piece::render()
{
	dest.x = x;
	dest.y = y;


	if (id == HEAD)
	{
		SDL_RenderCopyEx(Game::renderer, Head, NULL, &dest, angle, NULL, SDL_FLIP_NONE);
	}
	if (id == STRAIGHT)
	{
		SDL_RenderCopyEx(Game::renderer, Straight, NULL, &dest, angle, NULL, SDL_FLIP_NONE);
	}
	if (id == CURVED)
	{
		SDL_RenderCopyEx(Game::renderer, Curved, NULL, &dest, angle, NULL, SDL_FLIP_NONE);
	}
	if (id == CURVED_)
	{
		if (angle == 0) { dest.x = x; dest.y = y-1; }
		if (angle == 90) { dest.x = x + 1; dest.y = y; }
		if (angle == 180){dest.x = x; dest.y = y + 1; }
		if (angle == 270) { dest.x = x - 1; dest.y = y; }
		SDL_RenderCopyEx(Game::renderer, Curved2, NULL, &dest, angle, NULL, SDL_FLIP_VERTICAL);
	}
}

void piece::init()
{
	Head=TextureManager::LoadTexture("../assests/SnakePieces/Head.png");
	Straight = TextureManager::LoadTexture("../assests/SnakePieces/StraightPiece.png");
	Curved = TextureManager::LoadTexture("../assests/SnakePieces/CurvedPiece.png");
	Curved2 = TextureManager::LoadTexture("../assests/SnakePieces/CurvedPiece2.png");
}

void piece::SetOrientation(char id)
{
	switch (id)
	{
	case RIGHT:
		{
			angle = 0;
			break;
		}
	case UP:
		{
			angle = 270;
			break;
		}
	case LEFT:
		{
			angle = 180;
			break;
		}
	case DOWN:
		{
			angle = 90;
			break;
		}
	}

	
}
