#include "LowerCategories.h"

#include <algorithm>
#include <vector>

int ThreeOfKind::CheckScore(const Dice& dice) const
{
	if (score > -1)
		return -1;

	int score = 0;

	std::vector<Die> d = dice.GetDice();
	std::sort(d.begin(), d.end(), [](const Die& a, const Die& b) {return a.Value() < b.Value(); });
	int previousValue = -1;
	int total = 0;

	std::for_each(d.begin(), d.end(), [&](const Die& die)
		{
			score += die.Value();

			int currentValue = die.Value();
			if (currentValue = previousValue)
				total++;
			else previousValue = currentValue;
		} );

	if (total >= 3)
		return score;
	else
		return 0;
}