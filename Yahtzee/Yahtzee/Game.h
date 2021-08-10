#pragma once

#include <iostream>
#include <vector>
#include "Player.h"
#include "Dice.h"

class Game
{
public:
	Game();
	void Go();

private:
	void Turn(Player& player);
	void GetWinner();
	void GetPlayers();
	void GetStartingPlayer();

	std::vector<Player> players;

	int currentRound;
	int currentPlayer;
	static constexpr int totalRounds = 13;
};