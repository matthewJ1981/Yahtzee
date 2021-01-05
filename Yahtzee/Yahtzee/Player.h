#pragma once

#include <string>
#include "ScoreCard.h"
#include "Dice.h"

#include <iostream>
class Player
{
public:
	Player(std::string n, bool c);
	std::string Name() const { return name; }
	bool Iscomputer() const { return isComputer; }
	int Tally();
	//const ScoreCard& GetScoreCard() const { return scoreCard; }
	void SetScore(int index, const Dice& dice);
	std::vector<int> GetScores();
	std::vector<int> CheckScore(const Dice& dice) const;
	friend std::ostream& operator << (std::ostream& out, Player& player);
	
private:
	std::string name;
	bool isComputer;
	ScoreCard scoreCard;
};