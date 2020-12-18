#pragma once

#include "../UpperCategories.h"
#include "../Dice.h"
#include <gtest/gtest.h>

TEST(UpperCategoryTest, ConstructorTest)
{
	int score = -1;
	std::string name = "Ones";

	Category* category = new Ones(name);

	EXPECT_EQ(category->Score(), score);
	EXPECT_EQ(category->Name(), name);
}

TEST(UpperCategoryTest, SetScoreTest)
{
	int score = 15;
	std::string name = "Ones";

	Category* category = new Ones(name);
	category->SetScore(score);

	EXPECT_EQ(category->Score(), score);
	EXPECT_EQ(category->Name(), name);
}

TEST(UpperCategoryTest, CheckScoreOnesTest)
{
	int score = -1;
	std::string name = "Name";

	Category* category = new Ones(name);

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 5);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 5);

	EXPECT_EQ(category->CheckScore(dice), 3);
	EXPECT_EQ(category->Name(), name);
}

TEST(UpperCategoryTest, CheckScoreTwosTest)
{
	int score = -1;
	std::string name = "Name";

	Category* category = new Twos(name);

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 2);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 2);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 5);

	EXPECT_EQ(category->CheckScore(dice), 4);
	EXPECT_EQ(category->Name(), name);
}

TEST(UpperCategoryTest, CheckScoreThreesTest)
{
	int score = -1;
	std::string name = "Name";

	Category* category = new Threes(name);

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 3);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 2);
	dice.AddDice(sides, 6);
	dice.AddDice(sides, 4);

	EXPECT_EQ(category->CheckScore(dice), 3);
	EXPECT_EQ(category->Name(), name);
}

TEST(UpperCategoryTest, CheckScoreFoursTest)
{
	int score = -1;
	std::string name = "Name";

	Category* category = new Fours(name);

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 4);
	dice.AddDice(sides, 4);
	dice.AddDice(sides, 4);
	dice.AddDice(sides, 4);
	dice.AddDice(sides, 4);

	EXPECT_EQ(category->CheckScore(dice), 20);
	EXPECT_EQ(category->Name(), name);
}

TEST(UpperCategoryTest, CheckScoreFivesTest)
{
	int score = -1;
	std::string name = "Name";

	Category* category = new Fives(name);

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 5);
	dice.AddDice(sides, 5);
	dice.AddDice(sides, 2);
	dice.AddDice(sides, 6);
	dice.AddDice(sides, 4);

	EXPECT_EQ(category->CheckScore(dice), 10);
	EXPECT_EQ(category->Name(), name);
}

TEST(UpperCategoryTest, CheckScoreSixesTest)
{
	int score = -1;
	std::string name = "name";

	Category* category = new Sixes(name);

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 3);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 2);
	dice.AddDice(sides, 6);
	dice.AddDice(sides, 4);

	EXPECT_EQ(category->CheckScore(dice), 6);
	EXPECT_EQ(category->Name(), name);
}