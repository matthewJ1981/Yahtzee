#pragma once

#include <string>
#include "ScoreCard.h"
#include "Dice.h"

#include <iostream>
class Player
{
public:
	Player(std::string n);
	std::string Name() const { return name; }

	int Tally();
	//const ScoreCard& GetScoreCard() const { return scoreCard; }
	void SetScore(int index, const Dice& dice);
	std::vector<int> GetScores();
	std::vector<int> CheckScore(const Dice& dice) const;
	friend std::ostream& operator << (std::ostream& out, Player& player);
	
private:
	std::string name;
	ScoreCard scoreCard;
};