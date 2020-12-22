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
		PREHOLD,
		HOLD,
		PRESCORE,
		SCORE
	};

	Game();
	void Input();
	void Update();
	void Draw();
	void GetPlayers();
	void ResetDice();
	bool GameOver();
	void RollDice() { readyDice.Roll(); }

	bool PlayerScored() { return playerScored; }

	void IncrementRound() { currentRound++;}
	int CurrentRound() { return currentRound; }

	void IncrementPlayer() { currentPlayer++; }
	int CurrentPlayer() { return currentPlayer; }

	void IncrementRoll();


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
	int currentRoll;
	int indexToScore;
};