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


#include "Input.h"


Input::Input()
{
}


Input::~Input()
{
}

void Input::update()
{
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	key = -1;

	if (keys[SDL_SCANCODE_UP] || keys[SDL_SCANCODE_W]) { key = 0; }
	if (keys[SDL_SCANCODE_RIGHT] || keys[SDL_SCANCODE_D]) { key = 1; }
	if (keys[SDL_SCANCODE_DOWN] || keys[SDL_SCANCODE_S]) { key = 2; }
	if (keys[SDL_SCANCODE_LEFT] || keys[SDL_SCANCODE_A]) { key = 3; }

	mouse[0] = Game::event.motion.x;
	mouse[1] = Game::event.motion.y;
	if (SDL_GetMouseState(NULL, NULL) && SDL_BUTTON(SDL_BUTTON_LEFT) && !mousePressed)
	{
		mousePressed = true;
		mousebuttons[0] = true;
	}
	else if (SDL_GetMouseState(NULL, NULL) && SDL_BUTTON(SDL_BUTTON_LEFT) && mousePressed)
	{
		mousebuttons[0] = false;
	}
	else
	{
		mousePressed = false;
	}
	mousebuttons[1] = SDL_GetMouseState(NULL, NULL) && SDL_BUTTON(SDL_BUTTON_RIGHT);
}
bool Input::pressed()
{
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	key = -1;

	if (keys[SDL_SCANCODE_UP]) { key = 0; }
	if (keys[SDL_SCANCODE_RIGHT]) { key = 1; }
	if (keys[SDL_SCANCODE_DOWN]) { key = 2; }
	if (keys[SDL_SCANCODE_LEFT]) { key = 3; }

	if (key != -1)
	{
		return true;
	}
	return false;
}
