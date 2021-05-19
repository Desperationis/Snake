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


#include "Game.h"
#include "SceneManager.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Window* Game::window = nullptr;
SDL_Event Game::event;
SceneManager sceneManager;

Game::Game()
{
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) ==0)
	{
		std::cout << "SDL Initialized" << std::endl;
		if (TTF_Init() == 0)
		{
			std::cout << "True type initialized" << std::endl;
		}
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window Created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer,0,0,0, 255);
			std::cout << "Renderer Created" << std::endl;
		}
		isRunning = true;
	}
	else { isRunning = false; };
	sceneManager.init();
}

void Game::update()
{
	sceneManager.update();
}
void Game::render()
{
	SDL_RenderClear(renderer);
	sceneManager.render();
	SDL_RenderPresent(renderer);
}
void Game::clean()
{


	sceneManager.clean();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
void Game::handleEvents()
{
	SDL_PollEvent(&Game::event);


	switch (Game::event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}
