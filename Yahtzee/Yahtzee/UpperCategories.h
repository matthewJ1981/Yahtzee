#pragma once

#include <string>

#include "Category.h"
class Ones : public Category
{
public:
	Ones(std::string n) : Category(n) {}
	int CheckScore(const Dice& dice) const override;
private:

};
