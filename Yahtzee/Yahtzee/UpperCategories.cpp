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

std::unique_ptr<Category> Ones::clone() const
{
	return std::make_unique<Ones>();
}

Twos::Twos() :
	Category("Twos")
{}

int Twos::CheckScore(const Dice& dice) const
{
	return UpperCheckScore(dice, 2);
}

std::unique_ptr<Category> Twos::clone() const
{
	return std::make_unique<Twos>();
}

Threes::Threes() :
	Category("Threes")
{}

int Threes::CheckScore(const Dice& dice) const
{
	return UpperCheckScore(dice, 3);
}

std::unique_ptr<Category> Threes::clone() const
{
	return std::make_unique<Threes>();
}

Fours::Fours() :
	Category("Fours")
{}

int Fours::CheckScore(const Dice& dice) const
{
	return UpperCheckScore(dice, 4);
}

std::unique_ptr<Category> Fours::clone() const
{
	return std::make_unique<Fours>();
}

Fives::Fives() :
	Category("Fives")
{}

int Fives::CheckScore(const Dice& dice) const
{
	return UpperCheckScore(dice, 5);
}

std::unique_ptr<Category> Fives::clone() const
{
	return std::make_unique<Fives>();
}

Sixes::Sixes() :
	Category("Sixes")
{}

int Sixes::CheckScore(const Dice& dice) const
{
	return UpperCheckScore(dice, 6);
}

std::unique_ptr<Category> Sixes::clone() const
{
	return std::make_unique<Sixes>();
}
