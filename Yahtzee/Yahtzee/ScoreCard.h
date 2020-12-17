#pragma once

#include "Section.h"
#include "Sections.h"

class ScoreCard
{
public:
	ScoreCard() : upper(nullptr), lower(nullptr), total(0)
	{
		upper = new Upper();
		lower = new Lower();
	}
	void CheckScore(const std::vector<Die>& dice);
private:
	//CheckScore();
	//Tally() { total = upper + lower; return total; }
	Section* upper;
	Section* lower;
	int total;
};