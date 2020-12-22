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
	//void TakeTurn();
	//void RollDice(Dice& dice);
	//bool HoldDie(int die);
	//void ResetDice();
	std::vector<int> CheckScore(const Dice& dice) const;
	int Tally();
	const ScoreCard& GetScoreCard() const { return scoreCard; }
	friend std::ostream& operator << (std::ostream& out, Player& player);
	void SetScore(int index, const Dice& dice);
	std::vector<int> GetScores();
	
private:
	std::string name;
	ScoreCard scoreCard;
};