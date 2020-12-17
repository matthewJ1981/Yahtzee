#pragma once

#include <string>
#include <vector>
#include "Die.h"

class Category
{
public:
	Category(std::string n) : score(-1), name(n) {}
	virtual ~Category() {}
	int Score() const { return score; }
	virtual int CheckScore(const std::vector<Die>& dice) = 0;
	void SetScore(int s) { score = s; }
	std::string Name() const { return name; }

protected:
	std::string name;
	int score;
};

