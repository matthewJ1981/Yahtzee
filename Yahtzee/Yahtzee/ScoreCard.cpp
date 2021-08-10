#include "ScoreCard.h"

#include <vector>
#include <iterator>

#include "Category.h"
#include "categoryEnums.h"

std::vector<std::pair<std::string, int>> ScoreCard::CheckScore(const Dice& dice) const
{
	// Check scoring options
	std::vector<std::pair<std::string, int>> upperScoringCategories = upper.CheckScores(dice);
	std::vector<std::pair<std::string, int>> lowerScoringCategories = lower.CheckScores(dice, upperScoringCategories);

	std::vector<std::pair<std::string, int>> scoringCategories;
	std::move(upperScoringCategories.begin(), upperScoringCategories.end(), std::back_inserter(scoringCategories));
	std::move(lowerScoringCategories.begin(), lowerScoringCategories.end(), std::back_inserter(scoringCategories));

	return scoringCategories;
}

bool ScoreCard::SetScore(int index, int score)
{
	if (index < (int)ALL::THREEOFAKIND)
		return upper.SetScore(index, score);
	else
		return lower.SetScore(index - (int)ALL::THREEOFAKIND, score);
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
