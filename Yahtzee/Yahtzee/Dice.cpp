#include "Dice.h"
#include <algorithm>
#include <assert.h>

Dice::Dice(int numDice, int sides)
{
	for (int i = 0; i < numDice; ++i)
		dice.push_back(sides);
}

void Dice::AddDice(int sides, int value)
{
	dice.push_back({ sides, value });
}

void Dice::RemoveDice(int index)
{
	assert(index >= 0 && index < dice.size());

	dice.erase(dice.begin() + index);
}

void Dice::Roll()
{
	std::for_each(dice.begin(), dice.end(), [](Die& die) { die.Roll(); });
}

void Dice::Clear()
{
	dice.clear();
}


//const std::vector<int> Dice::Values() const
//{
//	std::vector<int> values;
//
//	for (const Die& d : dice)
//		values.push_back(d.Value());
//
//	return values;
//}
//
//
//std::ostream& operator<<(std::ostream& out, const Dice& d)
//{
//	for (const int& i : d.Values())
//	{
//		out << i << " ";
//	}
//
//	return out;
//}
