#pragma once

#include <gtest/gtest.h>
#include "../ScoreCard.h"
#include "../categoryEnums.h"

TEST(ScoredCardTest, ConstructorTest)
{
	ScoreCard scoreCard;
	EXPECT_EQ(scoreCard.Tally(), 0);
}

TEST(ScoredCardTest, SetScoreTest)
{
	ScoreCard scoreCard;

	Dice dice;
	dice.AddDice(6, 6);
	dice.AddDice(6, 6);
	dice.AddDice(6, 6);
	dice.AddDice(6, 6);
	dice.AddDice(6, 6);
	
	scoreCard.SetScore((int)ALL::SIXES, dice);
	scoreCard.SetScore((int)ALL::YAHTZEE, dice);
	scoreCard.SetScore((int)ALL::LARGESTRAIGHT, dice);
	
	EXPECT_EQ(scoreCard.Tally(), 220);
}