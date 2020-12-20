#pragma once

#include <string>

#include "Category.h"

class Ones : public Category
{
public:
	//Ones(std::string n) : Category(n) {}
	int CheckScore(const Dice& dice) const override;
};

class Twos : public Category
{
public:
	//Twos(std::string n) : Category(n) {}
	int CheckScore(const Dice& dice) const override;
};

class Threes : public Category
{
public:
	//Threes(std::string n) : Category(n) {}
	int CheckScore(const Dice& dice) const override;
};

class Fours : public Category
{
public:
	//Fours(std::string n) : Category(n) {}
	int CheckScore(const Dice& dice) const override;
};

class Fives : public Category
{
public:
	//Fives(std::string n) : Category(n) {}
	int CheckScore(const Dice& dice) const override;
};

class Sixes : public Category
{
public:
	//Sixes(std::string n) : Category(n) {}
	int CheckScore(const Dice& dice) const override;
};