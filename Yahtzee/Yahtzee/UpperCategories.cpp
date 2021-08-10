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
//{
//	if (HasScored())
//		return UNSCORABLE;
//
//	int newScore = 0;
//
//	std::for_each(dice.begin(), dice.end(), [&](const Die& die) {if (die.Value() == 1) ++newScore; });
//
//	return newScore;
//}

Twos::Twos() :
	Category("Twos")
{}

int Twos::CheckScore(const Dice& dice) const
{
	return UpperCheckScore(dice, 2);
}
//{
//	if (HasScored())
//		return UNSCORABLE;
//
//	int newScore = 0;
//
//	std::for_each(dice.begin(), dice.end(), [&](const Die& die) {if (die.Value() == 2) newScore += 2; });
//
//	return newScore;
//}

Threes::Threes() :
	Category("Threes")
{}

int Threes::CheckScore(const Dice& dice) const
{
	return UpperCheckScore(dice, 3);
}
//{
//	if (HasScored())
//		return UNSCORABLE;
//
//	int newScore = 0;
//
//	std::for_each(dice.begin(), dice.end(), [&](const Die& die) {if (die.Value() == 3) newScore += 3; });
//
//	return newScore;
//}

Fours::Fours() :
	Category("Fours")
{}

int Fours::CheckScore(const Dice& dice) const
{
	return UpperCheckScore(dice, 4);
}
//{
//	if (HasScored())
//		return UNSCORABLE;
//
//	int newScore = 0;
//
//	std::for_each(dice.begin(), dice.end(), [&](const Die& die) {if (die.Value() == 4) newScore += 4; });
//
//	return newScore;
//}

Fives::Fives() :
	Category("Fives")
{}

int Fives::CheckScore(const Dice& dice) const
{
	return UpperCheckScore(dice, 5);
}
//{
//	if (HasScored())
//		return UNSCORABLE;
//
//	int newScore = 0;
//
//	std::for_each(dice.begin(), dice.end(), [&](const Die& die) {if (die.Value() == 5) newScore += 5; });
//
//	return newScore;
//}

Sixes::Sixes() :
	Category("Sixes")
{}

int Sixes::CheckScore(const Dice& dice) const
{
	return UpperCheckScore(dice, 6);
}
//{
//	if (HasScored())
//		return UNSCORABLE;
//
//	int newScore = 0;
//
//	std::for_each(dice.begin(), dice.end(), [&](const Die& die) {if (die.Value() == 6) newScore += 6; });
//
//	return newScore;
//}