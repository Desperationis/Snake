#include "Menu.h"
#include <iostream>
Text* Title = nullptr;
Text* Author = nullptr;
Text* Start = nullptr;
SDL_Rect tempDest;
Menu::Menu()
{
	Title = new Text("Snake",400- static_cast<int>(325/2), 10, 5, Title_Color);
	Author = new Text("By Deigo", 690,760,1, Title_Color);
	Start = new Text("START", 240, 310,5, Start_Color);
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
}

void Menu::init()
{
	for (short int i = 0; i < buttons.size(); i++)
	{
		buttons[i].init();
	}
	font = TTF_OpenFont("fonts/8bitoperator_jve.ttf", 30);
	SDL_SetRenderDrawColor(Game::renderer, light, light, light, 255);
	background = TextureManager::LoadTexture("assests/Grey.png");
	SDL_SetTextureAlphaMod(background, alpha);

	Title->init(font);
	Author->init(font);
	Start->init(font);
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
