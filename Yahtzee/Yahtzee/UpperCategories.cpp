#include "UpperCategories.h"

#include <algorithm>
#include <vector>

Ones::Ones() :
	Category("Ones")
{}

int Ones::CheckScore(const Dice& dice) const
{
	return UpperCheckScore(dice, 1);
}

Twos::Twos() :
	Category("Twos")
{}

int Twos::CheckScore(const Dice& dice) const
{
	return UpperCheckScore(dice, 2);
}

Threes::Threes() :
	Category("Threes")
{}

int Threes::CheckScore(const Dice& dice) const
{
	return UpperCheckScore(dice, 3);
}

Fours::Fours() :
	Category("Fours")
{}

int Fours::CheckScore(const Dice& dice) const
{
	return UpperCheckScore(dice, 4);
}

Fives::Fives() :
	Category("Fives")
{}

int Fives::CheckScore(const Dice& dice) const
{
	return UpperCheckScore(dice, 5);
}

Sixes::Sixes() :
	Category("Sixes")
{}

int Sixes::CheckScore(const Dice& dice) const
{
	return UpperCheckScore(dice, 6);
}
