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
#include <cstdio>

SDL_Renderer* Game::renderer = nullptr;
SDL_Window* Game::window = nullptr;
SDL_Event Game::event;
SceneManager sceneManager;

Game::Game(const char* windowTitle, int width, int height, bool fullscreen) {
	int sdlInitCode = SDL_Init(SDL_INIT_EVERYTHING);
	int ttfCode = sdlInitCode == 0 ? TTF_Init() : 1;
	
	if (sdlInitCode == 0 && ttfCode == 0)
		printf("SDL and True Type Initialized.\n");
	else {
		printf("ERROR: SDL and True Type could not be initialized.\n");
		throw std::exception();
	}

	window = SDL_CreateWindow(windowTitle, 
			SDL_WINDOWPOS_CENTERED, 
			SDL_WINDOWPOS_CENTERED, 
			width, 
			height, 
			fullscreen ? SDL_WINDOW_FULLSCREEN : 0
		);

	renderer = SDL_CreateRenderer(window, -1, 0);

	if(window != nullptr && renderer != nullptr)
		printf("Created SDL Window and Renderer.\n");
	else {
		printf("ERROR: SDL Window and Renderer could not be initialized.\n");
		throw std::exception();
	}

	SDL_SetRenderDrawColor(renderer,0,0,0, 255);
	isRunning = true;

	sceneManager.init();
}

void Game::update() {
	sceneManager.update();
}

void Game::render() {
	SDL_RenderClear(renderer);
	sceneManager.render();
	SDL_RenderPresent(renderer);
}

void Game::free() {
	sceneManager.clean();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::handleEvents() {
	SDL_PollEvent(&Game::event);
	if(Game::event.type == SDL_QUIT)
		isRunning = false;
}
