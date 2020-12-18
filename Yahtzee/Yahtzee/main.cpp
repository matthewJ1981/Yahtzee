#define TESTING 1

#ifndef TESTING

#include "Game.h"

int main()
{
	Game game;
	game.GetPlayers();
	bool playing = true;
	while (playing)
	{
		//Player 1 Turn
		//player1 roll
		//player1 Draw
		//player1 hold dice or score

		//repeat up to 3 times

		//player2 roll
		//player2 show result
		//player2 hold dice or score

		//repeat up to 3 times

		game.Input();
		game.Update();
		game.Draw();

		playing = game.GameOver();
	}
}

#else //TESTING

#include <iostream>
#include <vector>

#include <algorithm>
#include "Die.h"

#include <gtest\gtest.h>
#include ".\Tests\DieTest.h"
#include ".\Tests\DiceTest.h"
#include ".\Tests\CategoryTest.h"
#include ".\Tests\UpperSectionTest.h"

int main()
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}

#endif