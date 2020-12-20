#pragma once

#include "../ScoreCard.h"
#include <gtest/gtest.h>

TEST(IntegrationTest, TestOne)
{
	ScoreCard scoreCard;
	Dice dice;

	dice.AddDice(6, 6);
	dice.AddDice(6, 6);
	dice.AddDice(6, 6);
	dice.AddDice(6, 6);
	dice.AddDice(6, 6);

	std::vector<std::pair<int, std::string>> scores = scoreCard.CheckScore(dice);

	for (int i = 0; i < dice.Size(); ++i)
	{
		std::cout << dice[i].Value();
		if (i < dice.Size() - 1)
			std::cout << ", ";
	}

	std::cout << "\n";

	for (size_t i = 0; i < scores.size(); ++i)
	{
		std::cout << scores[i].second << ": " << scores[i].first << "\n";
	}
	std::cout << "\n";

	scoreCard.SetScore(ScoreCard::YAHTZEE, 50);

	scores = scoreCard.GetScores();

	std::cout << "\n";

	for (size_t i = 0; i < scores.size(); ++i)
	{
		std::cout << scores[i].second << ": " << scores[i].first << "\n";
	}
	std::cout << "\n";
}