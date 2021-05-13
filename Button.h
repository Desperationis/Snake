#pragma once
#include "TextureManager.h"
class Button
{
public:
	Button(int x, int y, int w, int h, const char* texture);
	Button(int x, int y, const char* texture);

	void update(int x, int y,bool pressed , int SCENE, int & scene);
	void render();
	void renderHitbox();
	void init();
	void clean() { SDL_DestroyTexture(texture); texture = nullptr; };
	SDL_Rect dest;
private:
	const char* textureLocation = NULL;
	SDL_Texture* texture;
	bool textureLoaded = false;
};

