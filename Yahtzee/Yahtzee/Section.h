#pragma once

#include <vector>
#include <tuple>
#include <memory>
#include "Category.h"


class Section
{
public:
	Section() : subtotal(0), bonus(0), total(0) {}
	virtual ~Section() {};

	int SubTotal() const { return subtotal; }
	int Bonus() const { return bonus; }
	int Total() const { return total; }
	int Size() const { return (int)categories.size(); }
	bool SetScore(int index, int score);

	std::vector<std::pair<std::string, int>>  CheckScores(const Dice& dice) const;
	std::vector<int> GetScores() const;

	void CalcSubTotal();
	virtual int Tally() = 0;

protected:
	std::vector<std::unique_ptr<Category>> categories;
	int subtotal;
	mutable int bonus;
	int total;
};
