#pragma once

#include <iostream>
#include <vector>
#include "Player.h"
#include "Dice.h"

class Game
{
public:
	enum state
	{
		ROLLING,
		ROLLED,
		HOLD,
		SCORE
	};

	Game();
	void Input();
	void Update();
	void Draw();
	void GetPlayers();
	void ResetDice();
	bool GameOver();

	bool PlayerScored() { return playerScored; }

	void IncrementRound() { currentRound++; playerScored = false; }
	int CurrentRound() { return currentRound; }

	void IncrementPlayer() { currentPlayer++; if (currentPlayer > (int)players.size() - 1) currentPlayer = 0; }
	int CurrentPlayer() { return currentPlayer; }

private:
	std::vector<Player> players;
	int roundCount;
	int state = ROLLING;
	bool playing = true;
	bool playerScored = false;
	int currentRound;
	int currentPlayer;
	Dice readyDice;
	Dice heldDice;
	std::vector<int> diceToHold;

};