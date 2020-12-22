#pragma once

#include "../Dice.h"
#include <gtest/gtest.h>

class DiceTest : public testing::Test
{
protected:

	virtual void SetUp()
	{
		dice = new Dice(numDice, numSides);
	}

	virtual void TearDown()
	{
		delete dice;
	}

	static constexpr int defaultSize = 5;
	static constexpr int defaultSides = 6;
	static constexpr int defaultValue = 1;
	static constexpr int defaultHeld = false;
	static constexpr int numDice = 8;
	static constexpr int numSides = 3;

	Dice defaultDice;
	Dice* dice;
};

TEST_F(DiceTest, DefaultConstructorTest)
{
	EXPECT_EQ(defaultDice.size(), defaultSize);
	EXPECT_EQ(defaultDice[0].Value(), defaultValue);
}

TEST_F(DiceTest, ConstructorDefaultSidesTest)
{
	Dice dice(numDice);

	EXPECT_EQ(dice.size(), numDice);
	EXPECT_EQ(dice[0].Value(), 1);

	for (Die d : dice)
	{
		EXPECT_EQ(d.Value(), defaultValue);
		EXPECT_EQ(d.Sides(), defaultSides);
		EXPECT_EQ(d.IsHeld(), defaultHeld);
	}
}

TEST_F(DiceTest, ConstructorTest)
{
	EXPECT_EQ(dice->size(), numDice);
	EXPECT_EQ((*dice)[0].Value(), defaultValue);

	for (Die d : *dice)
	{
		EXPECT_EQ(d.Value(), defaultValue);
		EXPECT_EQ(d.Sides(), numSides);
		EXPECT_EQ(d.IsHeld(), defaultHeld);
	}
}

TEST_F(DiceTest, AddDiceTest)
{
	Die die;
	dice->AddDice(die);

	EXPECT_EQ(dice->size(), numDice + 1);
	EXPECT_EQ((*dice)[dice->size() - 1].Sides(), defaultSides);
	EXPECT_EQ((*dice)[dice->size() - 1].Value(), defaultValue);
}

TEST_F(DiceTest, RemoveDiceTest)
{
	dice->RemoveDice(0);

	EXPECT_EQ(dice->size(), numDice - 1);
	EXPECT_EQ((*dice)[0].Sides(), numSides);
	EXPECT_EQ((*dice)[0].Value(), defaultValue);
}

TEST_F(DiceTest, RollDiceTest)
{
	int minValue = 1;
	int maxValue = numSides;

	dice->Roll();

	EXPECT_EQ(dice->size(), numDice);
	for (Die d : *dice)
	{
		EXPECT_GE(d.Value(), minValue);
		EXPECT_LE(d.Value(), maxValue);
		EXPECT_EQ(d.Sides(), numSides);
	}
}