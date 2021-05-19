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


#include "Grid.h"
#include "Snek.h"
#include "fruit.h"
#include <sstream>
Snek* Snake = nullptr;
fruit* Fruit = nullptr;

Grid::Grid()
{
	Snake = new Snek(TILESIZE);
	Fruit = new fruit(TILESIZE);
	for (int i = 0; i < 32; i++)
	{
		int tile = TILESIZE * i;
		walls.push_back(Wall(tile, 0, TILESIZE));
		walls.push_back(Wall(tile, 31 * TILESIZE, TILESIZE)); //top & bottom
	}
	for (int i = 1; i < 31;i++)
	{
		int tile = TILESIZE * i;
		walls.push_back(Wall(0, tile, TILESIZE));
		walls.push_back(Wall(31 * TILESIZE, tile, TILESIZE));//right & left
	}

	dest.x = dest.y = TILESIZE;
	dest_bold.x = dest_bold.y = TILESIZE - 1;
	dest.w = 800 - (TILESIZE * 2);
	dest.h = 800 - (TILESIZE * 2);
	dest_bold.w = 802 - (TILESIZE * 2);
	dest_bold.h = 802 - (TILESIZE * 2);
}



void Grid::render()
{
	TextureManager::DrawTexture(score, FontDest);


	Fruit->render();
	Snake->render();
	SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(Game::renderer,&dest);
	SDL_RenderDrawRect(Game::renderer, &dest_bold);
	SDL_SetRenderDrawColor(Game::renderer, light, light, light, 255);

}

void Grid::UpdateScore()
{
	std::stringstream strs;
	strs << Score();
	std::string temp_str = strs.str();
	const char* char_type = (const char*)temp_str.c_str();

	std::string s = "Score: ";
	s += char_type;
	const char* char_type2 = (const char*)s.c_str();
	score = TextureManager::LoadText(char_type2, Color, font);
	SDL_QueryTexture(score, NULL, NULL, &FontDest.w, &FontDest.h);
	FontDest.w *= 3.5;
	FontDest.h *= 3.5;
	FontDest.x = 400 - (FontDest.w / 2);
	FontDest.y = 400 - (FontDest.h / 2);
}
void Grid::update()
{
	if (temp != Snake->length())
	{
		SDL_DestroyTexture(score);
		UpdateScore();
		temp = Snake->length();
	}
	Snake->update(*Fruit , walls);

	if (Snake->isDead())
	{
		Restart();
	}
}

void Grid::init()
{
	Snake->init();
	Fruit->LoadImage();
	font = TTF_OpenFont("fonts/ka1.ttf", 30);
	UpdateScore();
	temp = Snake->length();
}
int Grid::Score()
{
	return Snake->length();
}

void Grid::clean()
{
	Snake->clean();
	Fruit->clean();
	delete Snake;
	delete Fruit;


	walls.clear();
	TTF_CloseFont(font);
	SDL_DestroyTexture(score);
	std::vector<Wall>().swap( walls );
	//Removes all elements from the vector, calling their respective destructors, leaving the container with a size of 0.
}

void Grid::Restart()
{
	delete Snake;
	delete Fruit;
	Snake = new Snek(TILESIZE);
	Fruit = new fruit(TILESIZE);
}
