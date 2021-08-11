#include "Game.h"
#include "ScoreCard.h"
#include <algorithm>
#include <sstream>
#include "util.h"

Game::Game() :
	currentRound(1),
	currentPlayer(0)
{}

void Game::GetPlayers()
{
	int numPlayers = util::Input("How many players? ", 1, 10);

	for (int i = 0; i < numPlayers; ++i)
	{
		std::string name = util::input("Enter player " + std::to_string(i + 1) + "'s name: ");
		bool isComputer = util::Input("Is " + name + " a computer? ") == 'Y';
		players.push_back({ name, isComputer });
	}
}

void Game::GetStartingPlayer()
{
	int max = 0;
	size_t first = 0;

	std::cout << "\n** Automatically rolling to see who goes first **\n\n";
	for (size_t i = 0; i < players.size(); ++i)
	{
		int score = players[i].Roll();

		std::cout << players[i].Name() << " rolled  " << score << "\n";
		if (score > max)
		{
			max = score;
			first = i;
		}
	}

	std::cout << "\n" << players[first].Name() << " goes first\n\n";
	std::swap(players[0], players[first]);
}

void Game::Go()
{
	std::cout << "**** Welcome to Yahtzee ****\n\n";
	GetPlayers();
	GetStartingPlayer();

	while (currentRound <= totalRounds)
	{
		std::cout << "\n** Round: " << currentRound << " **\n";
		for (Player player : players)
			player.TakeTurn();

		++currentRound;
	}

	GetWinner();
	std::cout << "\n**** Thanks for playing. ****\n";
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
