#pragma once

#include "../LowerCategories.h"
#include "../Dice.h"
#include <gtest/gtest.h>

TEST(LowerCategoryTest, ConstructorTest)
{
	int score = -1;

	Category* category = new ThreeOfKind();

	EXPECT_EQ(category->Score(), score);
}

TEST(LowerCategoryTest, SetScoreTest)
{
	int score = 15;

	Category* category = new ThreeOfKind();
	category->SetScore(score);

	EXPECT_EQ(category->Score(), score);
}

TEST(LowerCategoryTest, CheckScoreThreeOfKindTest1)
{
	int score = -1;

	Category* category = new ThreeOfKind();

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 4);
	dice.AddDice(sides, 4);
	dice.AddDice(sides, 5);
	dice.AddDice(sides, 5);
	dice.AddDice(sides, 5);

	EXPECT_EQ(category->CheckScore(dice), 23);
}

TEST(LowerCategoryTest, CheckScoreThreeOfKindTest2)
{
	int score = -1;

	Category* category = new ThreeOfKind();

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 5);
	dice.AddDice(sides, 5);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 3);

	EXPECT_EQ(category->CheckScore(dice), 0);
}

TEST(LowerCategoryTest, CheckScoreThreeOfKindTest3)
{
	int score = -1;

	Category* category = new ThreeOfKind();

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 4);
	dice.AddDice(sides, 5);
	dice.AddDice(sides, 5);
	dice.AddDice(sides, 5);
	dice.AddDice(sides, 6);

	EXPECT_EQ(category->CheckScore(dice), 25);
}

TEST(LowerCategoryTest, CheckScoreThreeOfKindTest4)
{
	int score = -1;

	Category* category = new ThreeOfKind();

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 6);

	EXPECT_EQ(category->CheckScore(dice), 10);
}

TEST(LowerCategoryTest, CheckScoreFourOfKindTest1)
{
	int score = -1;

	Category* category = new FourOfKind();

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 5);

	EXPECT_EQ(category->CheckScore(dice), 9);
}

TEST(LowerCategoryTest, CheckScoreFourOfKindTest2)
{
	int score = -1;

	Category* category = new FourOfKind();

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);

	EXPECT_EQ(category->CheckScore(dice), 5);
}

TEST(LowerCategoryTest, CheckScoreFourOfKindTest3)
{
	int score = -1;

	Category* category = new FourOfKind();

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 4);
	dice.AddDice(sides, 5);

	EXPECT_EQ(category->CheckScore(dice), 0);
}

TEST(LowerCategoryTest, CheckScoreFullHouseTest1)
{
	int score = -1;

	Category* category = new FullHouse();

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 5);
	dice.AddDice(sides, 5);

	EXPECT_EQ(category->CheckScore(dice), 25);
}

TEST(LowerCategoryTest, CheckScoreFullHouseTest2)
{
	int score = -1;

	Category* category = new FullHouse();

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 3);
	dice.AddDice(sides, 5);

	EXPECT_EQ(category->CheckScore(dice), 0);
}

TEST(LowerCategoryTest, CheckScoreFullHouseTest3)
{
	int score = -1;

	Category* category = new FullHouse();

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 3);
	dice.AddDice(sides, 3);
	dice.AddDice(sides, 5);

	EXPECT_EQ(category->CheckScore(dice), 0);
}

TEST(LowerCategoryTest, CheckScoreSmallStraightTest)
{
	int score = -1;

	Category* category = new SmallStraight();

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 2);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 2);
	dice.AddDice(sides, 3);
	dice.AddDice(sides, 4);

	EXPECT_EQ(category->CheckScore(dice), 30);
}

TEST(LowerCategoryTest, CheckScoreLargeStraightTest)
{
	int score = -1;

	Category* category = new LargeStraight();

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 2);
	dice.AddDice(sides, 3);
	dice.AddDice(sides, 4);
	dice.AddDice(sides, 5);

	EXPECT_EQ(category->CheckScore(dice), 40);
}

TEST(LowerCategoryTest, CheckScoreYahtzeeTest)
{
	int score = -1;

	Category* category = new Yahtzee();

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 6);
	dice.AddDice(sides, 6);
	dice.AddDice(sides, 6);
	dice.AddDice(sides, 6);
	dice.AddDice(sides, 6);

	EXPECT_EQ(category->CheckScore(dice), 50);
}

TEST(LowerCategoryTest, CheckScoreChanceTest)
{
	int score = -1;

	Category* category = new Chance();

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 4);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 6);
	dice.AddDice(sides, 2);
	dice.AddDice(sides, 6);

	EXPECT_EQ(category->CheckScore(dice), 19);
}