#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <iostream>

class Game
{
public:
	Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; };
	static SDL_Renderer *renderer;
	static SDL_Window *window;
	static SDL_Event event;
private:
	bool isRunning;
};

