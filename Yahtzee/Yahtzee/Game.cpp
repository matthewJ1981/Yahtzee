#include "Game.h"
#include "ScoreCard.h"
#include <algorithm>
#include <sstream>
#include "util.h"

Game::Game() :
	//roundCount(13),
	//playing(true),
	currentRound(1),
	currentPlayer(0)
	//currentRoll(0),
	//indexToScore(-1),
	//playerScored(false)
{
	//ResetDice();
}
//
//void Game::Input()
//{
//	if (state == ROLLING)
//	{
//
//	}
//	else if (state == ROLLED)
//	{
//		//After dice roll, choose hold[1] or score[2]
//		//std::cin ...
//		int choice = -1;
//		if (!players[currentPlayer].Iscomputer())
//		{
//			std::string input;
//			std::getline(std::cin, input);
//			std::stringstream ss(input);
//			ss >> choice;
//		}
//		else
//		{
//			; // Computer logic
//		}
//
//		if (choice == 1)
//		{
//			state = PREHOLD;
//		}
//		else if (choice == 2)
//		{
//			state = PRESCORE;
//		}
//		else
//		{
//			//;
//		}
//	}
//	else if (state == HOLD)
//	{
//
//		std::string dice = util::input("");
//		std::istringstream ss(dice);
//		//std::vector<int> dNums;
//		int diceNum = -1;
//		while (ss >> diceNum)
//		{
//			if (diceNum >= 0 && diceNum < int(readyDice.size()))
//			{
//				diceToHold.push_back(diceNum);
//			}
//			else
//			{
//				diceToHold.clear();
//				state = PREHOLD;
//				break;
//			}
//		}
//
//		if (diceToHold.empty())
//			state = PREHOLD;
//
//		std::sort(diceToHold.begin(), diceToHold.end());
//	}
//	else if (state == SCORE)
//	{
//		indexToScore = 0; //std::cin...
//
//	}
//}
//
//void Game::Update()
//{
//
//	if (state == ROLLING)
//	{
//		IncrementRoll(); 
//		readyDice.Roll();
//
//		state = ROLLED;
//	}
//	else if (state == HOLD)
//	{
//		for (int i = 0; i < (int)diceToHold.size(); ++i)
//		{
//			readyDice[i].SetHeld(true);
//		}
//
//		for (int i = 0; i < (int)readyDice.size(); ++i)
//			if (readyDice[i].IsHeld())
//				heldDice.AddDice(readyDice[i]);
//
//
//		for (int i = 0; i < readyDice.size(); ++i)
//		{
//			if (readyDice[i].IsHeld())
//			{
//				readyDice.RemoveDice(i);
//				--i;
//			}
//		}
//
//		diceToHold.clear();
//	}
//	else if (state == SCORE)
//	{
//		players[currentPlayer].SetScore(indexToScore, readyDice + heldDice);
//		playerScored = true;
//	}
//}
//
//void Game::Draw()
//{
//	if (state == ROLLED)
//	{
//		std::cout << "ReadyDice: " << readyDice << "\n";
//		std::cout << "HeldDice: " << heldDice << "\n";
//
//		if (currentRoll < 3)
//			std::cout << "Choose dice to hold[1] or score[2]: ";
//		else
//			state = PRESCORE;
//	}
//	else if (state == PREHOLD)
//	{
//		std::cout << "Enter the numbers of the dice to hold: ";
//		state = HOLD;
//	}
//	else if (state == PRESCORE)
//	{
//		std::cout << "Select a category to score: ";
//		std::vector<int> scores = players[currentPlayer].CheckScore(readyDice + heldDice);
//		for (size_t i = 0; i < scores.size(); ++i)
//			std::cout << ScoreCard::EnumToString((int)i) << ": " << scores[i] << "\n";
//
//		std::cout << "\n";
//		state = SCORE;
//	}
//	else if (state == HOLD)
//	{
//		//std::cout << "ReadyDice: " << readyDice << "\n";
//		std::cout << "HeldDice: " << heldDice << "\n";
//		state = ROLLING;
//	}
//	else if (state == SCORE)
//	{
//		std::vector<int> scores = players[currentPlayer].GetScores();
//		for (size_t i = 0; i < scores.size(); ++i)
//			std::cout << ScoreCard::EnumToString((int)i) << ": " << scores[i] << "\n";
//		state = ROLLING;
//	}
//}
//
//bool Game::GameOver()
//{
//	//evaluate score and determine winner
//	return currentRound > 13; // temporary
//}
void Game::GetPlayers()
{
	int numPlayers = util::inputInt("How many players?");

	for (int i = 0; i < numPlayers; ++i)
	{
		std::string name = util::input("Enter the player's name: ");
		bool isComputer = util::inputChar("Is " + name + " a computer? ");
			players.push_back({ name, isComputer });
	}

	std::cerr << numPlayers << "\n";
}

