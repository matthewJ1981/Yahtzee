#pragma once

#include "../LowerCategories.h"
#include "../Dice.h"
#include <gtest/gtest.h>

class LowerCategoryTest : public testing::Test
{
protected:

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


TEST_F(LowerCategoryTest, ConstructorTest)
{
	score = -1;
	category = new ThreeOfKind();

	EXPECT_EQ(category->Score(), score);

}

TEST_F(LowerCategoryTest, SetScoreTest)
{
	int score = 15;
	category = new ThreeOfKind();
	category->SetScore(score);

	EXPECT_EQ(category->Score(), score);
}

TEST_F(LowerCategoryTest, CheckScoreThreeOfKindTest1)
{
	category = new ThreeOfKind();

	dice[0].SetValue(4);
	dice[1].SetValue(4);
	dice[2].SetValue(5);
	dice[3].SetValue(5);
	dice[4].SetValue(5);
						  
	EXPECT_EQ(category->CheckScore(dice), 23);
}

TEST_F(LowerCategoryTest, CheckScoreThreeOfKindTest2)
{
	category = new ThreeOfKind();

	dice[0].SetValue(5);
	dice[1].SetValue(5);
	dice[2].SetValue(1);
	dice[3].SetValue(1);
	dice[4].SetValue(3);
						   
	EXPECT_EQ(category->CheckScore(dice), 0);
}

TEST_F(LowerCategoryTest, CheckScoreThreeOfKindTest3)
{
	category = new ThreeOfKind();

	dice[0].SetValue(4);
	dice[1].SetValue(5);
	dice[2].SetValue(5);
	dice[3].SetValue(5);
	dice[4].SetValue(6);
				
	EXPECT_EQ(category->CheckScore(dice), 25);
}

TEST_F(LowerCategoryTest, CheckScoreThreeOfKindTest4)
{
	category = new ThreeOfKind();

	dice[0].SetValue(6);
	dice[1].SetValue(1);
	dice[2].SetValue(1);
	dice[3].SetValue(1);
	dice[4].SetValue(1);
				   
	EXPECT_EQ(category->CheckScore(dice), 10);
}

TEST_F(LowerCategoryTest, CheckScoreFourOfKindTest1)
{
	category = new FourOfKind();

	dice[0].SetValue(1);
	dice[1].SetValue(1);
	dice[2].SetValue(1);
	dice[3].SetValue(1);
	dice[4].SetValue(5);
				 
	EXPECT_EQ(category->CheckScore(dice), 9);
}

TEST_F(LowerCategoryTest, CheckScoreFourOfKindTest2)
{
	category = new FourOfKind();

	dice[0].SetValue(1);
	dice[1].SetValue(1);
	dice[2].SetValue(1);
	dice[3].SetValue(1);
	dice[4].SetValue(1);

	EXPECT_EQ(category->CheckScore(dice), 5);
}

TEST_F(LowerCategoryTest, CheckScoreFourOfKindTest3)
{
	category = new FourOfKind();

	dice[0].SetValue(1);
	dice[1].SetValue(1);
	dice[2].SetValue(1);
	dice[3].SetValue(4);
	dice[4].SetValue(5);

	EXPECT_EQ(category->CheckScore(dice), 0);
}

TEST_F(LowerCategoryTest, CheckScoreFullHouseTest1)
{
	category = new FullHouse();

	dice[0].SetValue(1);
	dice[1].SetValue(1);
	dice[2].SetValue(1);
	dice[3].SetValue(5);
	dice[4].SetValue(5);

	EXPECT_EQ(category->CheckScore(dice), 25);
}

TEST_F(LowerCategoryTest, CheckScoreFullHouseTest2)
{
	category = new FullHouse();

	dice[0].SetValue(1);
	dice[1].SetValue(1);
	dice[2].SetValue(1);
	dice[3].SetValue(3);
	dice[4].SetValue(5);

	EXPECT_EQ(category->CheckScore(dice), 0);
}

TEST_F(LowerCategoryTest, CheckScoreFullHouseTest3)
{
	category = new FullHouse();

	dice[0].SetValue(1);
	dice[1].SetValue(1);
	dice[2].SetValue(3);
	dice[3].SetValue(3);
	dice[4].SetValue(5);
						    
	EXPECT_EQ(category->CheckScore(dice), 0);
}

TEST_F(LowerCategoryTest, CheckScoreSmallStraightTest)
{
	category = new SmallStraight();

	dice[0].SetValue(2);
	dice[1].SetValue(1);
	dice[2].SetValue(2);
	dice[3].SetValue(3);
	dice[4].SetValue(4);

	EXPECT_EQ(category->CheckScore(dice), 30);
}

TEST_F(LowerCategoryTest, CheckScoreLargeStraightTest)
{
	category = new LargeStraight();

	dice[0].SetValue(1);
	dice[1].SetValue(2);
	dice[2].SetValue(3);
	dice[3].SetValue(4);
	dice[4].SetValue(5);

	EXPECT_EQ(category->CheckScore(dice), 40);
}

TEST_F(LowerCategoryTest, CheckScoreYahtzeeTest)
{
	category = new Yahtzee();

	dice[0].SetValue(6);
	dice[1].SetValue(6);
	dice[2].SetValue(6);
	dice[3].SetValue(6);
	dice[4].SetValue(6);

	EXPECT_EQ(category->CheckScore(dice), 50);
}

TEST_F(LowerCategoryTest, CheckScoreChanceTest)
{
	category = new Chance();

	dice[0].SetValue(4);
	dice[1].SetValue(1);
	dice[2].SetValue(6);
	dice[3].SetValue(2);
	dice[4].SetValue(6);

	EXPECT_EQ(category->CheckScore(dice), 19);
}