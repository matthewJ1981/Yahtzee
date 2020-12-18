#include "UpperCategories.h"

#include <algorithm>

int Ones::CheckScore(const Dice& dice) const
{
	if (score > -1)
		return -1;

	int score = 0;
	std::for_each(dice.GetDice().begin(), dice.GetDice().end(), [&](const Die& die) {if (die.Value() == 1) ++score; });

	//std::cout << "Score: " << score << "\n";
	//std::cout << "Score: " << this->score << "\n";
	return score;
}