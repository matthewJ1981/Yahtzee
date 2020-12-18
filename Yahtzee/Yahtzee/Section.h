#pragma once
#include <vector>
#include "Category.h"

class Section
{
public:
	Section() : subtotal(0), bonus(0), total(0) {}
	virtual ~Section() {};

	const std::vector<Category*> Categories() { return categories; }
	std::vector<std::pair<Category*, int>> CheckScores(const Dice& dice);

	//void SetSubTotal(int st) { subtotal = st; }
	//void SetBonus(int b) { bonus = b; }
	//void SetTotal(int t) { total = t; }

	int SubTotal() const { return subtotal; }
	int Bonus() const { return bonus; }
	int Total() const { return total; }

	void CalcSubTotal();
	virtual int Tally() = 0;

protected:
	std::vector<Category*> categories;
	int subtotal;
	int bonus;
	int total;
};
