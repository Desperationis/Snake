#include "TextureManager.h"


SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
	SDL_Surface* tmp = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmp);
	SDL_FreeSurface(tmp);

	return tex;
}

void TextureManager::DrawTexture(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
void TextureManager::DrawTexture(SDL_Texture* tex)
{
	SDL_RenderCopy(Game::renderer, tex, NULL, NULL);
}
void TextureManager::DrawTexture(SDL_Texture* tex, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, tex, NULL, &dest);
}
SDL_Texture* TextureManager::LoadText(const char* text, SDL_Color color, TTF_Font* font)
{
	SDL_Surface * surface = TTF_RenderText_Solid(font, text, color);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
	SDL_FreeSurface(surface);

	return texture;
}
