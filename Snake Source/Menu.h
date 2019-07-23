#pragma once
#include "Input.h"
#include "Button.h"
#include "TextureManager.h"
#include "Text.h"
class Menu
{
public:
	Menu();
	void render();
	void update(int &scene);
	void init();
	void clean();
	void copyDest(SDL_Rect& dest, SDL_Rect& copy,int offset);
	Uint8 alpha = 190;
	SDL_Texture* background;
private:
	Input input;
	int light = 110;
	std::vector<Button> buttons;
	TTF_Font* font;
	SDL_Color Title_Color = { 190,190,190 };
	SDL_Color Start_Color = {0,0,0};
};

