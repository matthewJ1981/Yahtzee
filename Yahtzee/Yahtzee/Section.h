#pragma once

#include <vector>
#include <tuple>

#include "Category.h"


class Section
{
public:
	Section() : subtotal(0), bonus(0), total(0) {}
	virtual ~Section() {};

	std::vector<std::pair<int, std::string>> CheckScores(const Dice& dice) const;

	int SubTotal() const { return subtotal; }
	int Bonus() const { return bonus; }
	int Total() const { return total; }
	int Size() const { return (int)categories.size(); }
	void SetScore(int index, int score);
	std::vector<std::pair<int, std::string>> GetScores();

	void CalcSubTotal();
	virtual int Tally() = 0;

protected:
	std::vector<Category*> categories;
	int subtotal;
	int bonus;
	int total;
};
