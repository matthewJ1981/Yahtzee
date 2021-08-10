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