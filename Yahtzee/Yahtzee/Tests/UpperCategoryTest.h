#pragma once

#include "../UpperCategories.h"
#include "../Dice.h"
#include <gtest/gtest.h>

class UpperCategoryTest : public testing::Test
{
protected:
	UpperCategoryTest() : dice(5) {}
	virtual void SetUp()
	{
	}

	virtual void TearDown()
	{
		delete category;
	}

	int score;
	Dice dice;
	Category* category = nullptr;
};

TEST_F(UpperCategoryTest, ConstructorTest)
{
	int score = -1;
	category = new Ones();

	EXPECT_EQ(category->Score(), score);
}

TEST_F(UpperCategoryTest, SetScoreTest)
{
	int score = 15;
	category = new Ones();
	category->SetScore(score);

	EXPECT_EQ(category->Score(), score);
}

TEST_F(UpperCategoryTest, CheckScoreOnesTest)
{
	category = new Ones();

	dice[0].SetValue(5);
	dice[1].SetValue(1);
	dice[2].SetValue(1);
	dice[3].SetValue(1);
	dice[4].SetValue(5);

	EXPECT_EQ(category->CheckScore(dice), 3);
}

TEST_F(UpperCategoryTest, CheckScoreTwosTest)
{
	category = new Twos();

	dice[0].SetValue(2);
	dice[1].SetValue(1);
	dice[2].SetValue(2);
	dice[3].SetValue(1);
	dice[4].SetValue(5);
				 
	EXPECT_EQ(category->CheckScore(dice), 4);
}

TEST_F(UpperCategoryTest, CheckScoreThreesTest)
{
	category = new Threes();

	dice[0].SetValue(3);
	dice[1].SetValue(1);
	dice[2].SetValue(2);
	dice[3].SetValue(6);
	dice[4].SetValue(4);

	EXPECT_EQ(category->CheckScore(dice), 3);
}

TEST_F(UpperCategoryTest, CheckScoreFoursTest)
{
	category = new Fours();

	dice[0].SetValue(4);
	dice[1].SetValue(4);
	dice[2].SetValue(4);
	dice[3].SetValue(4);
	dice[4].SetValue(4);
				 
	EXPECT_EQ(category->CheckScore(dice), 20);
}

TEST_F(UpperCategoryTest, CheckScoreFivesTest)
{
	category = new Fives();

	dice[0].SetValue(5);
	dice[1].SetValue(5);
	dice[2].SetValue(2);
	dice[3].SetValue(6);
	dice[4].SetValue(4);

	EXPECT_EQ(category->CheckScore(dice), 10);
}

TEST_F(UpperCategoryTest, CheckScoreSixesTest)
{
	category = new Sixes();

	dice[0].SetValue(3);
	dice[1].SetValue(1);
	dice[2].SetValue(2);
	dice[3].SetValue(6);
	dice[4].SetValue(4);

	EXPECT_EQ(category->CheckScore(dice), 6);
}