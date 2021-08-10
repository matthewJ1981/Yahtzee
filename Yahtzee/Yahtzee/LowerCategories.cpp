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
	if (HasScored())
		return UNSCORABLE;

	int temp = 0;

	Dice tempDice = dice;
	std::sort(tempDice.begin(), tempDice.end());
	int previousValue = -1;
	int total = 1;
	bool threeOfKind = false;
	std::for_each(tempDice.begin(), tempDice.end(), [&](const Die& die)
		{
			temp += die.Value();

			int currentValue = die.Value();
			if (currentValue == previousValue)
				total++;
			else
			{
				total = 1;
				previousValue = currentValue;
			}

			if (total >= 3)
				threeOfKind = true;
		} );

	if (threeOfKind)
		return temp;
	else
		return 0;
}

int FourOfKind::CheckScore(const Dice& dice) const
{
	if (HasScored())
		return UNSCORABLE;

	int temp = 0;

	Dice tempDice = dice;
	std::sort(tempDice.begin(), tempDice.end(), [](const Die& a, const Die& b) {return a.Value() < b.Value(); });
	int previousValue = -1;
	int total = 1;
	bool fourOfKind = false;
	std::for_each(tempDice.begin(), tempDice.end(), [&](const Die& die)
		{
			temp += die.Value();

			int currentValue = die.Value();
			if (currentValue == previousValue)
				total++;
			else
			{
				total = 1;
				previousValue = currentValue;
			}

			if (total >= 4)
				fourOfKind = true;
		});

	if (fourOfKind)
		return temp;
	else
		return 0;
}

int FullHouse::CheckScore(const Dice& dice) const
{
	if (HasScored())
		return UNSCORABLE;

	int temp = 0;

	Dice tempDice = dice;
	std::sort(tempDice.begin(), tempDice.end(), [](const Die& a, const Die& b) {return a.Value() < b.Value(); });
	int previousValue = -1;

	int numDice = (int)tempDice.size();
	int total[5] = { 1, 1, 1, 1, 1 };
	int currentTotal = -1;

	for(int i = 0; i < numDice; ++i)
	{
		int currentValue = tempDice[i].Value();
		if (currentValue == previousValue)
		{
			total[currentTotal]++;
		}
		else
		{
			currentTotal++;
			previousValue = currentValue;
		}	
	};

	if ((total[0] >= 2 && total[1] >= 3) || (total[0] >= 3 && total[1] >= 2))
		return 25;
	else
		return 0;
}

int SmallStraight::CheckScore(const Dice& dice) const
{
	if (HasScored())
		return UNSCORABLE;

	Dice tempDice = dice;
	std::sort(tempDice.begin(), tempDice.end(), [](const Die& a, const Die& b) {return a.Value() < b.Value(); });
	int previousValue = -1;

	int total = 1;
	bool smStraight = false;
	std::for_each(tempDice.begin(), tempDice.end(), [&](const Die& die)
		{
			int currentValue = die.Value();
			if (currentValue != previousValue)
			{
				if (currentValue == previousValue + 1)
				{
					total++;
					previousValue++;
				}
				else
				{
					total = 1;
					previousValue = currentValue;
				}

				if (total >= 4)
					smStraight = true; 
			}
		});

	if (smStraight)
		return 30;
	else
		return 0;
}

int LargeStraight::CheckScore(const Dice& dice) const
{
	if (HasScored())
		return UNSCORABLE;

	Dice tempDice = dice;
	std::sort(tempDice.begin(), tempDice.end(), [](const Die& a, const Die& b) {return a.Value() < b.Value(); });
	int previousValue = -1;

	int total = 1;
	bool lrgStraight = false;
	std::for_each(tempDice.begin(), tempDice.end(), [&](const Die& die)
		{
			int currentValue = die.Value();
			if (currentValue != previousValue)
			{
				if (currentValue == previousValue + 1)
				{
					previousValue++;
					total++;
				}
				else
				{
					total = 1;
					previousValue = currentValue;
				}

				if (total == 5)
					lrgStraight = true;
			}
		});

	if (lrgStraight)
		return 40;
	else
		return 0;
}

int Yahtzee::CheckScore(const Dice& dice) const
{
	int value = dice[0].Value();
	for (const auto d : dice)
		if (d.Value() != value)
			return 0;

	return 50;
}

int Chance::CheckScore(const Dice& dice) const
{
	if (HasScored())
		return UNSCORABLE;

	int temp = 0;
	for (const auto& d : dice)
		temp += d.Value();

	return temp;
}