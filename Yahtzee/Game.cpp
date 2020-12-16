#include "Game.h"
#include <iostream>
#include <random>
void Game::Intro()
{
	std::cout << "Welcome to Yahtzee.\n";
	char selection = Input("Solo (1) or Muiltplayer (2): ", { '1', '2' });

	if (selection == '1')
	{	
		AddPlayers(1);

		char selection = Input("Would you like to play against a computer opponent ? (y / n) : ", { 'Y', 'y', 'N', 'n' });
		if (selection == 'Y' || selection == 'y')
			_comOpponent = true;
		else
			_comOpponent = false;

		std::cerr << "ComOpp " << _comOpponent << "\n";
	}
	else
	{
		AddPlayers((int)Input("How many players? (2 - 4) : ", { '2', '3', '4' }) - 48);
	}
}

char Game::Input(std::string msg, std::vector<char> validInputs) const
{
	while (true)
	{
		std::cout << msg;
		char selection;
		std::cin >> selection;
		std::cin.ignore(1000, '\n');

		for (size_t i = 0; i < validInputs.size(); ++i)
		{
			if (selection == validInputs[i])
				return selection;
		}

		std::cout << "Invalid Input\n";
	}
}

void Game::AddPlayers(int numPlayers)
{
	for (int i = 1; i <= numPlayers; ++i)
	{
		std::cout << "Enter player " << i << " name: ";
		std::string name;
		std::cin >> name;
		_players.emplace_back(name);
	}
}

void Game::HighRoll()
{
	for (size_t i = 0; i < _players.size(); ++i)
	{
		;
	}
}

int Game::Roll()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> dist(1, 6);
	
	return dist(rng);
	//for (int i = 0; i < numDice; ++i)
	//{
	//	std::cout << dist(rng);
	//}
}
