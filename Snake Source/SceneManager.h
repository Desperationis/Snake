#pragma once
class SceneManager
{
public:

	void render();
	void update();
	void init();
	void clean();
	void paseTo(int pase) { scene = pase; };
private:
	enum SCENES{MAIN,GRID,DEAD };
	int scene = MAIN;
};

