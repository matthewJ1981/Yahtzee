#pragma once
#include <vector>
#include <algorithm>
#include "Die.h"

class Dice
{
public:
	void AddDice(int s);
	void RemoveDice(int);
	std::vector<Die> Roll();
private:
	std::vector<Die> dice;
};

