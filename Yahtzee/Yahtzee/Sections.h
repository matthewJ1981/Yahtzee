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
	friend std::ostream& operator << (std::ostream& out, const Upper& upper);
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
	bool BonusEligible() const { return categories[(int)LOWER::YAHTZEE]->Score() == Yahtzee::ScoreValue(); }
	std::vector<std::pair<std::string, int>>CheckScores(const Dice& dice, const std::vector<std::pair<std::string, int>>& upperCategories) const;

	bool HasYahtzee() const { return yahtzee; }
	void SetHasYahtzee(bool b) const { yahtzee = b; }

	static int BonusValue() { return BONUSVALUE; }
	friend std::ostream& operator << (std::ostream& out, const Lower& lower);
private:
	mutable bool yahtzee = false;
	static constexpr int BONUSVALUE = 100;
};


