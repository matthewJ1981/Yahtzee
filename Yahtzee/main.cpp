#include <iostream>
#include "Game.h"

int main()
{
	Game game;
	game.Intro();
	while (true)
	{
		std::cin.get();
		game.Roll();
	}

	return 0;
	//nothing
}
