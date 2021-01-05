#pragma once

#include <iostream>
#include <vector>
#include "Player.h"
#include "Dice.h"

class Game
{
public:
	//enum state
	//{
	//	ROLLING,
	//	ROLLED,
	//	PREHOLD,
	//	HOLD,
	//	PRESCORE,
	//	SCORE
	//};

	Game();
	//void Input();
	//void Update();
	//void Draw();


	//void ResetDice();
	//bool GameOver();
	//void RollDice() { readyDice.Roll(); }
	//bool PlayerScored() { return playerScored; }

	//bool PlayerScored() { return playerScored; }

	//void IncrementRound() { currentRound++;}
	//int CurrentRound() { return currentRound; }

	//void IncrementPlayer() { currentPlayer++; }
	//int CurrentPlayer() { return currentPlayer; }

	//void IncrementRoll();
	void Go();
	

private:
	void Turn(Player& player);
	void GetWinner();
	void GetPlayers();
	void GetStartingPlayer();

	std::vector<Player> players;
	//int roundCount;
	//int state = ROLLING;
	//bool playing = true;
	//bool playerScored = false;
	int currentRound;
	int currentPlayer;
	//int currentRoll;
	//Dice readyDice;
	//Dice heldDice;

	//std::vector<int> diceToHold;	
	//int indexToScore;
	//bool playerScored;
};