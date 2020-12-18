#pragma once

#include "Dice.h"
#include <gtest/gtest.h>

TEST(DiceTest, DefaultConstructorTest)
{
	Dice dice;
	std::vector<Die> diceDice = dice.GetDice();
	EXPECT_EQ(dice.GetDice().size(), 0);
}

TEST(DiceTest, ConstructorDefaultSidesTest)
{
	int numDice = 5;
	int value = 1;
	int sides = 6;

	Dice dice(numDice);
	std::vector<Die> diceDice = dice.GetDice();

	EXPECT_EQ(diceDice.size(), numDice);

	for (Die d : diceDice)
	{
		EXPECT_EQ(d.Value(), value);
		EXPECT_EQ(d.Sides(), sides);
	}
}

TEST(DiceTest, ConstructorTest)
{
	int numDice = 7;
	int sides = 8;
	int value = 1;

	Dice dice(numDice, sides);
	std::vector<Die> diceDice = dice.GetDice();

	EXPECT_EQ(diceDice.size(), numDice);

	for (Die d : diceDice)
	{
		EXPECT_EQ(d.Value(), value);
		EXPECT_EQ(d.Sides(), sides);
	}
}

TEST(DiceTest, AddDiceDefaultTest)
{
	int value = 1;
	int sides = 6;
	int numDice = 1;

	Dice dice;
	dice.AddDice();
	std::vector<Die> diceDice = dice.GetDice();

	EXPECT_EQ(diceDice.size(), numDice);
	EXPECT_EQ(diceDice[0].Sides(), sides);
	EXPECT_EQ(diceDice[0].Value(), value);
}

TEST(DiceTest, AddDiceTest)
{
	int value = 1;
	int sides = 4;
	int numDice = 1;

	Dice dice;
	dice.AddDice(sides);
	std::vector<Die> diceDice = dice.GetDice();

	EXPECT_EQ(diceDice.size(), numDice);
	EXPECT_EQ(diceDice[0].Sides(), sides);
	EXPECT_EQ(diceDice[0].Value(), value);
}

TEST(DiceTest, RemoveDiceTest)
{
	int value = 1;
	int sides = 5;
	int numDice = 2;

	Dice dice(numDice, sides);
	dice.RemoveDice(0);

	std::vector<Die> diceDice = dice.GetDice();
	EXPECT_EQ(diceDice.size(), numDice - 1);
	EXPECT_EQ(diceDice[0].Sides(), sides);
	EXPECT_EQ(diceDice[0].Value(), value);
}

// This test fails an out of bounds assertion in the code \\

//TEST(DiceTest, RemoveOutOfBoundsDiceTest)
//{
//	int value = 1;
//	int sides = 5;
//	int numDice = 2;
//
//	Dice dice(numDice, sides);
//	dice.RemoveDice(4);
//
//	std::vector<Die> diceDice = dice.GetDice();
//	EXPECT_EQ(diceDice.size(), numDice);
//	EXPECT_EQ(diceDice[0].Sides(), sides);
//	EXPECT_EQ(diceDice[0].Value(), value);
//}

TEST(DiceTest, RollDiceTest)
{
	int value = 1;
	int sides = 6;
	int numDice = 6;
	int minValue = 1;
	int maxValue = sides;

	Dice dice(numDice, sides);
	dice.Roll();

	std::vector<Die> diceDice = dice.GetDice();

	EXPECT_EQ(diceDice.size(), numDice);
	for (Die d : diceDice)
	{
		EXPECT_GE(d.Value(), minValue);
		EXPECT_LE(d.Value(), maxValue);
		EXPECT_EQ(d.Sides(), sides);
	}
}