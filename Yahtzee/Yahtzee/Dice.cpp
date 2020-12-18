#include "Dice.h"
#include <algorithm>
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

void Dice::Roll()
{
	std::for_each(dice.begin(), dice.end(), [](Die& die) { die.Roll(); });
}

Dice Dice::YahtzeeDice()
{
	Dice dice;
	for(int i = 0; i < 5; ++i)
		dice.AddDice(6);
	return dice;
}

const std::vector<int> Dice::Values() const
{
	std::vector<int> values;
	for (const Die& d : dice)
		values.push_back(d.Value());
	return values;
}

void Dice::Clear()
{
	dice.clear();
}

std::ostream& operator<<(std::ostream& out, const Dice& d)
{
	for (const int& i : d.Values())
	{
		out << i << " ";
	}

	return out;
}