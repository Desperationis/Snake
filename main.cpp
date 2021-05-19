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

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int FRAME_DELAY = 1000 / FPS; // In milliseconds
	Uint32 frameStart, elapsedTime;

	Game game("Snake", 800, 800, false);

	while (game.running())
	{
		frameStart = SDL_GetTicks();

		game.handleEvents();
		game.update();
		game.render();

		elapsedTime = SDL_GetTicks() - frameStart;

		std::cout<<game.running()<<std::endl;
		
		// Delay frame for x milliseconds while taking into account execution
		// time. 
		if (FRAME_DELAY > elapsedTime)
		{
			SDL_Delay(FRAME_DELAY - elapsedTime);
		}
	}

	game.free();

	return 0;
}
