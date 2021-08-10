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

void ScoreCard::SetScore(int index, int score)
{
	if (index < (int)ALL::THREEOFAKIND)
		upper.SetScore(index, score);
	else
		lower.SetScore(index - (int)ALL::THREEOFAKIND, score);
}

std::vector<int> ScoreCard::GetScores() const
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
