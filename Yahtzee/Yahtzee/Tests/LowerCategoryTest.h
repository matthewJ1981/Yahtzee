#pragma once

#include "../LowerCategories.h"
#include "../Dice.h"
#include <gtest/gtest.h>

TEST(LowerCategoryTest, ConstructorTest)
{
	int score = -1;
	std::string name = "Three Of A Kind";

	Category* category = new ThreeOfKind(name);

	EXPECT_EQ(category->Score(), score);
	EXPECT_EQ(category->Name(), name);
}

TEST(LowerCategoryTest, SetScoreTest)
{
	int score = 15;
	std::string name = "Three Of A Kind";

	Category* category = new ThreeOfKind(name);
	category->SetScore(score);

	EXPECT_EQ(category->Score(), score);
	EXPECT_EQ(category->Name(), name);
}

TEST(LowerCategoryTest, CheckScoreThreeOfKindTest)
{
	int score = -1;
	std::string name = "Name";

	Category* category = new ThreeOfKind(name);

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 5);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 5);

	EXPECT_EQ(category->CheckScore(dice), 13);
	EXPECT_EQ(category->Name(), name);
}

TEST(LowerCategoryTest, CheckScoreFourOffKindTest)
{
	int score = -1;
	std::string name = "Name";

	Category* category = new FourOfKind(name);

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 5);

	EXPECT_EQ(category->CheckScore(dice), 9);
	EXPECT_EQ(category->Name(), name);
}

TEST(LowerCategoryTest, CheckScoreFullHouseTest)
{
	int score = -1;
	std::string name = "Name";

	Category* category = new FullHouse(name);

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 5);
	dice.AddDice(sides, 5);

	EXPECT_EQ(category->CheckScore(dice), 25);
	EXPECT_EQ(category->Name(), name);
}

TEST(LowerCategoryTest, CheckScoreSmallStraightTest)
{
	int score = -1;
	std::string name = "Name";

	Category* category = new SmallStraight(name);

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 2);
	dice.AddDice(sides, 3);
	dice.AddDice(sides, 4);
	dice.AddDice(sides, 6);

	EXPECT_EQ(category->CheckScore(dice), 30);
	EXPECT_EQ(category->Name(), name);
}

TEST(LowerCategoryTest, CheckScoreLargeStraightTest)
{
	int score = -1;
	std::string name = "Name";

	Category* category = new LargeStraight(name);

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 2);
	dice.AddDice(sides, 3);
	dice.AddDice(sides, 4);
	dice.AddDice(sides, 5);

	EXPECT_EQ(category->CheckScore(dice), 40);
	EXPECT_EQ(category->Name(), name);
}

TEST(LowerCategoryTest, CheckScoreYahtzeeTest)
{
	int score = -1;
	std::string name = "Name";

	Category* category = new Yahtzee(name);

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 6);
	dice.AddDice(sides, 6);
	dice.AddDice(sides, 6);
	dice.AddDice(sides, 6);
	dice.AddDice(sides, 6);

	EXPECT_EQ(category->CheckScore(dice), 50);
	EXPECT_EQ(category->Name(), name);
}

TEST(LowerCategoryTest, CheckScoreChanceTest)
{
	int score = -1;
	std::string name = "Name";

	Category* category = new Chance(name);

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 4);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 6);
	dice.AddDice(sides, 2);
	dice.AddDice(sides, 6);

	EXPECT_EQ(category->CheckScore(dice), 19);
	EXPECT_EQ(category->Name(), name);
}