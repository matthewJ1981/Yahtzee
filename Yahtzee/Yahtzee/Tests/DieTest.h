#pragma once

#include <gtest/gtest.h>
#include "../Die.h"

class DieTest : public testing::Test
{
protected:

	virtual void SetUp()
	{
		die = new Die(sides, value);
	}

	virtual void TearDown()
	{
		delete die;
	}

	static constexpr int defaultSides = 6;
	static constexpr int defaultValue = 1;
	static constexpr bool defaultHeld = false;
	static constexpr int sides = 8;
	static constexpr int value = 3;
	Die defaultDie;
	Die* die;
};

TEST_F(DieTest, DefaultConstructorTest)
{
	EXPECT_EQ(defaultDie.Sides(), defaultSides);
	EXPECT_EQ(defaultDie.Value(), defaultValue);
	EXPECT_EQ(defaultDie.IsHeld(), defaultHeld);
}


TEST_F(DieTest, ConstructorTest1)
{
	Die defDie(sides);

	EXPECT_EQ(defDie.Sides(), sides);
	EXPECT_EQ(defDie.Value(), defaultValue);
	EXPECT_EQ(defDie.IsHeld(), defaultHeld);
}

TEST_F(DieTest, ConstructorTest2)
{
	EXPECT_EQ(die->Sides(), sides);
	EXPECT_EQ(die->Value(), value);
	EXPECT_EQ(die->IsHeld(), defaultHeld);
}

TEST_F(DieTest, RollTest)
{
	int minValue = 1;
	int maxValue = sides;

	die->Roll();

	EXPECT_EQ(die->Sides(), sides);
	EXPECT_GE(die->Value(), minValue);
	EXPECT_LE(die->Value(), maxValue);
	EXPECT_EQ(die->IsHeld(), defaultHeld);
}

TEST_F(DieTest, SetHeldTest)
{
	bool newHeld = true;
	die->SetHeld(newHeld);

	EXPECT_EQ(die->Sides(), sides);
	EXPECT_EQ(die->Value(), value);
	EXPECT_EQ(die->IsHeld(), newHeld);
}

TEST_F(DieTest, SetValueTest)
{
	int newValue = 4;

	die->SetValue(newValue);

	EXPECT_EQ(die->Sides(), sides);
	EXPECT_EQ(die->Value(), newValue);
	EXPECT_EQ(die->IsHeld(), defaultHeld);
}