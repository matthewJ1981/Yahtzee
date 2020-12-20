#include "Sections.h"

int Upper::Tally()
{
	CalcSubTotal();
	if (subtotal >= 63)
		bonus = 35;

	total = subtotal + bonus;
	return total;
}

int Lower::Tally()
{
	CalcSubTotal();
	total = subtotal + bonus;
	return total;
}

// This overridden method exists to enforce scoring options on successive yahtzees
std::vector<std::pair<int, std::string>> Lower::CheckScores(const Dice& dice, std::vector<std::pair<int, std::string>> upperCategories) const
{
	std::vector<std::pair<int, std::string>> scores = Section::CheckScores(dice);

	// Currently rolled a yahtzee
	if (scores[5].first == 50)
	{
		// Already scored a yahtzee so show bonus as scoring option
		if (categories[5]->Score() == 50)	
			scores.push_back(std::make_pair(100, "Bonus"));

		//Force scoring of upper section or allow options of lower per joker rules
		if (categories[5]->Score() == 50 || categories[5]->Score() == 0)
		{
			int upperIndex = dice.GetDice()[0].Value() - 1;

			if (upperCategories[upperIndex].first == -1)
			{
				if (scores[2].first != -1)
					scores[2].first = 25;

				if (scores[3].first != -1)
					scores[3].first = 30;

				if (scores[4].first != -1)
					scores[4].first = 40;
			}
			else
			{
				scores[0].first = -1;
				scores[1].first = -1;
				scores[2].first = -1;
				scores[3].first = -1;
				scores[4].first = -1;
				scores[5].first = -1;
				scores[6].first = -1;
			}
		}
	}

	return scores;
}
