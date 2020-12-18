#pragma once
#include <vector>
#include "Die.h"
#include <iostream>

class Dice
{
public:
	void AddDice(int s);
	void RemoveDice(int);
	void Roll();
	static Dice YahtzeeDice();
	const std::vector<int> Values() const;
	friend std::ostream& operator<< (std::ostream& out, const Dice& dice);
	void Clear();
private:
	std::vector<Die> dice;
};


