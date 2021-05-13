#pragma once
#include "piece.h"
#include "Input.h"
#include "fruit.h"
#include "Wall.h"

class Snek
{
public:
	Snek(const int tile);
	void init() { piece::init(); };
	void update(fruit& Fruit , std::vector<Wall>& walls);
	void render();
	void clean() { piece::clean(); }
	inline int length() { return current_pieces - 1; }
	inline bool isDead() { return Dead; };
	enum DIRECTION { UP, RIGHT, DOWN, LEFT };
	enum PIECE { HEAD, STRAIGHT, CURVED, CURVED_, TAIL };
private:
	Input input;
	std::vector<piece> Pieces;
	std::deque<PIECE> Textures;
	std::deque<DIRECTION> Angles;
	Uint32 now = 0, then = 0;
	unsigned int current_pieces;
	int velocity[2] = { 0,0 };
	int TILESIZE;
	bool Dead = false;
	int Delay = 70;
private:
	void add_piece(int x, int y,int id);
	void HandleInput();
	bool delay(int milliseconds);
};

