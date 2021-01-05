#pragma once

#include <gtest/gtest.h>
#include "../ScoreCard.h"
#include "../categoryEnums.h"

class ScoreCardTest : public testing::Test
{
protected:
	ScoreCardTest() : dice(5) {}
	virtual void SetUp()
	{
	}

	virtual void TearDown()
	{
	}

	ScoreCard scoreCard;
	Dice dice;
};


TEST_F(ScoreCardTest, ConstructorTest)
{
	EXPECT_EQ(scoreCard.Tally(), 0);
}

TEST_F(ScoreCardTest, SetScoreTest)
{
	dice[0].SetValue(6);
	dice[1].SetValue(6);
	dice[2].SetValue(6);
	dice[3].SetValue(6);
	dice[4].SetValue(6);
					    
	scoreCard.SetScore((int)ALL::SIXES, dice);
	scoreCard.SetScore((int)ALL::YAHTZEE, dice);
	scoreCard.SetScore((int)ALL::LARGESTRAIGHT, dice);
	
	EXPECT_EQ(scoreCard.Tally(), 220);
}
