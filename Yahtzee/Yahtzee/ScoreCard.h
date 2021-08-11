#pragma once

#include <vector>
#include "Sections.h"

class ScoreCard
{
public:
	ScoreCard() : total(0) {}
	std::vector<std::pair<std::string, int>> CheckScore(const Dice& dice) const;
	std::vector<int> GetScores() const;

	bool SetScore(int index, int score);
	int Tally();

	friend std::ostream& operator << (std::ostream& out, const ScoreCard& scoreCard);
private:
	Upper upper;
	Lower lower;
	int total;
};