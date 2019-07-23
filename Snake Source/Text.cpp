#include "stdafx.h"
#include "Text.h"


Text::Text(const char* text, int x, int y, SDL_Color& Color)
{
	this->text = text;
	dest.x = x;
	dest.y = y;
	this->Color = Color;
}
Text::Text(const char* text, int x,int y, double scale, SDL_Color& Color)
{
	this->text = text;
	dest.x = x;
	dest.y = y;
	this->scale = scale;
	this->Color = Color;
}

void Text::init(TTF_Font*& font)
{
	texture = TextureManager::LoadText(text, Color, font);
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	dest.w *= scale;
	dest.h *= scale;
}

void Text::render()
{
	TextureManager::DrawTexture(texture, dest);
}
