#include "Game.h"
#include "SceneManager.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Window* Game::window = nullptr;
SDL_Event Game::event;
SceneManager sceneManager;

static void SetSDLIcon(SDL_Window* window)
{
	// this will "paste" the struct my_icon into this function
#include "assests/my_icon.c"
	// these masks are needed to tell SDL_CreateRGBSurface(From)
	// to assume the data it gets is byte-wise RGB(A) data
	Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	int shift = (gimp_image.bytes_per_pixel == 3) ? 8 : 0;
	rmask = 0xff000000 >> shift;
	gmask = 0x00ff0000 >> shift;
	bmask = 0x0000ff00 >> shift;
	amask = 0x000000ff >> shift;
#else // little endian, like x86
	rmask = 0x000000ff;
	gmask = 0x0000ff00;
	bmask = 0x00ff0000;
	amask = (gimp_image.bytes_per_pixel == 3) ? 0 : 0xff000000;
#endif
	SDL_Surface* icon = SDL_CreateRGBSurfaceFrom((void*)gimp_image.pixel_data, gimp_image.width,
		gimp_image.height, gimp_image.bytes_per_pixel * 8, gimp_image.bytes_per_pixel*gimp_image.width,
		rmask, gmask, bmask, amask);
	SDL_SetWindowIcon(window, icon);

	SDL_FreeSurface(icon);
}

Game::Game()
{
}

void init_()
{
	sceneManager.init();
	SetSDLIcon(Game::window);
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
	init_();
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
