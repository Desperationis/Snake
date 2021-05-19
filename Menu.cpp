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


#include "Menu.h"
#include <iostream>
Text* Title = nullptr;
Text* Author = nullptr;
Text* Start = nullptr;
Text* Github = nullptr;
SDL_Rect tempDest;
Menu::Menu()
{
	Title = new Text("Snake",400- static_cast<int>(325/2), 10, 5, Title_Color);
	Author = new Text("By Diego C", 670,760,1, Title_Color);
	Start = new Text("START", 240, 310,5, Start_Color);
	Github = new Text("https://github.com/Desperationis/Snake", 10, 763, 1, Title_Color); 
	buttons.push_back(Button(106,300,600,200,""));
	
}
void Menu::copyDest(SDL_Rect& dest, SDL_Rect& copy, int offset)
{
	dest.x = copy.x + offset;
	dest.y = copy.y + offset;
	dest.h = copy.h - offset - offset; // "Undo's" change from x and y
	dest.w = copy.w - offset - offset;
}
void Menu::render()
{
	TextureManager::DrawTexture(background);
	SDL_SetRenderDrawColor(Game::renderer, 190, 190, 190, 255);
	for (short int i = 0; i < buttons.size(); i++)
	{
		buttons[i].render();
	}
	SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
	for (int i = 0; i <= 10; i++)
	{
		copyDest(tempDest, buttons[0].dest, i);
		SDL_RenderDrawRect(Game::renderer, &tempDest);
	}

	SDL_SetRenderDrawColor(Game::renderer, light, light, light, 255);
	Title->render();
	Author->render();
	Start->render();
	Github->render();
}

void Menu::init()
{
	for (short int i = 0; i < buttons.size(); i++)
	{
		buttons[i].init();
	}
	font = TTF_OpenFont("../fonts/8bitoperator_jve.ttf", 30);
	SDL_SetRenderDrawColor(Game::renderer, light, light, light, 255);
	background = TextureManager::LoadTexture("../assests/Grey.png");
	SDL_SetTextureAlphaMod(background, alpha);

	Title->init(font);
	Author->init(font);
	Start->init(font);
	Github->init(font);
}

void Menu::update(int &scene)
{
	//*scene = 1;
	input.update();

	buttons[0].update(input.mouse[0], input.mouse[1], input.mousebuttons[0], 1, scene);
}

void Menu::clean()
{
	for (int i = 0; i < buttons.size(); i++)
	{
		buttons[i].clean(); 
	}
	TTF_CloseFont(font);
	font = nullptr;
	SDL_DestroyTexture(background);
	background = nullptr;
	delete Title;
	delete Author;
	delete Start;
};
