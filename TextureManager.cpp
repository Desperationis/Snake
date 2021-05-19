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
