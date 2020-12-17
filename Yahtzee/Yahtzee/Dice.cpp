#include "Dice.h"

void Dice::AddDice(int s)
{
	dice.push_back(s);
}

void Dice::RemoveDice(int i)
{
	if (i < 0 || i >= dice.size())
		throw std::exception("Index out of bounds");
	dice.erase(dice.begin() + i);
}

std::vector<Die> Dice::Roll()
{
	std::for_each(dice.begin(), dice.end(), [](Die& die) { die.Roll(); });
	return dice;
}
