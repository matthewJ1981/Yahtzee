#include "LowerCategories.h"

#include <algorithm>
#include <vector>

ThreeOfKind::ThreeOfKind()
	:
	Category("Three of a kind")
{}

int ThreeOfKind::CheckScore(const Dice& dice) const
{
	return KindScore(dice, 3);
}

std::unique_ptr<Category> ThreeOfKind::clone() const
{
	return std::make_unique<ThreeOfKind>();
}

FourOfKind::FourOfKind()
	:
	Category("Four of a kind")
{}

int FourOfKind::CheckScore(const Dice& dice) const
{
	return KindScore(dice, 4);
}

std::unique_ptr<Category> FourOfKind::clone() const
{
	return std::make_unique<FourOfKind>();
}

FullHouse::FullHouse()
	:
	Category("Full house")
{}

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

std::unique_ptr<Category> FullHouse::clone() const
{
	return std::make_unique<FullHouse>();
}

SmallStraight::SmallStraight()
	:
	Category("Small straight")
{}

int SmallStraight::CheckScore(const Dice& dice) const
{
	if (Scored())
		return UNSCORABLE;

	if (StraightScore(dice, 4))
		return ScoreValue();

	return 0;
}

std::unique_ptr<Category> SmallStraight::clone() const
{
	return std::make_unique<SmallStraight>();
}

LargeStraight::LargeStraight()
	:
	Category("Large straight")
{}

int LargeStraight::CheckScore(const Dice& dice) const
{
	if (Scored())
		return UNSCORABLE;

	if (StraightScore(dice, 5))
		return ScoreValue();

	return 0;
}

std::unique_ptr<Category> LargeStraight::clone() const
{
	return std::make_unique<LargeStraight>();
}

Yahtzee::Yahtzee()
	:
	Category("Yahtzee")
{}

int Yahtzee::CheckScore(const Dice& dice) const
{
	int value = dice[0].Value();
	for (const auto& d : dice)
		if (d.Value() != value)
			return 0;

	return 50;
}

std::unique_ptr<Category> Yahtzee::clone() const
{
	return std::make_unique<Yahtzee>();
}

Chance::Chance()
	:
	Category("Chance")
{}

int Chance::CheckScore(const Dice& dice) const
{
	if (Scored())
		return UNSCORABLE;

	int temp = 0;
	for (const auto& d : dice)
		temp += d.Value();

	return temp;
}

std::unique_ptr<Category> Chance::clone() const
{
	return std::make_unique<Chance>();
}
