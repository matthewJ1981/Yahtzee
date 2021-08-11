#include "LowerCategories.h"

#include <algorithm>
#include <vector>

ThreeOfKind::ThreeOfKind()
	:
	Category("Three of a kind")
{}

FourOfKind::FourOfKind()
	:
	Category("Four of a kind")
{}

FullHouse::FullHouse()
	:
	Category("Full house")
{}

SmallStraight::SmallStraight()
	:
	Category("Small straight")
{}

LargeStraight::LargeStraight()
	:
	Category("Large straight")
{}

Yahtzee::Yahtzee()
	:
	Category("Yahtzee")
{}

Chance::Chance()
	:
	Category("Chance")
{}

int ThreeOfKind::CheckScore(const Dice& dice) const
{
	return KindScore(dice, 3);
}

int FourOfKind::CheckScore(const Dice& dice) const
{
	return KindScore(dice, 4);
}

int FullHouse::CheckScore(const Dice& dice) const
{
	if (Scored())
		return UNSCORABLE;

	bool twoKind = false;
	bool threeKind = false;

	int values[7]{ 0 };
	for (const auto& d : dice)
		++values[d.Value()];

	for (int i = 1; i < 7; ++i)
	{
		if (values[i] >= 3)
			threeKind = true;
		if (values[i] >= 2)
			twoKind = true;
	}

	if (twoKind && threeKind)
		return ScoreValue();
	else
		return 0;
}

int SmallStraight::CheckScore(const Dice& dice) const
{
	if (Scored())
		return UNSCORABLE;

	if (StraightScore(dice, 4))
		return ScoreValue();

	return 0;
}

int LargeStraight::CheckScore(const Dice& dice) const
{
	if (Scored())
		return UNSCORABLE;

	if (StraightScore(dice, 5))
		return ScoreValue();

	return 0;
}

int Yahtzee::CheckScore(const Dice& dice) const
{
	int value = dice[0].Value();
	for (const auto& d : dice)
		if (d.Value() != value)
			return 0;

	return 50;
}

int Chance::CheckScore(const Dice& dice) const
{
	if (Scored())
		return UNSCORABLE;

	int temp = 0;
	for (const auto& d : dice)
		temp += d.Value();

	return temp;
}