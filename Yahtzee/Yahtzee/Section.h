#pragma once
#include <vector>
#include "Category.h"

class Section
{
public:
	Section() : subtotal(0), bonus(0), total(0) {}
	virtual ~Section() {};
	const std::vector<Category*> Categories() { return categories; }
	std::vector<std::pair<Category*, int>> CheckScores(const std::vector<Die>& dice);
protected:
	std::vector<Category*> categories;
	int subtotal;
	int bonus;
	int total;
};
