#pragma once
#include <vector>
#include "Die.h"
#include <iostream>

class Dice
{
public:
	Dice() {};
	Dice(int numDice, int sides = 6);

	void AddDice(int sides = 6, int value = 1);
	void RemoveDice(int index);
	void Roll();

	//const std::vector<int> Values() const;
	std::vector<Die> GetDice() const { return dice; }
	void Clear();

	//friend std::ostream& operator<< (std::ostream& out, const Dice& dice);

private:
	std::vector<Die> dice;
};


