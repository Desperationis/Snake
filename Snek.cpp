#include "stdafx.h"
#include "Snek.h"

void Snek::add_piece(int x, int y,int id)
{
	Pieces.push_back(piece(x, y,TILESIZE,id));
	current_pieces += 1;
}
Snek::Snek(const int tile)
{
	srand(static_cast<unsigned int>(time(0)));
	TILESIZE = tile;
	add_piece(3 * TILESIZE, 15 * TILESIZE,HEAD);
	Angles.push_front(RIGHT);
}

void Snek::render()
{
	for (unsigned int i = 0; i < current_pieces; i++)
	{
		Pieces[i].render();
	}
}
void Snek::HandleInput()
{
	input.update();
	bool flag = false;
	switch (input.key)
	{
	case LEFT:
		if (velocity[0] != 1 || current_pieces == 1)
		{
			if (velocity[0] == 0 && velocity[1] == 1) { Textures[0] = CURVED; Angles.push_front(LEFT); }
			else if (velocity[0] == 0 && velocity[1] == -1) { Textures[0] = CURVED_; Angles.push_front(LEFT); }
			else { Angles.push_front(LEFT); }
			velocity[0] = -1;
			velocity[1] = 0;
		}
		else { flag = true; }
		break;
	case RIGHT:
		if (velocity[0] != -1 || current_pieces == 1)
		{
			if (velocity[0] == 0 && velocity[1] == -1) { Textures[0] = CURVED; Angles.push_front(RIGHT);}
			else if (velocity[0] == 0 && velocity[1] == 1) { Textures[0] = CURVED_; Angles.push_front(RIGHT); }
			else { Angles.push_front(RIGHT); }
			velocity[0] = 1;
			velocity[1] = 0;
		}
		else { flag = true; }
		break;
	case UP:
		if (velocity[1] != 1 || current_pieces == 1)
		{
			if (velocity[0] == -1 && velocity[1] == 0) { Textures[0] = CURVED; Angles.push_front(UP);}
			else if (velocity[0] == 1 && velocity[1] == 0) { Textures[0] = CURVED_; Angles.push_front(UP); }
			else { Angles.push_front(UP); }
			velocity[1] = -1;
			velocity[0] = 0;
		}
		else { flag = true; }
		break;
	case DOWN:
		if (velocity[1] != -1 || current_pieces == 1)
		{
			if (velocity[0] == 1 && velocity[1] == 0) { Textures[0] = CURVED; Angles.push_front(DOWN);}
			else if (velocity[0] == -1 && velocity[1] == 0) { Textures[0] = CURVED_; Angles.push_front(DOWN); }
			else { Angles.push_front(DOWN); }
			velocity[1] = 1;
			velocity[0] = 0;
		}
		else { flag = true; }
		break;
	case -1:
		Angles.push_front(Angles[0]);
		break;
	}
	if(flag){
		Angles.push_front(Angles[0]);
	}
}
void Snek::update(fruit& Fruit, std::vector<Wall>& walls)
{
	

	if (delay(Delay) && !Dead)
	{
		Delay = 70;
		Textures.push_front(STRAIGHT);
		HandleInput();
		for (unsigned int i = Pieces.size() - 1; i > 0; i--)
		{
			//Check before the head moves so it wont "grow" over it
			if (i != 0)
			{
				Pieces[i].x = Pieces[i - 1].x;
				Pieces[i].y = Pieces[i - 1].y;
			}

		}
		Pieces[0].x += velocity[0] * TILESIZE;
		Pieces[0].y += velocity[1] * TILESIZE;
		if (Textures.size() > current_pieces)
		{
			Textures.pop_back();
			//Textures.back() = "H";
		}
		if (Angles.size() > current_pieces + 1)
		{
			Angles.pop_back();
		}
		for (unsigned int i = 1; i < Pieces.size(); i++)
		{
			//Start at 1 so the snake doesn't collide with itself
			if (Pieces[0].x == Pieces[i].x && Pieces[0].y == Pieces[i].y)
			{
				Pieces[0].x -= velocity[0] * TILESIZE;
				Pieces[0].y -= velocity[1] * TILESIZE;

				velocity[0] = velocity[1] = 0;
				Dead = true;
				return;
			}
		}
		for (unsigned int i = 1; i < Pieces.size(); i++)
		{
			if (Pieces.size() > 1)
			{
				Pieces[i].SetId(Textures[i-1]);
			}
		}
		for (unsigned int i = 0; i < current_pieces; i++)
		{
			Pieces[i].SetOrientation(Angles[i]);
		}
		for (unsigned int i = 0; i < walls.size(); i++)
		{
			if (walls[i].x == Pieces[0].x && walls[i].y == Pieces[0].y) {
				Pieces[0].x -= velocity[0] * TILESIZE;
				Pieces[0].y -= velocity[1] * TILESIZE;

				velocity[0] = velocity[1] = 0;
				Dead = true;
				return;
			};
		}

		if (Fruit.x == Pieces[0].x && Fruit.y == Pieces[0].y) {
			add_piece(-64, -64,STRAIGHT); Fruit.teleport(Pieces);
		};
	}

	
}

bool Snek::delay(int milliseconds)
{
	now = SDL_GetTicks();
	if (now - milliseconds > then)
	{
		then = now;
		return true;
	}

	return false;
}
