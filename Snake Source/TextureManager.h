#pragma once
#include "Game.h" //NEEDS RENDERER
class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* texture);
	static void DrawTexture(SDL_Texture* texture, SDL_Rect scr, SDL_Rect dest);
	static void DrawTexture(SDL_Texture* tex, SDL_Rect dest);
	static void DrawTexture(SDL_Texture* tex);
	static SDL_Texture* LoadText(const char* text, SDL_Color color,TTF_Font* font);
};



