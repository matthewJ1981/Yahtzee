#pragma once
#include <vector>
#include <iterator>
#include "Die.h"
#include <iostream>

class Dice
{
public:
	explicit Dice(int numDice = 0, int sides = 6);

	//void AddDice(int sides = 6, int value = 1);
	void AddDice(const Die& d);
	void RemoveDice(int index);
	void Roll();
	int size() const { return (int)dice.size(); }
	bool empty() const { return dice.size() == 0; }
	Die& operator[](int i){ return dice[i]; }
	const Die& operator[](int i) const { return dice[i]; }
	//const std::vector<int> Values() const;
	//std::vector<Die> GetDice() const { return dice; }
	void Clear();
	void Reset();
	Dice operator+(const Dice& rhs) const;

	auto begin() { return dice.begin(); }
	auto end() { return dice.end(); }

	auto begin() const { return dice.begin(); }
	auto end() const { return dice.end(); }

	friend std::ostream& operator<< (std::ostream& out, const Dice& dice);

private:
	std::vector<Die> dice;
	int defaultSize;
	int defaultSides;
};


