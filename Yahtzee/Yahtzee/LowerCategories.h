#pragma once

#include <string>

#include "Category.h"

class ThreeOfKind : public Category
{
public:
	//ThreeOfKind(std::string n) : Category(n) {}
	int CheckScore(const Dice& dice) const override;
};

class FourOfKind : public Category
{
public:
	//FourOfKind(std::string n) : Category(n) {}
	int CheckScore(const Dice& dice) const override;
};

class FullHouse : public Category
{
public:
	//FullHouse(std::string n) : Category(n) {}
	int CheckScore(const Dice& dice) const override;
};

class SmallStraight : public Category
{
public:
	//SmallStraight(std::string n) : Category(n) {}
	int CheckScore(const Dice& dice) const override;
};

class LargeStraight : public Category
{
public:
	//LargeStraight(std::string n) : Category(n) {}
	int CheckScore(const Dice& dice) const override;
};

class Yahtzee : public Category
{
public:
	//Yahtzee(std::string n) : Category(n) {}
	int CheckScore(const Dice& dice) const override;
};

class Chance : public Category
{
public:
	//Chance(std::string n) : Category(n) {}
	int CheckScore(const Dice& dice) const override;
};