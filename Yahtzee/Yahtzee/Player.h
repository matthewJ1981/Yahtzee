#pragma once

#include <string>
#include "ScoreCard.h"
#include "Dice.h"
class Player
{
public:
	Player(std::string n);
	std::string Name() const { return name; }
	void TakeTurn();
	void RollDice(Dice& dice);
	bool HoldDie(int die);
	void ResetDice();
	
private:
	std::string name;
	ScoreCard scorecard;
	/*std::vector<Die> readyDice;
	std::vector<Die> heldDice;*/
	Dice readyDice;
	Dice heldDice;
	int numDice;
};