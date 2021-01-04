#include "ScoreCard.h"

#include <vector>
#include <iterator>

#include "Category.h"
#include "categoryEnums.h"

std::vector<int> ScoreCard::CheckScore(const Dice& dice) const
{
	// Check scoring options
	std::vector<int> upperScoringCategories = upper.CheckScores(dice);
	std::vector<int> lowerScoringCategories = lower.CheckScores(dice, upperScoringCategories);

	std::vector<int> scoringCategories;
	std::move(upperScoringCategories.begin(), upperScoringCategories.end(), std::back_inserter(scoringCategories));
	std::move(lowerScoringCategories.begin(), lowerScoringCategories.end(), std::back_inserter(scoringCategories));

	return scoringCategories;
}

//TEST *************************************
//std::vector<int> ScoreCard::CheckScore(const Dice& dice) const
//{
//	std::vector<int> scoringCategories(13, 0);
//	int values[6] = { 0 };
//
//	//get count of each number
//	for (Die d : dice)
//		values[d.Value() - 1]++;
//
//	for(int i = int(UPPER::ONES); i <= int(UPPER::SIXES); ++i )
//		scoringCategories[int(i)] = values[i] * (i + 1);
//
//	int score = 0;
//	bool threeOfKind = false;
//	bool fourOfKind = false;
//	bool yahtzee = false;
//
//	for (int i = 0; i < 6; ++i)
//	{
//		score += values[i] * (i + 1);
//
//		if (values[i] >= 3)
//			threeOfKind = true;
//		if (values[i] >= 4)
//			fourOfKind = true;
//		if (values[i] == 5)
//			yahtzee = true;
//	}
//
//	int numConsec = 0;
//	int prev = -1;
//	int current = -1;
//	for (int i = 1; i < 6; ++i)
//	{
//		prev = values[i - 1];
//		current = values[i];
//		if (prev > 0 && current > 0)
//			++numConsec;
//	}
//
//	int indexTwo = -1;
//	bool two = false;
//	bool three = false;
//	for (int i = 0; i < 6; ++i)
//	{
//		if (values[i] > 1 && two == false)
//		{
//			two = true;
//			indexTwo = i;
//		}
//		if (values[i] > 2 && indexTwo != i)
//		{
//			three = true;
//		}
//	}
//
//	if (numConsec > 3)
//		scoringCategories[int(ALL::SMALLSTRAIGHT)] = 30;
//	if (numConsec > 4)
//		scoringCategories[int(ALL::LARGESTRAIGHT)]  = 40;
//	if (threeOfKind)
//		scoringCategories[int(ALL::THREEOFAKIND)] = score;
//	if (fourOfKind)
//		scoringCategories[int(ALL::FOUROFAKIND)] = score;
//	if (yahtzee)
//		scoringCategories[int(ALL::YAHTZEE)] = score;
//	if (two && three)
//		scoringCategories[int(ALL::FULLHOUSE)] = 25;
//
//	scoringCategories[int(ALL::CHANCE)] = score;
//
//
//
//	return scoringCategories;
//}


void ScoreCard::SetScore(int index, const Dice& dice)
{
	std::vector<int> scoringCategories = CheckScore(dice);

	bool test = lower.BonusEligibile();
	if (scoringCategories[(int)ALL::YAHTZEE] == 50 && lower.BonusEligibile())
		lower.IncrementBonus();

	if (index < 6)
		upper.SetScore(index, scoringCategories[index]);
	else
		lower.SetScore(index - 6, scoringCategories[index]);

}

std::vector<int> ScoreCard::GetScores()
{
	std::vector<int> upperScores = upper.GetScores();
	std::vector<int> lowerScores = lower.GetScores();

	std::vector<int> scores;
	std::move(upperScores.begin(), upperScores.end(), std::back_inserter(scores));
	std::move(lowerScores.begin(), lowerScores.end(), std::back_inserter(scores));

	return scores;
}

int ScoreCard::Tally()
{
	return upper.Tally() + lower.Tally();
}
