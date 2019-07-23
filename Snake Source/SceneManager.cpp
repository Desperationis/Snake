#include "stdafx.h"
#include "SceneManager.h"
#include "Grid.h"
#include "Menu.h"

Grid grid;
Menu menu;

void SceneManager::render()
{
	switch (scene)
	{
	case MAIN:
		grid.render();
		menu.render();
		break;
	case GRID:
		grid.render();
		break;
	case DEAD:
		break;

	}
}
void SceneManager::init()
{
	grid.init();
	menu.init();
}
void SceneManager::update()
{
	switch (scene)
	{
	case MAIN:
		menu.update(scene);
		break;
	case GRID:
		grid.update();
		break;
	case DEAD:
		break;

	}
}

void SceneManager::clean()
{
	grid.clean();
	menu.clean();
}