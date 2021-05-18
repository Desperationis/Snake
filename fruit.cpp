#include "fruit.h"
#include "Snek.h"
#include <math.h>

SDL_Texture* fruit::texture;
fruit::~fruit()
{
}
double angle;
void fruit::render()
{
	angle += 5;
	angle = fmod(angle, 360);
	dest.x = x;
	dest.y = y;
	dest.w = TILESIZE;
	dest.h = TILESIZE;
	//TextureManager::DrawTexture(texture, dest);
	SDL_RenderCopyEx(Game::renderer, texture, NULL, &dest, angle, NULL, SDL_FLIP_NONE);
}
inline int fruit::random(int range)
{
	return rand() % range;
}
void fruit::teleport(const std::vector<piece>& list)
{
	x = ((random(29)+1) * TILESIZE) + TILESIZE;
	y = ((random(29) + 1) * TILESIZE) + TILESIZE;
}

void fruit::LoadImage()
{
	texture = TextureManager::LoadTexture("assests/Fruits/Fruit_3.png");
}
