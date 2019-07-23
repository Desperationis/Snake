#pragma once
#include "Game.h"
class Input
{
public:
	Input();
	~Input();
	void update();
	bool pressed();
	
	int key = -1;

	bool mousePressed = false;
	int mouse[2];
	bool mousebuttons[2];
};

