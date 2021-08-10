#include "Dice.h"
#include <algorithm>
#include <assert.h>

Dice::Dice(int numDice, int sides) : defaultSize(5), defaultSides(6)
{
	for (int i = 0; i < numDice; ++i)
		dice.push_back(sides);
}

void Dice::AddDice(const Die& d)
{
	dice.push_back(d);
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

void Dice::Reset()
{
	Clear();

	for (int i = 0; i < defaultSize; ++i)
		dice.push_back(Die());
}

Dice Dice::operator+(const Dice& rhs) const
{
	Dice d = *this;
	for (int i = 0; i < (int)rhs.size(); ++i)
		d.AddDice(rhs[i]);

	return d;
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
std::ostream& operator<<(std::ostream& out, const Dice& d)
{
	for (const Die& d : d.dice)
	{
		out << d << " ";
	}

	return out;
}
