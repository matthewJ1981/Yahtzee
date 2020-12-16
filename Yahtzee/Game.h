#pragma once
#include <vector>
#include <string>
#include "Player.h"

class Game
{
	bool _comOpponent;
	int currentPlayer;
	std::vector<Player> _players;
public:
	void Intro();
	char Input(std::string msg, std::vector<char> validInputs) const;
	void AddPlayers(int numPlayers);
	void HighRoll();
	int Roll();
};

