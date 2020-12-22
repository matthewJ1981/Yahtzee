#pragma once

#include "../Sections.h"
#include <gtest/gtest.h>

class UpperSectionTest : public testing::Test
{
protected:

	virtual void SetUp()
	{
	}

	virtual void TearDown()
	{
	}

	Upper upper;
	Dice dice;

};


TEST_F(UpperSectionTest, ConstructorTest)
{

	EXPECT_EQ(upper.SubTotal(), 0);
	EXPECT_EQ(upper.Bonus(), 0);
	EXPECT_EQ(upper.Total(), 0);
	EXPECT_EQ(upper.Size(), 6);
	EXPECT_EQ(upper.CheckScores(dice).size(), 6);
}

TEST_F(UpperSectionTest, SetScoreTest)
{
	int score = 50;

	upper.SetScore(0, score);

	EXPECT_EQ(upper.SubTotal(), 0);
	EXPECT_EQ(upper.Bonus(), 0);
	EXPECT_EQ(upper.Total(), 0);
	EXPECT_EQ(upper.Size(), 6);
	EXPECT_EQ(upper.CheckScores(dice).size(), 6);
}

TEST_F(UpperSectionTest, CalcSubTotalTest)
{
	int score = 50;

	upper.SetScore(0, score);
	upper.CalcSubTotal();

	EXPECT_EQ(upper.SubTotal(), score);
	EXPECT_EQ(upper.Bonus(), 0);
	EXPECT_EQ(upper.Total(), 0);
	EXPECT_EQ(upper.Size(), 6);
	EXPECT_EQ(upper.CheckScores(dice).size(), 6);
}

TEST_F(UpperSectionTest, TallyTest)
{
	int score = 80;
	int bonus = 35;

	upper.SetScore(0, score);
	upper.Tally();

	EXPECT_EQ(upper.SubTotal(), score);
	EXPECT_EQ(upper.Bonus(), bonus);
	EXPECT_EQ(upper.Total(), score + bonus);
	EXPECT_EQ(upper.Size(), 6);
	EXPECT_EQ(upper.CheckScores(dice).size(), 6);
}
