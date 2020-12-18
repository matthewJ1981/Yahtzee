#pragma once

#include <gtest/gtest.h>
#include "../Die.h"

TEST(DieTest, DefaultConstructorTest)
{
	int sides = 6;
	int value = 1;

	Die die;

	EXPECT_EQ(die.Sides(), sides);
	EXPECT_EQ(die.Value(), value);
}


TEST(DieTest, ConstructorTest)
{
	int sides = 8;
	int value = 1;

	Die die(sides);

	EXPECT_EQ(die.Sides(), sides);
	EXPECT_EQ(die.Value(), value);
}

TEST(DieTest, RollTest)
{
	int sides = 6;
	int value = 1;
	int minValue = 1;
	int maxValue = sides;

	Die die(sides);
	die.Roll();

	EXPECT_EQ(die.Sides(), sides);
	EXPECT_GE(die.Value(), minValue);
	EXPECT_LE(die.Value(), maxValue);
}
