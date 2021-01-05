#include "Game.h"
#include "ScoreCard.h"
#include <algorithm>
#include <sstream>
//#include "C:\dev\include\util\input.h"
#include <util\input.h>

Game::Game() :
	roundCount(13),
	//playing(true),
	currentRound(1),
	currentPlayer(0),
	currentRoll(0),
	indexToScore(-1),
	playerScored(false)
{
	ResetDice();
}

void Game::Input()
{
	if (state == ROLLING)
	{

	}
	else if (state == ROLLED)
	{
		//After dice roll, choose hold[1] or score[2]
		//std::cin ...
		int choice = -1;
		if (!players[currentPlayer].Iscomputer())
		{
			std::string input;
			std::getline(std::cin, input);
			std::stringstream ss(input);
			ss >> choice;
		}
		else
		{
			; // Computer logic
		}

		if (choice == 1)
		{
			state = PREHOLD;
		}
		else if (choice == 2)
		{
			state = PRESCORE;
		}
		else
		{
			//;
		}
	}
	else if (state == HOLD)
	{

		std::string dice = util::input("");
		std::istringstream ss(dice);
		//std::vector<int> dNums;
		int diceNum = -1;
		while (ss >> diceNum)
		{
			if (diceNum >= 0 && diceNum < int(readyDice.size()))
			{
				diceToHold.push_back(diceNum);
			}
			else
			{
				diceToHold.clear();
				state = PREHOLD;
				break;
			}
		}

		if (diceToHold.empty())
			state = PREHOLD;

		std::sort(diceToHold.begin(), diceToHold.end());
	}
	else if (state == SCORE)
	{
		indexToScore = 0; //std::cin...

	}
}

void Game::Update()
{

	if (state == ROLLING)
	{
		IncrementRoll(); 
		readyDice.Roll();

		state = ROLLED;
	}
	else if (state == HOLD)
	{
		for (int i = 0; i < (int)diceToHold.size(); ++i)
		{
			readyDice[i].SetHeld(true);
		}

		for (int i = 0; i < (int)readyDice.size(); ++i)
			if (readyDice[i].IsHeld())
				heldDice.AddDice(readyDice[i]);


		for (int i = 0; i < readyDice.size(); ++i)
		{
			if (readyDice[i].IsHeld())
			{
				readyDice.RemoveDice(i);
				--i;
			}
		}

		diceToHold.clear();
	}
	else if (state == SCORE)
	{
		players[currentPlayer].SetScore(indexToScore, readyDice + heldDice);
		playerScored = true;
	}
}

void Game::Draw()
{
	if (state == ROLLED)
	{
		std::cout << "ReadyDice: " << readyDice << "\n";
		std::cout << "HeldDice: " << heldDice << "\n";

		if (currentRoll < 3)
			std::cout << "Choose dice to hold[1] or score[2]: ";
		else
			state = PRESCORE;
	}
	else if (state == PREHOLD)
	{
		std::cout << "Enter the numbers of the dice to hold: ";
		state = HOLD;
	}
	else if (state == PRESCORE)
	{
		std::cout << "Select a category to score: ";
		std::vector<int> scores = players[currentPlayer].CheckScore(readyDice + heldDice);
		for (size_t i = 0; i < scores.size(); ++i)
			std::cout << ScoreCard::EnumToString((int)i) << ": " << scores[i] << "\n";

		std::cout << "\n";
		state = SCORE;
	}
	else if (state == HOLD)
	{
		//std::cout << "ReadyDice: " << readyDice << "\n";
		std::cout << "HeldDice: " << heldDice << "\n";
		state = ROLLING;
	}
	else if (state == SCORE)
	{
		std::vector<int> scores = players[currentPlayer].GetScores();
		for (size_t i = 0; i < scores.size(); ++i)
			std::cout << ScoreCard::EnumToString((int)i) << ": " << scores[i] << "\n";
		state = ROLLING;
	}
}

bool Game::GameOver()
{
	//evaluate score and determine winner
	return currentRound > 13; // temporary
}
void Game::GetPlayers()
{

	int numPlayers = util::inputInt("How many players?");
	for (int i = 0; i < numPlayers; ++i)
	{
		if (util::inputChar("Is player " + std::to_string(i + 1) + " a person? ") == 'Y')
		{
			players.push_back({ util::input("Enter the player's name: "), false });
		}
	}
	std::cout << numPlayers << "\n";

	//players.push_back({ "Bob", false });
	//players.push_back({ "Tim", false });
}

void Game::IncrementRoll()
{
	currentRoll++;
	if (currentRoll > 3 || playerScored)
	{
		ResetDice();
		currentRoll = 1;
		currentPlayer++;
		playerScored = false;
	}

	if (currentPlayer > (int)players.size() - 1)
	{
		currentPlayer = 0;
		currentRound++;
	}

	std::cout << "Round: " << currentRound << "\n";
	std::cout << "Player: " << players[currentPlayer].Name() << "\n";
	std::cout << "Roll: " << currentRoll << "\n";
}

void Game::ResetDice()
{
	std::cout << "Reset\n";
	readyDice.Reset();
	heldDice.Clear();
	diceToHold.clear();
}