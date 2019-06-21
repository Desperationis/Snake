#pragma once
#include "TextureManager.h"
class piece
{
private:
	int TILESIZE;
	enum DIRECTION { UP, RIGHT, DOWN, LEFT };
	enum PIECE{HEAD,STRAIGHT,CURVED,CURVED_,TAIL};
	int id;
	double angle = 0;
	static SDL_Texture* Head;
	static SDL_Texture* Curved;
	static SDL_Texture* Curved2;
	static SDL_Texture* Straight;
	static SDL_Texture* Tail;
	SDL_Rect dest;
public:
	piece(int x, int y, int Tile, int id);
	~piece();
	static void init();
	void moveTo(int x, int y);
	void render();
	void SetId(int id) { this->id = id; };
	void SetOrientation(char id);
	static void clean() {
		SDL_DestroyTexture(Head);
		SDL_DestroyTexture(Curved);
		SDL_DestroyTexture(Curved2);
		SDL_DestroyTexture(Straight);
		SDL_DestroyTexture(Tail);
		Head = nullptr;
		Curved = nullptr;
		Curved2 = nullptr;
		Straight = nullptr;
		Tail = nullptr;
	}
	int x, y;
};

