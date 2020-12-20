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
	if (score > -1)
		return -1;

	int score = 0;

	std::vector<Die> d = dice.GetDice();
	std::for_each(d.begin(), d.end(), [&](const Die& die) {if (die.Value() == 2) score += 2; });

	return score;
}

int Threes::CheckScore(const Dice& dice) const
{
	if (score > -1)
		return -1;

	int score = 0;

	std::vector<Die> d = dice.GetDice();
	std::for_each(d.begin(), d.end(), [&](const Die& die) {if (die.Value() == 3) score += 3; });

	return score;
}

int Fours::CheckScore(const Dice& dice) const
{
	if (score > -1)
		return -1;

	int score = 0;

	std::vector<Die> d = dice.GetDice();
	std::for_each(d.begin(), d.end(), [&](const Die& die) {if (die.Value() == 4) score += 4; });

	return score;
}

int Fives::CheckScore(const Dice& dice) const
{
	if (score > -1)
		return -1;

	int score = 0;

	std::vector<Die> d = dice.GetDice();
	std::for_each(d.begin(), d.end(), [&](const Die& die) {if (die.Value() == 5) score += 5; });

	return score;
}

int Sixes::CheckScore(const Dice& dice) const
{
	if (score > -1)
		return -1;

	int score = 0;

	std::vector<Die> d = dice.GetDice();
	std::for_each(d.begin(), d.end(), [&](const Die& die) {if (die.Value() == 6) score += 6; });

	return score;
}