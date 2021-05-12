#pragma once
#include "SDL.h"
struct vector2
{
	float x;
	float y;
};
class Game
{
public:
	Game();
	bool initialise();
	void gameloop();
	void stopgame();

private:
	void getinput();
	void update();
	void givout();
	SDL_Window* mywindo;
	bool isruninng;
	SDL_Renderer* mrender;
	const int thisness=15;
	vector2 padlpos, bolpos;
	vector2 bolvelo;
	Uint32 mtickcou;
	int paddldir = 0;
	int boldir;
};
