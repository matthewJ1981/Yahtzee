#pragma once

#include <string>

#include "Category.h"

class ThreeOfKind : public Category
{
public:
	ThreeOfKind();
	int CheckScore(const Dice& dice) const override;
};

class FourOfKind : public Category
{
public:
	FourOfKind();
	int CheckScore(const Dice& dice) const override;
};

class FullHouse : public Category
{
public:
	FullHouse();
	static int ScoreValue() { return 25; }
	int CheckScore(const Dice& dice) const override;
};

class SmallStraight : public Category
{
public:
	SmallStraight();
	static int ScoreValue() { return 30; }
	int CheckScore(const Dice& dice) const override;
};

class LargeStraight : public Category
{
public:
	LargeStraight();
	static int ScoreValue() { return 40; }
	int CheckScore(const Dice& dice) const override;
};

class Yahtzee : public Category
{
public:
	Yahtzee();
	static int ScoreValue() { return 50; }
	int CheckScore(const Dice& dice) const override;
};

class Chance : public Category
{
public:
	Chance();
	int CheckScore(const Dice& dice) const override;
};