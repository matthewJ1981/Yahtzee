#pragma once

#include <string>
#include <vector>

#include "Die.h"
#include "Category.h"
class Ones : public Category
{
public:
	Ones(std::string n) : Category(n) {}
	int CheckScore(const std::vector<Die>& dice);
private:

};
