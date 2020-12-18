#include "UpperCategories.h"

#include <algorithm>
#include <vector>

int Ones::CheckScore(const Dice& dice) const
{
	if (score > -1)
		return -1;

	int score = 0;

	std::vector<Die> d = dice.GetDice();
	std::for_each(d.begin(), d.end(), [&](const Die& die) {if (die.Value() == 1) ++score; });

	return score;
}

int Twos::CheckScore(const Dice& dice) const
{
	return 0;
}

int Threes::CheckScore(const Dice& dice) const
{
	return 0;
}

int Fours::CheckScore(const Dice& dice) const
{
	return 0;
}

int Fives::CheckScore(const Dice& dice) const
{
	return 0;
}

int Sixes::CheckScore(const Dice& dice) const
{
	return 0;
}