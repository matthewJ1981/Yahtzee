#pragma once

#include <vector>
#include "Sections.h"

class ScoreCard
{
public:
	ScoreCard() : total(0){}
	std::vector<std::pair<std::string, int>> CheckScore(const Dice& dice) const;
	std::vector<int> GetScores() const;

	bool SetScore(int index, int score);
	int Tally();
	static std::string EnumToString(int cat)
	{
		switch ((int)cat)
		{
		case 0:		return "Ones";
		case 1:		return "Twos";
		case 2:		return "Threes";
		case 3:		return "Fours";
		case 4:		return "Fives";
		case 5:		return "Sixes";
		case 6:		return "Three of a Kind";
		case 7:		return "Four of a Kind";
		case 8:		return "Full House";
		case 9:		return "Small Straight";
		case 10:	return "Large Straight";
		case 11:	return "Yahtzee";
		case 12:	return "Chance";
		default:
			return "";
		}
	}

	friend std::ostream& operator << (std::ostream& out, const ScoreCard& scoreCard);
private:
	Upper upper;
	Lower lower;
	int total;
};