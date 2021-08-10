#include "Game.h"
#include "ScoreCard.h"
#include <algorithm>
#include <sstream>
#include "util.h"

Game::Game() :
	currentRound(1),
	currentPlayer(0)
{
}

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

		for (const Die&  d : dice)
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

void Game::Go()
{
	std::cout << "Welcome to Yahtzee\n";
	GetPlayers();
	GetStartingPlayer();

	while (currentRound < totalRounds)
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

	while (currentRoll <= 3 && playerScored == false)
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

				//  MUST CHECK BOUNDS
				playerScored = player.SetScore(index, scores[index]);
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
