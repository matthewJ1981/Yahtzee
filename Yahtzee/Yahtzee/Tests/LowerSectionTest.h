#pragma once

#include "../Sections.h"
#include <gtest/gtest.h>

TEST(LowerSectionTest, ConstructorTest)
{
	
	Section* lower = new Lower();
	Dice dice; //5 6-sided dice, all value 1

	EXPECT_EQ(lower->SubTotal(), 0);
	EXPECT_EQ(lower->Bonus(), 0);
	EXPECT_EQ(lower->Total(), 0);
	EXPECT_EQ(lower->Size(), 7);
	EXPECT_EQ(lower->CheckScores(dice).size(), 1);
	EXPECT_EQ(static_cast<Lower*>(lower)->BonusEligibile(), false);
}

TEST(LowerSectionTest, SetScoreTest)
{
	int score = 50;
	int bonus = 100;

	Lower lower;
	Dice dice; //5 6-sided dice, all value 1
	//std::vector<std::pair<int, std::string>> scores;
	//scores.push(std::make_pair())

	lower.SetScore(0, score);

	EXPECT_EQ(lower.SubTotal(), 0);
	EXPECT_EQ(lower.Bonus(), 0);
	EXPECT_EQ(lower.Total(), 0);
	EXPECT_EQ(lower.Size(), 7);
	//EXPECT_EQ(lower.CheckScores(dice).size(), 0);
	EXPECT_EQ(lower.BonusEligibile(), false);
}

TEST(LowerSectionTest, CalcSubTotalTest)
{
	int score = 50;
	int bonus = 100;

	Section* lower = new Lower();
	Dice dice; //5 6-sided dice, all value 1

	lower->SetScore(0, score);
	lower->CalcSubTotal();

	EXPECT_EQ(lower->SubTotal(), score);
	EXPECT_EQ(lower->Bonus(), 0);
	EXPECT_EQ(lower->Total(), 0);
	EXPECT_EQ(lower->Size(), 7);
	EXPECT_EQ(lower->CheckScores(dice).size(), 0);
	EXPECT_EQ(static_cast<Lower*>(lower)->BonusEligibile(), false);
}

TEST(LowerSectionTest, TallyTest)
{
	int score = 80;
	int bonus = 100;

	Section* lower = new Lower();
	Dice dice; //5 6-sided dice, all value 1

	lower->SetScore(0, score);
	lower->CalcSubTotal();
	lower->Tally();

	EXPECT_EQ(lower->SubTotal(), score);
	EXPECT_EQ(lower->Bonus(), 0);
	EXPECT_EQ(lower->Total(), score);
	EXPECT_EQ(lower->Size(), 7);
	EXPECT_EQ(lower->CheckScores(dice).size(), 0);
	EXPECT_EQ(static_cast<Lower*>(lower)->BonusEligibile(), false);
}

TEST(LowerSectionTest, IncrementBonusTest)
{
	int score = 80;
	int bonus = 100;

	Section* lower = new Lower();
	Dice dice; //5 6-sided dice, all value 1

	lower->SetScore(0, score);

	Lower* lowPointer = static_cast<Lower*>(lower);
	lowPointer->IncrementBonus();

	lower->CalcSubTotal();
	lower->Tally();

	EXPECT_EQ(lower->SubTotal(), score);
	EXPECT_EQ(lower->Bonus(), bonus);
	EXPECT_EQ(lower->Total(), bonus + score);
	EXPECT_EQ(lower->Size(), 7);
	EXPECT_EQ(lower->CheckScores(dice).size(), 0);
	EXPECT_EQ(static_cast<Lower*>(lower)->BonusEligibile(), false);
}

TEST(LowerSectionTest, SetBonusEligibleTest)
{
	int score = 80;
	int bonus = 100;

	Section* lower = new Lower();
	Dice dice; //5 6-sided dice, all value 1

	Lower* lowPointer = static_cast<Lower*>(lower);

	lowPointer->SetBonusEligible(true);

	EXPECT_EQ(lower->SubTotal(), 0);
	EXPECT_EQ(lower->Bonus(), 0);
	EXPECT_EQ(lower->Total(), 0);
	EXPECT_EQ(lower->Size(), 7);
	EXPECT_EQ(lower->CheckScores(dice).size(), 1);
	EXPECT_EQ(static_cast<Lower*>(lower)->BonusEligibile(), true);
}