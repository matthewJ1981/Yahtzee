#pragma once

#include "../UpperCategories.h"
#include "../Dice.h"
#include <gtest/gtest.h>

TEST(UpperCategoryTest, ConstructorTest)
{
	int score = -1;

	Category* category = new Ones();

	EXPECT_EQ(category->Score(), score);
}

TEST(UpperCategoryTest, SetScoreTest)
{
	int score = 15;

	Category* category = new Ones();
	category->SetScore(score);

	EXPECT_EQ(category->Score(), score);
}

TEST(UpperCategoryTest, CheckScoreOnesTest)
{
	int score = -1;

	Category* category = new Ones();

	int sides = 6;

	Dice dice;
	dice.AddDice({ sides, 5 });
	dice.AddDice({ sides, 1 });
	dice.AddDice({ sides, 1 });
	dice.AddDice({ sides, 1 });
	dice.AddDice({ sides, 5 });

	EXPECT_EQ(category->CheckScore(dice), 3);
}

TEST(UpperCategoryTest, CheckScoreTwosTest)
{
	int score = -1;

	Category* category = new Twos();

	int sides = 6;

	Dice dice;
	dice.AddDice({ sides, 2 });
	dice.AddDice({ sides, 1 });
	dice.AddDice({ sides, 2 });
	dice.AddDice({ sides, 1 });
	dice.AddDice({ sides, 5 });
				 
	EXPECT_EQ(category->CheckScore(dice), 4);
}

TEST(UpperCategoryTest, CheckScoreThreesTest)
{
	int score = -1;

	Category* category = new Threes();

	int sides = 6;

	Dice dice;
	dice.AddDice({ sides, 3 });
	dice.AddDice({ sides, 1 });
	dice.AddDice({ sides, 2 });
	dice.AddDice({ sides, 6 });
	dice.AddDice({ sides, 4 });

	EXPECT_EQ(category->CheckScore(dice), 3);
}

TEST(UpperCategoryTest, CheckScoreFoursTest)
{
	int score = -1;

	Category* category = new Fours();

	int sides = 6;

	Dice dice;
	dice.AddDice({ sides, 4 });
	dice.AddDice({ sides, 4 });
	dice.AddDice({ sides, 4 });
	dice.AddDice({ sides, 4 });
	dice.AddDice({ sides, 4 });
				 
	EXPECT_EQ(category->CheckScore(dice), 20);
}

TEST(UpperCategoryTest, CheckScoreFivesTest)
{
	int score = -1;

	Category* category = new Fives();
	int sides = 6;

	Dice dice;
	dice.AddDice({ sides, 5 });
	dice.AddDice({ sides, 5 });
	dice.AddDice({ sides, 2 });
	dice.AddDice({ sides, 6 });
	dice.AddDice({ sides, 4 });

	EXPECT_EQ(category->CheckScore(dice), 10);
}

TEST(UpperCategoryTest, CheckScoreSixesTest)
{
	int score = -1;

	Category* category = new Sixes();

	int sides = 6;

	Dice dice;
	dice.AddDice({ sides, 3 });
	dice.AddDice({ sides, 1 });
	dice.AddDice({ sides, 2 });
	dice.AddDice({ sides, 6 });
	dice.AddDice({ sides, 4 });

	EXPECT_EQ(category->CheckScore(dice), 6);
}