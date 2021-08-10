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
	static constexpr int BONUSTHRESHOLD = 63;
	static constexpr int BONUSVALUE = 35;
};

class Lower : public Section
{
public:
	Lower();
	void IncrementBonus() const { bonus += BONUSVALUE; }
	int Tally() override;
	bool BonusEligible() const { return categories[(int)LOWER::YAHTZEE]->Score() == YAHTZEEVALUE; }
	std::vector<int> CheckScores(const Dice& dice, std::vector<int> upperCategories) const;

	bool HasYahtzee() const { return yahtzee; }
	void SetHasYahtzee(bool b) const { yahtzee = b; }

	static int FullHouseValue() { return FULLHOUSEVALUE; }
	static int SmallStraightValue() { return SMALLSTRAIGHTVALUE; }
	static int LargeStraightValue() { return LARGESTRAUGHTVALUE; }
	static int YahtzeeValue() { return YAHTZEEVALUE; }
	static int BonusValue() { return BONUSVALUE; }

private:
	mutable bool yahtzee = false;
	static constexpr int FULLHOUSEVALUE = 25;
	static constexpr int SMALLSTRAIGHTVALUE = 30;
	static constexpr int LARGESTRAUGHTVALUE = 40;
	static constexpr int YAHTZEEVALUE = 50;
	static constexpr int BONUSVALUE = 100;
};


