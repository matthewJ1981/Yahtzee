#pragma once

#include <vector>
#include "Sections.h"

class ScoreCard
{
public:

	//ScoreCard() : upper(nullptr), lower(nullptr), total(0)
	ScoreCard() : total(0), hasYahtzee(false), bonus(0)
	{
		//upper = new Upper();
		//lower = new Lower();
	}
	std::vector<std::pair<int, std::string>> CheckScore(const Dice& dice) const;

	std::vector<std::pair<int, std::string>> GetScores();
	void SetScore(int index, const Dice& dice);
	int Tally();
	void AddBonus() { bonus += 100; }
	int GetBonus() { return bonus; }

private:
	Upper upper;
	Lower lower;
	int total;
	int bonus;
	bool hasYahtzee = false;
};