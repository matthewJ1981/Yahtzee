#include "Category.h"
#include <algorithm>

Category::Category(std::string n) 
	:
	score(-1),
	name(n) 
{}

int Category::UpperCheckScore(const Dice& dice, int value) const
{
	if (HasScored())
		return UNSCORABLE;

	int newScore = 0;

	std::for_each(dice.begin(), dice.end(), [&](const Die& die) {if (die.Value() == value) newScore += value; });

	return newScore;
}

int Category::KindScore(const Dice& dice, int numSame) const
{
	if (HasScored())
		return UNSCORABLE;

	int newScore = 0;

	int values[7]{ 0 };
	for (const auto& d : dice)
	{
		++values[d.Value()];
		newScore += d.Value();
	}

	for (int i = 1; i < 7; ++i)
		if (values[i] >= numSame)
			return newScore;

	return 0;
}

bool Category::StraightScore(const Dice& dice, int numConsec) const
{
	if (HasScored())
		return UNSCORABLE;

	int numConsecutive = 0;
	int maxConsecutive = 0;
	int values[7]{ 0 };
	for (const auto& d : dice)
		++values[d.Value()];

	for (int i = 1; i < 7; ++i)
	{
		if (values[i])
		{
			++numConsecutive;
		}
		else
		{
			if (numConsecutive > maxConsecutive)
				maxConsecutive = numConsecutive;
			numConsecutive = 0;
		}
	}

	return maxConsecutive >= numConsec;
}
