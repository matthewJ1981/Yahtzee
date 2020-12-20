#pragma once

#include "Section.h"
#include "UpperCategories.h"
#include "LowerCategories.h"

class Upper : public Section
{
public:
	Upper()
	{
		categories.push_back(new Ones("Ones"));
	}

	//std::vector<std::pair<int, std::string>> CheckScores(const Dice& dice) const override;
	int Tally() override;
private:
};

class Lower : public Section
{
public:
	Lower()
	{
		categories.push_back(new ThreeOfKind("Three of a Kind"));
	};
	void IncrementBonus() { bonus += 100; }
	int Tally() override;
	bool BonusEligibile() const { return bonusEligible; }
	void SetBonusEligible(bool b) { bonusEligible = b; }
	/*std::vector<std::pair<int, std::string>> CheckScores(const Dice& dice) const override*/
	std::vector<std::pair<int, std::string>> CheckScores(const Dice& dice, std::vector<std::pair<int, std::string>> upperCategories) const;
private:
	bool bonusEligible = false;
};


