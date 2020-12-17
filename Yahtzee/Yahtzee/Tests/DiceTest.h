#pragma once

#include "Dice.h"
#include <gtest/gtest.h>

TEST(DiceTest, AddDice)
{
	Dice dice;
	dice.AddDice(6);
	std::vector<Die> d = dice.Roll();
	EXPECT_EQ(d.size(), 1);
	EXPECT_EQ(d[0].Sides(), 6);
	EXPECT_GE(d[0].Value(), 1);
	EXPECT_LE(d[0].Value(), 6);
}

TEST(DiceTest, RemoveDice)
{
	Dice dice;
	dice.AddDice(6);
	dice.AddDice(10);
	std::vector<Die> d = dice.Roll();
	EXPECT_EQ(d.size(), 2);
	EXPECT_EQ(d[1].Sides(), 10);
	EXPECT_GE(d[1].Value(), 1);
	EXPECT_LE(d[1].Value(), 10);

	dice.RemoveDice(0);
	d = dice.Roll();
	EXPECT_EQ(d.size(), 1);
	EXPECT_EQ(d[0].Sides(), 10);
	EXPECT_GE(d[0].Value(), 1);
	EXPECT_LE(d[0].Value(), 10);
}