void Game::GetStartingPlayer()
{
	int max = 0;
	int first = -1;

	std::cout << "Rolling to see who goes first\n";
	for (size_t i = 0; i < players.size(); ++i)
	{
		int score = 0;

		Dice dice(5);
		players[i].RollDice(dice);

		for (Die d : dice)
			score += d.Value();

		std::cout << players[i].Name() << ": " << score << "\n";
		if (score > max)
		{
			max = score;
			first = int(i);
		}
	}

	std::cout << players[first].Name() << " goes first\n";
	std::swap(players[0], players[first]);
}
//void Game::IncrementRoll()
//{
//	currentRoll++;
//	if (currentRoll > 3 || playerScored)
//	{
//		ResetDice();
//		currentRoll = 1;
//		currentPlayer++;
//		playerScored = false;
//	}
//
//	if (currentPlayer > (int)players.size() - 1)
//	{
//		currentPlayer = 0;
//		currentRound++;
//	}
//
//	std::cout << "Round: " << currentRound << "\n";
//	std::cout << "Player: " << players[currentPlayer].Name() << "\n";
//	std::cout << "Roll: " << currentRoll << "\n";
//}

//void Game::ResetDice()
//{
//	std::cout << "Reset\n";
//	readyDice.Reset();
//	heldDice.Clear();
//	diceToHold.clear();
//}

void Game::Go()
{
	std::cout << "Welcome to Yahtzee\n";
	GetPlayers();
	GetStartingPlayer();

	while (currentRound < 2)
	{
		std::cout << "Round: " << currentRound << "\n";
		for (Player p : players)
		{
			std::cout << "Player: " << p.Name() << "\n";
			Turn(p);
		}

		++currentRound;
	}

	GetWinner();
	std::cout << "Thanks for playing.\n";
}

void Game::Turn(Player& player)
{
	Dice readyDice(5);
	Dice heldDice;
	bool playerScored = false;
	//heldDice.Clear();

	int currentRoll = 1;

	while (currentRoll < 4 && playerScored == false)
	{
		player.RollDice(readyDice);

		std::cout << "ReadyDice: " << readyDice << "\n";
		std::cout << "HeldDice: " << heldDice << "\n";
		//player.CheckScore(readyDice + heldDice);

		bool inputting = true;
		while (inputting)
		{
			inputting = false;
			int choice = -1;
			if (currentRoll < 3)
				choice = util::inputInt("Hold(1), Score(2), or Roll Again(3)");
			else
				choice = 2;

			if (choice == 1)
			{
				player.HoldOrReady(readyDice, heldDice);
			}
			else if (choice == 2)
			{
				std::cout << "Scoring options\n";
				std::vector<int> scores = player.CheckScore(readyDice + heldDice);
				for (size_t i = 0; i < scores.size(); ++i)
					std::cout << i << ": " << ScoreCard::EnumToString((int)i) << ": " << scores[i] << "\n";
				std::cout << "\n";
				int index = util::inputInt("Select category to score: ");

				playerScored = player.SetScore(index, readyDice + heldDice);
			}
			else if (choice == 3)
			{
				;
			}
			else
			{
				inputting = true;
				std::cout << "Invalid input\n";
			}
		}

		++currentRoll;
	}
}

void Game::GetWinner()
{
	int max = 0;
	int index = -1;

	for (size_t i = 0; i < players.size(); ++i)
	{
		int score = players[i].Tally();
		std::cout << players[i] << "\n";
		if (score > max)
		{
			max = score;
			index = int(i);
		}
	}

	std::cout << players[index].Name() << " is the winner.\n";
}
