#pragma once

#include <vector>
#include "Sections.h"

class ScoreCard
{
public:
	enum Category
	{
		ONES,
		TWOS,
		THREES,
		FOURS,
		FIVES,
		SIXES,
		THREEOFAKIND,
		FOUROFAKIND,
		FULLHOUSE,
		SMALLSTRAIGHT,
		LARGESTRAIGHT,
		YAHTZEE,
		CHANCE
	};
	//ScoreCard() : upper(nullptr), lower(nullptr), total(0)
	ScoreCard() : total(0)
	{
		//upper = new Upper();
		//lower = new Lower();
	}
	std::vector<std::pair<int, std::string>> CheckScore(const Dice& dice) const;

	std::vector<std::pair<int, std::string>> GetScores();
	void SetScore(int index, int score, bool yahtzeeBonus = false);
	int Tally();
private:
	Upper upper;
	Lower lower;
	int total;
};