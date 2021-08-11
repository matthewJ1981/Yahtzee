#pragma once

#include <string>
#include "Category.h"

class Ones : public Category
{
public:
	Ones();
	int CheckScore(const Dice& dice) const override;
	std::unique_ptr<Category> clone() const override;
};

class Twos : public Category
{
public:
	Twos();
	int CheckScore(const Dice& dice) const override;
	std::unique_ptr<Category> clone() const override;
};

class Threes : public Category
{
public:
	Threes();
	int CheckScore(const Dice& dice) const override;
	std::unique_ptr<Category> clone() const override;
};

class Fours : public Category
{
public:
	Fours();
	int CheckScore(const Dice& dice) const override;
	std::unique_ptr<Category> clone() const override;
};

class Fives : public Category
{
public:
	Fives();
	int CheckScore(const Dice& dice) const override;
	std::unique_ptr<Category> clone() const override;
};

class Sixes : public Category
{
public:
	Sixes();
	int CheckScore(const Dice& dice) const override;
	std::unique_ptr<Category> clone() const override;
};