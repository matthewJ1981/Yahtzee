#pragma once

#include <gtest/gtest.h>
#include "../ScoreCard.h"

TEST(ScoredCardTest, ConstructorTest)
{
	ScoreCard scoreCard;
	EXPECT_EQ(scoreCard.Tally(), 0);
}

TEST(ScoredCardTest, SetScoreTest)
{
	ScoreCard scoreCard;
	
	scoreCard.SetScore(5, 45);
	scoreCard.SetScore(11, 50);
	scoreCard.SetScore(2, 10, true);
	
	EXPECT_EQ(scoreCard.Tally(), 205);
}