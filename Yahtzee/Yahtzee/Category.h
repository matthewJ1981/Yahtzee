#pragma once

#include <string>
#include "Dice.h"

class Category
{
public:
	Category() : score(-1) {}
	virtual ~Category() {}
	
	virtual int CheckScore(const Dice& dice) const = 0;

	void SetScore(int s) { score = s; }
	int Score() const { return score; }

protected:
	int score;
};

