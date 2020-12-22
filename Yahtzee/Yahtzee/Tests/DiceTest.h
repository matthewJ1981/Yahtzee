#pragma once

#include "../Dice.h"
#include <gtest/gtest.h>

TEST(DiceTest, DefaultConstructorTest)
{
	constexpr int defaultSize = 5;
	constexpr int defaultValue = 1;

	Dice dice;

	EXPECT_EQ(dice.size(), defaultSize);
	EXPECT_EQ(dice[0].Value(), defaultValue);
}

TEST(DiceTest, ConstructorDefaultSidesTest)
{
	constexpr int defaultSize = 5;
	constexpr int defaultValue = 1;
	constexpr int defaultSides = 6;

	Dice dice;

	EXPECT_EQ(dice.size(), defaultSize);
	EXPECT_EQ(dice[0].Value(), 1);

	for (Die d : dice)
	{
		EXPECT_EQ(d.Value(), defaultValue);
		EXPECT_EQ(d.Sides(), defaultSides);
		EXPECT_EQ(d.IsHeld(), false);
	}
}

TEST(DiceTest, ConstructorTest)
{
	int numDice = 7;
	int sides = 8;
	int value = 1;

	Dice dice(numDice, sides);

	EXPECT_EQ(dice.size(), numDice);
	EXPECT_EQ(dice[0].Value(), 1);

	for (Die d : dice)
	{
		EXPECT_EQ(d.Value(), value);
		EXPECT_EQ(d.Sides(), sides);
		EXPECT_EQ(d.IsHeld(), false);
	}
}

TEST(DiceTest, AddDiceTest)
{
	int value = 1;
	int sides = 6;
	int numDice = 1;
	int defaultSize = 5;

	Dice dice;
	Die die;
	dice.AddDice(die);

	EXPECT_EQ(dice.size(), defaultSize);
	EXPECT_EQ(dice[0].Sides(), sides);
	EXPECT_EQ(dice[0].Value(), value);
}

TEST(DiceTest, RemoveDiceTest)
{
	int value = 1;
	int sides = 5;
	int numDice = 2;

	Dice dice;
	dice.RemoveDice(0);

	EXPECT_EQ(dice.size(), numDice - 1);
	EXPECT_EQ(dice[0].Sides(), sides);
	EXPECT_EQ(dice[0].Value(), value);
}

TEST(DiceTest, RollDiceTest)
{
	int value = 1;
	int sides = 6;
	int numDice = 6;
	int minValue = 1;
	int maxValue = sides;

	Dice dice(numDice, sides);
	dice.Roll();

	EXPECT_EQ(dice.size(), numDice);
	for (Die d : dice)
	{
		EXPECT_GE(d.Value(), minValue);
		EXPECT_LE(d.Value(), maxValue);
		EXPECT_EQ(d.Sides(), sides);
	}
}