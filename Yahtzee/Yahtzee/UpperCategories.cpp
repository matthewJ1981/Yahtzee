#include "UpperCategories.h"

#include <algorithm>
#include <vector>

int Ones::CheckScore(const Dice& dice) const
{
	if (score > -1)
		return -1;

	int temp = 0;

	std::for_each(dice.begin(), dice.end(), [&](const Die& die) {if (die.Value() == 1) ++temp; });

	return temp;
}

int Twos::CheckScore(const Dice& dice) const
{
	if (score > -1)
		return -1;

	int temp = 0;

	std::for_each(dice.begin(), dice.end(), [&](const Die& die) {if (die.Value() == 2) temp += 2; });

	return temp;
}

int Threes::CheckScore(const Dice& dice) const
{
	if (score > -1)
		return -1;

	int temp = 0;

	std::for_each(dice.begin(), dice.end(), [&](const Die& die) {if (die.Value() == 3) temp += 3; });

	return temp;
}

int Fours::CheckScore(const Dice& dice) const
{
	if (score > -1)
		return -1;

	int temp = 0;

	std::for_each(dice.begin(), dice.end(), [&](const Die& die) {if (die.Value() == 4) temp += 4; });

	return temp;
}

int Fives::CheckScore(const Dice& dice) const
{
	if (score > -1)
		return -1;

	int temp = 0;

	std::for_each(dice.begin(), dice.end(), [&](const Die& die) {if (die.Value() == 5) temp += 5; });

	return temp;
}

int Sixes::CheckScore(const Dice& dice) const
{
	if (score > -1)
		return -1;

	int temp = 0;

	std::for_each(dice.begin(), dice.end(), [&](const Die& die) {if (die.Value() == 6) temp += 6; });

	return temp;
}