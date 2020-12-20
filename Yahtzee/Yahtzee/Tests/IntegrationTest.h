#pragma once

#include "../ScoreCard.h"
#include <gtest/gtest.h>
#include "../categoryEnums.h"

TEST(IntegrationTest, TestOne)
{
	ScoreCard scoreCard;
	Dice dice;

	dice.AddDice(6, 6);
	dice.AddDice(6, 6);
	dice.AddDice(6, 6);
	dice.AddDice(6, 6);
	dice.AddDice(6, 6);

	std::vector<int> scores = scoreCard.CheckScore(dice);

	for (int i = 0; i < dice.Size(); ++i)
	{
		std::cout << dice[i].Value();
		if (i < dice.Size() - 1)
			std::cout << ", ";
	}

	std::cout << "\n";

	for (size_t i = 0; i < scores.size(); ++i)
	{
		std::cout << scoreCard.EnumToString((int)i) << ": " << scores[i] << "\n";
	}
	std::cout << "\n";

	scoreCard.SetScore((int)ALL::YAHTZEE, dice);

	scores = scoreCard.GetScores();

	std::cout << "\n";

	for (size_t i = 0; i < scores.size(); ++i)
	{
		std::cout << scoreCard.EnumToString((int)i) << ": " << scores[i] << "\n";
	}
	std::cout << "\n";
}