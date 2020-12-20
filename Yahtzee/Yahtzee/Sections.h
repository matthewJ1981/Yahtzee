#pragma once

#include "Section.h"
#include "UpperCategories.h"
#include "LowerCategories.h"
#include "categoryEnums.h"

class Upper : public Section
{
public:
	Upper();

	int Tally() override;
private:
};

class Lower : public Section
{
public:
	Lower();
	void IncrementBonus() { bonus += 100; }
	int Tally() override;
	bool BonusEligibile() const { return categories[(int)LOWER::YAHTZEE]->Score() == 50; }
	std::vector<int> CheckScores(const Dice& dice, std::vector<int> upperCategories) const;
private:

};


