#include "Game.h"

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int FRAME_DELAY = 1000 / FPS; // In milliseconds
	Uint32 frameStart, elapsedTime;

	Game game;

	game.init("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);
	while (game.running())
	{
		frameStart = SDL_GetTicks();

		game.handleEvents();
		game.update();
		game.render();

		elapsedTime = SDL_GetTicks() - frameStart;
		
		// Delay frame for x milliseconds while taking into account execution
		// time. 
		if (FRAME_DELAY > elapsedTime)
		{
			SDL_Delay(FRAME_DELAY - elapsedTime);
		}
	}

	game.clean();

	return 0;
}
