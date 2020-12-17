#pragma once

#include <vector>

#include "Player.h"

class Game
{
public:
	Game()
	{
	}
	void Play()
	{
		for (int i = 0; i < 13; ++i)
			for (size_t j = 0; j < players.size(); ++j)
				players[j].TakeTurn();
	}
	void GetPlayers()
	{
		players.push_back({ "Bob" });
		players.push_back({ "Tim" });
	}
private:
	std::vector<Player> players;
};