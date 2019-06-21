#pragma once
#include "TextureManager.h"
class Text
{
public:
	Text(const char* text, int x, int y , SDL_Color& Color);
	Text(const char* text, int x, int y, double scale, SDL_Color& Color);

	void render();
	void init(TTF_Font*& font);
	int width() { return dest.w; }
private:
	SDL_Texture * texture;
	const char* text;
	SDL_Color Color;
	SDL_Rect dest;
	double scale;
};

