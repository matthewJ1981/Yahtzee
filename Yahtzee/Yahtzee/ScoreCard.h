#pragma once

#include <vector>
#include "Sections.h"

class ScoreCard
{
public:
	//ScoreCard() : upper(nullptr), lower(nullptr), total(0)
	ScoreCard() : total(0)
	{
		//upper = new Upper();
		//lower = new Lower();
	}
	std::vector<std::pair<int, std::string>> CheckScore(const Dice& dice) const;

	int Tally();
private:
	Upper upper;
	Lower lower;
	int total;
};