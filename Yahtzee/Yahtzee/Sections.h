#pragma once

#include "Section.h"
#include "UpperCategories.h"
#include "LowerCategories.h"
#include "categoryEnums.h"

class Upper : public Section
{
public:
	Upper()
	{
		categories.push_back(new Ones("Ones"));
		categories.push_back(new Twos("Twos"));
		categories.push_back(new Threes("Threes"));
		categories.push_back(new Fours("Fours"));
		categories.push_back(new Fives("Fives"));
		categories.push_back(new Sixes("Sixes"));
	}

	int Tally() override;
private:
};

class Lower : public Section
{
public:
	Lower()
	{
		categories.push_back(new ThreeOfKind("Three of a Kind"));
		categories.push_back(new FourOfKind("Four of a Kind"));
		categories.push_back(new FullHouse("Full House"));
		categories.push_back(new SmallStraight("Small Straight"));
		categories.push_back(new LargeStraight("Large Straight"));
		categories.push_back(new Yahtzee("Yahtzee"));
		categories.push_back(new Chance("Chance"));
	};
	void IncrementBonus() { bonus += 100; }
	int Tally() override;
	bool BonusEligibile() const { return categories[(int)LOWER::YAHTZEE]->Score() == 50; }
	std::vector<std::pair<int, std::string>> CheckScores(const Dice& dice, std::vector<std::pair<int, std::string>> upperCategories) const;
private:

};


