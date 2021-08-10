#pragma once

#include <string>
#include "Category.h"

class Ones : public Category
{
public:
	int CheckScore(const Dice& dice) const override;
};

class Twos : public Category
{
public:
	int CheckScore(const Dice& dice) const override;
};

class Threes : public Category
{
public:
	int CheckScore(const Dice& dice) const override;
};

class Fours : public Category
{
public:
	int CheckScore(const Dice& dice) const override;
};

class Fives : public Category
{
public:
	int CheckScore(const Dice& dice) const override;
};

class Sixes : public Category
{
public:
	int CheckScore(const Dice& dice) const override;
};