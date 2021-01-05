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

	int Tally();
	void HoldDice(Dice& rD, Dice& hD, std::vector<int> dTM);
	void UnholdDice(Dice& rD, Dice& hD, std::vector<int> dTM);
	bool SetScore(int index, const Dice& dice);
	void RollDice(Dice& dice) const;
	void HoldOrReady(Dice& rD, Dice& hD);
	std::vector<int> GetDiceToMove(const Dice& dice) const;

	std::vector<int> GetScores();
	std::vector<int> CheckScore(const Dice& dice) const;


	std::string Name() const { return name; }
	bool Iscomputer() const { return isComputer; }

	friend std::ostream& operator << (std::ostream& out, Player& player);

private:
	std::string name;
	bool isComputer;
	ScoreCard scoreCard;
};