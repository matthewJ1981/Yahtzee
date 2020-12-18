#pragma once

#include <string>

#include "Category.h"

class ThreeOfKind : public Category
{
public:
	ThreeOfKind(std::string n) : Category(n) {}
	int CheckScore(const Dice& dice) const override;
private:

};
