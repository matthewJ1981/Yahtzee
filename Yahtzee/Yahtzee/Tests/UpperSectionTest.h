#pragma once

#include "../Sections.h"
#include <gtest/gtest.h>

TEST(UpperSectionTest, ConstructorTest)
{
	
	Section* upper = new Upper();
	Dice dice; //5 6-sided dice, all value 1

	EXPECT_EQ(upper->SubTotal(), 0);
	EXPECT_EQ(upper->Bonus(), 0);
	EXPECT_EQ(upper->Total(), 0);
	EXPECT_EQ(upper->Size(), 1);
	EXPECT_EQ(upper->CheckScores(dice).size(), 1);
}

TEST(UpperSectionTest, SetScoreTest)
{
	int score = 50;
	int bonus = 35;

	Section* upper = new Upper();
	Dice dice; //5 6-sided dice, all value 1

	upper->SetScore(0, score);

	EXPECT_EQ(upper->SubTotal(), 0);
	EXPECT_EQ(upper->Bonus(), 0);
	EXPECT_EQ(upper->Total(), 0);
	EXPECT_EQ(upper->Size(), 1);
	EXPECT_EQ(upper->CheckScores(dice).size(), 0);
}

TEST(UpperSectionTest, CalcSubTotalTest)
{
	int score = 50;
	int bonus = 35;

	Section* upper = new Upper();
	Dice dice; //5 6-sided dice, all value 1

	upper->SetScore(0, score);
	upper->CalcSubTotal();

	EXPECT_EQ(upper->SubTotal(), score);
	EXPECT_EQ(upper->Bonus(), 0);
	EXPECT_EQ(upper->Total(), 0);
	EXPECT_EQ(upper->Size(), 1);
	EXPECT_EQ(upper->CheckScores(dice).size(), 0);
}

TEST(UpperSectionTest, TallyTest)
{
	int score = 80;
	int bonus = 35;

	Section* upper = new Upper();
	Dice dice; //5 6-sided dice, all value 1

	upper->SetScore(0, score);
	upper->CalcSubTotal();
	upper->Tally();

	EXPECT_EQ(upper->SubTotal(), score);
	EXPECT_EQ(upper->Bonus(), bonus);
	EXPECT_EQ(upper->Total(), score + bonus);
	EXPECT_EQ(upper->Size(), 1);
	EXPECT_EQ(upper->CheckScores(dice).size(), 0);
}
