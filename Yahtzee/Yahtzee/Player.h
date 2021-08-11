#pragma once

#include <string>
#include "ScoreCard.h"
#include "Dice.h"
#include <vector>

#include <iostream>
class Player
{
public:
	Player(std::string n, bool c);

	void TakeTurn();
	void MoveDice(Dice& lhs, Dice& rhs, std::vector<int>& indices);

	int Roll();
	void Hold();
	void Unhold();
	std::vector<int> GetDiceToMove(const Dice& dice) const;
	bool Score();

	std::string Name() const { return name; }
	bool Iscomputer() const { return isComputer; }

	int Tally() { return scoreCard.Tally(); }

	void Print();
	friend std::ostream& operator << (std::ostream& out, Player& player);

private:
	std::string name;
	bool isComputer;
	ScoreCard scoreCard;
	Dice rollable;
	Dice held;
};