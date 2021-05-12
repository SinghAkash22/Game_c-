#include"Game.h"
int main(int argc,char *args[])
{
	Game game;
	bool rungae=game.initialise();
	if (rungae)
	{
		game.gameloop();
	}
	game.stopgame();
	return 0;
}