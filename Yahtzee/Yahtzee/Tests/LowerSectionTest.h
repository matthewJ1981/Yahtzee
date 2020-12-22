#pragma once

#include "../Sections.h"
#include <gtest/gtest.h>

class LowerSectionTest : public testing::Test
{
protected:

	virtual void SetUp()
	{
	}

	virtual void TearDown()
	{
	}

	Lower lower;
	Dice dice;

};


TEST_F(LowerSectionTest, ConstructorTest)
{
	EXPECT_EQ(lower.SubTotal(), 0);
	EXPECT_EQ(lower.Bonus(), 0);
	EXPECT_EQ(lower.Total(), 0);
	EXPECT_EQ(lower.Size(), 7);
	EXPECT_EQ(lower.BonusEligibile(), false);
}

TEST_F(LowerSectionTest, SetScoreTest1)
{
	int score = 50;

	lower.SetScore(0, score);

	EXPECT_EQ(lower.SubTotal(), 0);
	EXPECT_EQ(lower.Bonus(), 0);
	EXPECT_EQ(lower.Total(), 0);
	EXPECT_EQ(lower.Size(), 7);
	EXPECT_EQ(lower.BonusEligibile(), false);
}

TEST_F(LowerSectionTest, SetScoreTest2)
{
	int score = 50;

	lower.SetScore(5, score);
	lower.SetScore(0, 30);
	lower.Tally();

	EXPECT_EQ(lower.SubTotal(), 80);
	EXPECT_EQ(lower.Bonus(), 0);
	EXPECT_EQ(lower.Total(), 80);
	EXPECT_EQ(lower.Size(), 7);
	EXPECT_EQ(lower.BonusEligibile(), true);
}

TEST_F(LowerSectionTest, CalcSubTotalTest)
{
	int score = 50;

	lower.SetScore(0, score);
	lower.CalcSubTotal();

	EXPECT_EQ(lower.SubTotal(), score);
	EXPECT_EQ(lower.Bonus(), 0);
	EXPECT_EQ(lower.Total(), 0);
	EXPECT_EQ(lower.Size(), 7);
	EXPECT_EQ(lower.BonusEligibile(), false);
}

TEST_F(LowerSectionTest, TallyTest)
{
	int score = 80;

	lower.SetScore(0, score);
	lower.Tally();

	EXPECT_EQ(lower.SubTotal(), score);
	EXPECT_EQ(lower.Bonus(), 0);
	EXPECT_EQ(lower.Total(), score);
	EXPECT_EQ(lower.Size(), 7);
	EXPECT_EQ(lower.BonusEligibile(), false);
}

TEST_F(LowerSectionTest, IncrementBonusTest)
{
	int score = 80;
	int bonus = 100;

	lower.SetScore(0, score);

	lower.IncrementBonus();

	lower.Tally();

	EXPECT_EQ(lower.SubTotal(), score);
	EXPECT_EQ(lower.Bonus(), bonus);
	EXPECT_EQ(lower.Total(), bonus + score);
	EXPECT_EQ(lower.Size(), 7);
	EXPECT_EQ(lower.BonusEligibile(), false);
}