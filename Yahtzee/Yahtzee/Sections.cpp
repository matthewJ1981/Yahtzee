#include "Sections.h"
//#include <tuple>

int Upper::Tally()
{
	if (subtotal >= 63)
		bonus = 35;

	total = subtotal + bonus;
	return total;
}
//
//std::vector<std::pair<int, std::string>> Upper::CheckScores(const Dice& dice) const
//{
//	return Section::CheckScores(dice);
//}

std::vector<std::pair<int, std::string>> Lower::CheckScores(const Dice& dice, std::vector<std::pair<int, std::string>> upperCategories) const
{
	std::vector<std::pair<int, std::string>> scores = Section::CheckScores(dice);

	if (scores[6].first == 50)
	{
		if (categories[6]->Score() == 50)
		{
			scores.push_back(std::make_pair(100, "Bonus"));
		}

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
	}

	return scores;
}

int Lower::Tally()
{
	total = subtotal + bonus;
	return total;
}
