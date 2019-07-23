#include "stdafx.h"
#include "Button.h"


Button::Button(int x, int y, int w, int h, const char* texture)
{
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
	this->textureLocation = texture;
	textureLoaded = true;
}
Button::Button(int x, int y, const char* texture)
{
	dest.x = x;
	dest.y = y;
	this->textureLocation = texture;
}

void Button::init()
{
	texture = TextureManager::LoadTexture(textureLocation);
	if (!textureLoaded)
	{
		SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	}
}
void Button::render()
{
	SDL_RenderFillRect(Game::renderer, &dest);
}
void Button::renderHitbox()
{
	SDL_RenderDrawRect(Game::renderer, &dest);
}

void Button::update(int x, int y, bool pressed , int SCENE , int & scene)
{
	if (x > dest.x && x < dest.w + dest.w && y>dest.y && y < dest.y + dest.h && pressed)
	{
		scene = SCENE;
	}
}


