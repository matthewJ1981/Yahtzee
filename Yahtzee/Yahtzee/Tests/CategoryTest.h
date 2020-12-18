#pragma once

#include "../UpperCategories.h"
#include "../Dice.h"
#include <gtest/gtest.h>

TEST(CategoryTest, ConstructorTest)
{
	int score = -1;
	std::string name = "Ones";

	Category* ones = new Ones("Ones");

	EXPECT_EQ(ones->Score(), score);
	EXPECT_EQ(ones->Name(), name);
}

TEST(CategoryTest, SetScoreTest)
{
	int score = 15;
	std::string name = "Ones";

	Category* ones = new Ones("Ones");
	ones->SetScore(score);

	EXPECT_EQ(ones->Score(), score);
	EXPECT_EQ(ones->Name(), name);
}

TEST(CategoryTest, CheckScoreTest)
{
	int score = -1;
	std::string name = "Ones";

	Category* ones = new Ones("Ones");

	int sides = 6;

	Dice dice;
	dice.AddDice(sides, 5);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 1);
	dice.AddDice(sides, 5);

	EXPECT_EQ(ones->CheckScore(dice), 3);
	EXPECT_EQ(ones->Name(), name);
}

