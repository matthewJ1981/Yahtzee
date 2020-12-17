#include "UpperCategories.h"

#include <algorithm>

int Ones::CheckScore(const std::vector<Die>& dice)
{
	if (score > -1)
		return -1;

	int score = 0;
	std::for_each(dice.begin(), dice.end(), [&](const Die& die) {if (die.Value() == 1) ++score; });

	//std::cout << "Score: " << score << "\n";
	//std::cout << "Score: " << this->score << "\n";
	return score;
}