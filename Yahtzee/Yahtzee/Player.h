#pragma once

#include <string>
#include "ScoreCard.h"

class Player
{
public:
	Player(std::string n);
	std::string Name() const { return name; }
	void TakeTurn();
	void RollDice();
	bool HoldDie(int die);
	void ResetDice();
private:
	std::string name;
	ScoreCard scorecard;
	std::vector<Die> readyDice;
	std::vector<Die> heldDice;
	int numDice;
};